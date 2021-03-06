#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myMachine.setup();
    myMachine.printAvailablePorts();
    myMachine.setPort(0);
    myMachine.connect();
}

//--------------------------------------------------------------
void ofApp::update(){
    myMachine.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1')
    {
        float y1 = ofRandom(0, 100);
        float x2 = ofRandom(0, 100);
        myMachine.drawLine(0, y1, x2, 0);
    } else if (key == '2') {
        float x1 = ofRandom(0, 100);
        float y1 = ofRandom(0, 100);
        float x2 = ofRandom(0, 100);
        float y2 = ofRandom(0, 100);
        float x3 = ofRandom(0, 100);
        float y3 = ofRandom(0, 100);
        
    } else if (key == '3') {
        float randomX = ofRandom(0, 100);
        float randomY = ofRandom(0, 100);
        float randomWidth = ofRandom(10, 50);
        float randomHeight = ofRandom(10, 50);
        myMachine.drawRectangle(randomX, randomY, randomWidth, randomHeight);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    myMachine.keyboardControl(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
