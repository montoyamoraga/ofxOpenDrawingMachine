#pragma ofxDrawingMachine

#include "ofSerial.h"

class ofxDrawingMachine {
  public:
    
    int penUpServoVal; 
    int penDownServoVal;
    int feedRate;

    ofxDrawingMachine(int _penUpServoVal = 90, int _penDownServoVal = 30, int _feedRate = 4000);

	
    ofSerial serial;

	///\brief this is the setup.....
	///\param _penUpServoVal  //range 0-90 default: 90
	///\param _penDownServoVal  //range 0-90 default: 30
	///\param _feedRate  //used for G1 G2 G3 default: 4000
	
    void setup(int _penUpServoVal = 90, int _penDownServoVal = 30, int _feedRate = 4000);

    void tipDown();
    void tipUp();

    // g00 rapid positioning
    void tipMoveXY(float x, float y);

    // g01 linear interpolation
    void tipLinearInterpolation(float x, float y);
          
    void drawLine(float x1, float y1, float x2, float y2);

};
