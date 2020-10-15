#pragma ofxOpenDrawingMachine

#include "ofSerial.h"

// import OpenSoundControl addon
#include "ofxOsc.h"

class ofxOpenDrawingMachine {
  public:
    
    int servoUp;
    int servoDown;
    int feedRate;
    
    ofSerial serial;
    int baudRate;
    std::string portName;
    int portIndex;
    std::vector<std::string> availablePorts;

    ofxOpenDrawingMachine(int newBaudRate = 115200, int newServoUp = 90, int newServoDown = 30, int newFeedRate = 4000);
    
	///\brief setup() sets the initial conditions
    ///\param newBaudRate // baudRate for serial connection, default 115200
	///\param _penUpServoVal  // range 0-90 default: 90
	///\param _penDownServoVal  / /range 0-90 default: 30
	///\param _feedRate  // used for G1 G2 G3 default: 4000
    void setup(int newBaudRate = 115200, int newServoUp = 90, int newServoDown = 30, int newFeedRate = 4000);
    
    std::vector<std::string> getAvailablePorts();
    void printAvailablePorts();
    void setPort(int newPortIndex);
    void connect();
    
    bool isConnected();
    
    ///\brief moves the  instrument downwards to the drawing surface
    void instrumentDown();
    
    ///\brief moves the  instrument upwards away from the drawing surface
    void instrumentUp();

    ///\brief moves the instrument to a new XY position
    ///\param newX // new x position
    ///\param newY // new y position
    void instrumentMoveTo(float newX, float newY);

    ///\brief uses the instrument to draw a line to new position
    ///\param newX // new x position
    ///\param newY // new y position
    void instrumentLineTo(float newX, float newY);
    
    ///\brief uses the instrument to draw an arc to new position, using radius and direction
    ///\param newX // new x position
    ///\param newX // new y position
    ///\param arcRadius // arc radius
    ///\param isClockwise // arc direction, true for clockwise, false is counterclockwise
    void instrumentArcTo(float newX, float newY, float arcRadius, bool isClockwise);
    
    ///\brief draws line between start point and end point
    ///\param startX // x position of starting point
    ///\param startY // y position of starting point
    ///\param endX // x position of ending point
    ///\param endY // y position of ending point
    void drawLine(float startX, float startY, float endX, float endY);
    
    ///\brief draws arc between start point and end point
    ///\param startX // x position of starting point
    ///\param startY // y position of starting point
    ///\param endX // x position of ending point
    ///\param endY // y position of ending point
    ///\param arcRadius // arc radius
    ///\param isClockwise // arc direction, true for clockwise, false is counterclockwise
    void drawArc(float startX, float startY, float endX, float endY, float arcRadius, bool isClockwise);
    
    ///\brief draws circle around a point, using radius
    void drawCircle(float posX, float posY, float radius);
    
    ///\brief controls the machine with key presses
    ///\param key // value of key pressed
    void keyboardControl(int key);

};
