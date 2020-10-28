#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    receiver.setup(RECEIVERPORT);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    while(receiver.hasWaitingMessages()) {
        ofxOscMessage newMessage;
        receiver.getNextMessage(&newMessage);
        
        if (newMessage.getAddress() == "/end") {
            receiverX = newMessage.getArgAsFloat(0);
            receiverY = newMessage.getArgAsFloat(1);
        }
      
        std::cout << receiverX << ", " << receiverY << endl;
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
