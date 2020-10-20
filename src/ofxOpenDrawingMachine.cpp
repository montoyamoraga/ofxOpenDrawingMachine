#include "ofxOpenDrawingMachine.h"

ofxOpenDrawingMachine::ofxOpenDrawingMachine(int newBaudRate, int newServoUp, int newServoDown, int newFeedRate) {
	setup(newBaudRate, newServoUp, newServoDown, newFeedRate);
}

void ofxOpenDrawingMachine::setup(int newBaudRate, int newServoUp, int newServoDown, int newFeedRate) {
    baudRate = newBaudRate;
    servoUp = newServoUp;
    servoDown = newServoDown;
    feedRate = newFeedRate;
    
    availablePorts = getAvailablePorts();
}

std::vector<std::string> ofxOpenDrawingMachine::getAvailablePorts() {
    std::vector<std::string> ports;
    auto devices = serial.getDeviceList();
    for (auto& device: devices) {
        ports.push_back(device.getDevicePath());
    }
    return ports;
}

void ofxOpenDrawingMachine::printAvailablePorts() {
    for (int i = 0; i < availablePorts.size(); i++) {
        std::cout << std::to_string(i) << ": " << availablePorts[i] << "\n";
    }
}

void ofxOpenDrawingMachine::setPort(int newPortIndex) {
    portIndex = newPortIndex;
    portName = availablePorts[newPortIndex];
}

void ofxOpenDrawingMachine::connect() {
    serial.setup(portName, baudRate);
}

bool ofxOpenDrawingMachine::isConnected() {
    return false;
}

void ofxOpenDrawingMachine::sendSerialMessage(std::string message) {
  // create placeHolder char array
  unsigned char placeHolder[message.length()];

  // copy the contents of the original string message
  for (int i = 0; i < sizeof(placeHolder); i++) {
    placeHolder[i] = message[i];
  }
  serial.writeBytes(&placeHolder[0], sizeof(placeHolder));
}

void ofxOpenDrawingMachine::setServoDown(int newServoDown) {
    servoDown = newServoDown;
}

void ofxOpenDrawingMachine::setOrigin() {
    std::string str = "G10 P0 L20 X0 Y0 Z0\n";
    currentInstructions.push_back(str);
}

void ofxOpenDrawingMachine::instrumentUp(){
    std::string str = "M03 S" + std::to_string(servoUp) + "\n";
    currentInstructions.push_back(str);
}

void ofxOpenDrawingMachine::instrumentDown() {
    std::string str = "M03 S" + std::to_string(servoDown) + "\n";
    currentInstructions.push_back(str);
}

void ofxOpenDrawingMachine::instrumentMoveTo(float newX, float newY) {
    std::string str = "G00 X" + std::to_string(newX) + " Y" + std::to_string(newY) + "\n";
    currentInstructions.push_back(str);
}

void ofxOpenDrawingMachine::instrumentLineTo(float newX, float newY) {
    std::string str = "G01 X " + std::to_string(newX) + " Y " + std::to_string(newY) +  " F " + std::to_string(feedRate) + "\n";
    currentInstructions.push_back(str);
}

void ofxOpenDrawingMachine::instrumentArcTo(float newX, float newY, float arcRadius, bool isClockwise) {
    std::string str = "";
    if (isClockwise) {
        str = "G02 X " + std::to_string(newX) + " Y " + std::to_string(newY) + " R " + std::to_string(arcRadius) + " F " + std::to_string(feedRate) + "\n";
    }
    else {
        str = "G03 X " + std::to_string(newX) + " Y " + std::to_string(newY) + " R " + std::to_string(arcRadius) + " F " + std::to_string(feedRate) + "\n";
    }
    currentInstructions.push_back(str);
}
          
void ofxOpenDrawingMachine::drawLine(float startX, float startY, float endX, float endY) {
    instrumentUp();
    instrumentMoveTo(startX, startY);
    instrumentDown();
    instrumentLineTo(endX, endY);
    instrumentUp();
}

void ofxOpenDrawingMachine::drawRectangle(float posX, float posY, float width, float height) {
    instrumentUp();
    // move to upper left corner
    instrumentMoveTo(posX - width/2, posY - height/2);
    instrumentDown();
    // draw the rectangle clockwise
    instrumentLineTo(posX + width/2, posY - height/2);
    instrumentLineTo(posX + width/2, posY + height/2);
    instrumentLineTo(posX - width/2, posY + height/2);
    instrumentLineTo(posX - width/2, posY - height/2);
    instrumentUp();
}

void ofxOpenDrawingMachine::drawArc(float startX, float startY, float endX, float endY, float arcRadius, bool isClockwise) {
    instrumentUp();
    instrumentMoveTo(startX, startY);
    instrumentDown();
    instrumentArcTo(endX, endY, arcRadius, isClockwise);
    instrumentUp();
}

void ofxOpenDrawingMachine::drawCircle(float posX, float posY, float radius) {
    drawArc(posX - radius, posY         , posX         , posY + radius, radius, true);
    drawArc(posX         , posY + radius, posX + radius, posY         , radius, true);
    drawArc(posX + radius, posY         , posX         , posY - radius, radius, true);
    drawArc(posX         , posY - radius, posX - radius, posY         , radius, true);
}

void ofxOpenDrawingMachine::keyboardControl(int key) {
    if (key == ' ') {
        setOrigin();
    }
    else if (key == 'd') {
        instrumentDown();
    }
    else if (key == 'u') {
        instrumentUp();
    }
}

void ofxOpenDrawingMachine::update() {
    
    if (isReadyForNext && currentInstructions.size()) {
        sendSerialMessage(currentInstructions.front());
        std::cout << "sending: " << std::endl << currentInstructions.front() << std::endl;
        currentInstructions.pop_front();
        isReadyForNext = false;
    }
    if (!isReadyForNext && serial.available()) {
        
        while (serial.available() > 0) {
            
            char newByte = (char)serial.readByte();
            
            if (newByte == '\n' || newByte == '\r') {
                
                if (readBuffer != "") {
                    
                    if (readBuffer == "ok") {
                        isReadyForNext = true;
                        std::cout << "i got an ok" << std::endl;
                    }
//                    else if (readBuffer == "placeholder") {
//                        here we can add more options to respond to
//                    }
                    readBuffer = "";
                }
            }
            else {
                readBuffer = readBuffer + newByte;
            }
        }
    }
}
