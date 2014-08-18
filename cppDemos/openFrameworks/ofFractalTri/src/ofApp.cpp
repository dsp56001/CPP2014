#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofNoFill(); 
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	DrawFractal(500.0f,25.0f, 700.0f,700.0f);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


void ofApp::DrawFractal(float x, float y, float w, float h)
{
	ofTriangle(x, y, x - (w/2), y + (h), x + (w/2), y + (h)); 
	float halfH = h/2;
	float halfW = w/2;
	if( x < 5 || h < 5) return; //exit condition
	DrawFractal(x, y, halfW, halfH); //top
	DrawFractal(x - halfW/2, y+ halfH, halfW, halfH); //left
	DrawFractal(x + halfW/2, y+ halfH, halfW, halfH); //right
	
}