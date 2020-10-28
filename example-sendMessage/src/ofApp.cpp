#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sender.setup(SENDERHOST, SENDERPORT);

}

//--------------------------------------------------------------
void ofApp::update(){

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
    
    ofxOscMessage newMessage;
    newMessage.setAddress("/end");
    newMessage.addFloatArg(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.f, 100.f, true));
    newMessage.addFloatArg(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0.f, 100.f, true));
    
    sender.sendMessage(newMessage, false);
    
    

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
