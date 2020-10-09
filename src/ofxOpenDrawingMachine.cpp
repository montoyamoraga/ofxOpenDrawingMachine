#include "ofxOpenDrawingMachine.h"

ofxOpenDrawingMachine::ofxOpenDrawingMachine(int newServoUp, int newServoDown, int newFeedRate) {
	setup(newServoUp, newServoDown, newFeedRate);
}

void ofxOpenDrawingMachine::setup(int newServoUp, int newServoDown, int newFeedRate) {
	
  servoUp = newServoUp;
  servoDown = newServoDown;
  feedRate = newFeedRate;

  serial.listDevices();

  std::vector <ofSerialDeviceInfo> serialDevices = serial.getDeviceList();

  int baudRate = 115200;

  serial.setup(0, baudRate);
	
}

void ofxOpenDrawingMachine::instrumentUp(){
    std::string str = "M03 S" + std::to_string(servoUp) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxOpenDrawingMachine::instrumentDown() {
    std::string str = "M03 S" + std::to_string(servoDown) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxOpenDrawingMachine::instrumentMoveTo(float newX, float newY) {
    std::string str = "G00 X" + std::to_string(newX) + " Y" + std::to_string(newY) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxOpenDrawingMachine::instrumentLineTo(float newX, float newY) {
    std::string str = "G01 X " + std::to_string(newX) + " Y " + std::to_string(newY) +  " F " + std::to_string(feedRate) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
        buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxOpenDrawingMachine::instrumentArcTo(float newX, float newY, float arcRadius, bool isClockwise) {
    std::string str = "";
    if (isClockwise) {
        str = "G02 X " + std::to_string(newX) + " Y " + std::to_string(newY) + " R " + std::to_string(arcRadius) + " F " + std::to_string(feedRate) + "\n";
    }
    else {
        str = "G03 X " + std::to_string(newX) + " Y " + std::to_string(newY) + " R " + std::to_string(arcRadius) + " F " + std::to_string(feedRate) + "\n";
    }
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}
          
void ofxOpenDrawingMachine::drawLine(float startX, float startY, float endX, float endY) {
    instrumentUp();
    instrumentMoveTo(startX, startY);
    instrumentDown();
    instrumentLineTo(endX, endY);
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
    if (key == 'd') {
        instrumentDown();
    }
    else if (key == 'u') {
        instrumentUp();
    }
}
