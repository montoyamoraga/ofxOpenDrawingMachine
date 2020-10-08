#pragma ofxDrawingMachine

#include "ofSerial.h"

class ofxDrawingMachine {
  public:
    
    int penUpServoVal; 
    int penDownServoVal;
    int feedRate;

    ofxDrawingMachine(int newPenUpServoVal, int newPenDownServoVal, int newFeedRate);

    ofSerial serial;

    void setup();

    void tipDown();
    void tipUp();

    // g00 rapid positioning
    void tipMoveXY(float x, float y);

    // g01 linear interpolation
    void tipLinearInterpolation(float x, float y);
          
    void drawLine(float x1, float y1, float x2, float y2);

};
