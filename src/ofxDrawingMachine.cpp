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

void ofxDrawingMachine::tipUp(){
    string str = "M03 S" + to_string(penUpServoVal) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxDrawingMachine::tipDown() {
    string str = "M03 S" + to_string(penDownServoVal) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxDrawingMachine::tipMoveXY(float x, float y) {
    string str = "G00 X" + to_string(x) + " Y" + to_string(y) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
            buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}

void ofxDrawingMachine::tipLinearInterpolation(float x, float y) {
    string str = "G01 X " + to_string(x) + " Y " + to_string(y) +  " F " + to_string(feedRate) + "\n";
    unsigned char buf[str.length()];
    for(int i = 0; i < sizeof(buf); i++){
        buf[i] = str[i];
    }
    serial.writeBytes(&buf[0], sizeof(buf));
}
          
void ofxDrawingMachine::drawLine(float x1, float y1, float x2, float y2) {
    tipUp();
    tipMoveXY(x1, y1);
    tipDown();
    tipLinearInterpolation(x2, y2);
    tipUp();
}
