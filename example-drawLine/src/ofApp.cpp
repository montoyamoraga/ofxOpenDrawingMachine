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
    if(key == ' ')
    {
        float y1 = ofRandom(0, 100);
        float x2 = ofRandom(0, 100);
        myMachine.drawLine(0, y1, x2, 0);
        ofDrawLine(0, y1, x2, 0);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
