#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("day 3");
	ofEnableAlphaBlending();
	ofEnableDepthTest();
	for (int i = 0; i < 500; i++) {
		this->nodes.push_back(shared_ptr<Node>(new Node()));
	}
	//this->cam.setDistance(ofGetWidth() * 1.5);
	//this->cam.setTarget(ofVec3f(ofGetWidth(), ofGetHeight(), 0));
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < this->nodes.size(); i++) {
		this->nodes[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	//this->cam.begin();
	for (int i = 0; i < this->nodes.size(); i++) {
		this->nodes[i]->draw(this->nodes);
	}
	//this->cam.end();
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
	string now = ofGetTimestampString("%Y%m%d%H%M%S");
	this->img.grabScreen(0, 0, 1000, 1000);
	this->img.saveImage("of" + now + ".jpg");
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
