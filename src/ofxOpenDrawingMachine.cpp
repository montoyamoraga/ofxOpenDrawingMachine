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

void ofxOpenDrawingMachine::instrumentDrawTo(float newX, float newY) {
    std::string str = "G01 X " + std::to_string(newX) + " Y " + std::to_string(newY) +  " F " + std::to_string(feedRate) + "\n";
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
    instrumentDrawTo(endX, endY);
    instrumentUp();
}
