#pragma ofxOpenDrawingMachine

#include "ofSerial.h"

// import OpenSoundControl addon
#include "ofxOsc.h"

class ofxOpenDrawingMachine {
  public:
    
    int servoUp;
    int servoDown;
    int feedRate;

    ofxOpenDrawingMachine(int newServoUp = 90, int newServoDown = 30, int newFeedRate = 4000);
	
    ofSerial serial;

	///\brief setup() sets the initial conditions
	///\param _penUpServoVal  //range 0-90 default: 90
	///\param _penDownServoVal  //range 0-90 default: 30
	///\param _feedRate  //used for G1 G2 G3 default: 4000
    void setup(int _penUpServoVal = 90, int _penDownServoVal = 30, int _feedRate = 4000);
    
    ///\brief moves the  instrument downwards to the drawing surface
    void instrumentDown();
    
    ///\brief moves the  instrument upwards away from the drawing surface
    void instrumentUp();

    ///\brief moves the instrument to a new XY position
    ///\param newX // new x position
    ///\param newY // new y position
    void instrumentMoveTo(float newX, float newY);

    ///\brief uses the instrument to draw from current position to new XY position
    ///\param newX // new x position
    ///\param newY // new y position
    void instrumentDrawTo(float newX, float newY);
    
    ///\brief draws line between start point and end point
    ///\param startX // x position of starting point
    ///\param startY // y position of starting point
    ///\param endX // x position of ending point
    ///\param endY // y position of ending point
    void drawLine(float startX, float startY, float endX, float endY);
    
    ///\brief controls the machine with key presses
    void keyboardControl(int key);

};
