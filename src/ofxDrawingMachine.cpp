#include "ofxDrawingMachine.h"
using namespace std;


ofxDrawingMachine::ofxDrawingMachine(int _penUpServoVal, int _penDownServoVal, int _feedRate) {
	setup(_penUpServoVal, _penDownServoVal, _feedRate);
}

void ofxDrawingMachine::setup(int _penUpServoVal, int _penDownServoVal, int _feedRate) {
	
  penUpServoVal = _penUpServoVal;
  penDownServoVal = _penDownServoVal;
  feedRate = _feedRate;
	
  serial.listDevices();

  vector <ofSerialDeviceInfo> serialDevices = serial.getDeviceList();

  int baudRate = 115200;

  serial.setup(0, baudRate);
	
}

void ofxDrawingMachine::instrumentUp(){
    string str = "M03 S" + to_string(penUpServoVal) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxDrawingMachine::instrumentDown() {
    string str = "M03 S" + to_string(penDownServoVal) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxDrawingMachine::instrumentMoveTo(float newX, float newY) {
    string str = "G00 X" + to_string(x) + " Y" + to_string(y) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxDrawingMachine::instrumentDrawTo(float newX, float newY) {
    string str = "G01 X " + to_string(x) + " Y " + to_string(y) +  " F " + to_string(feedRate) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
        buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}
          
void ofxDrawingMachine::drawLine(float startX, float startY, float endX, float endY) {
    tipUp();
    tipMoveTo(x1, y1);
    tipDown();
    tipDrawTo(x2, y2);
    tipUp();
}
