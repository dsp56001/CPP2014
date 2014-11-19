#include "ofApp.h"

const int SPEED = 200;

//--------------------------------------------------------------
void ofApp::setup(){
	m_pos.set(100, 100);  //PacMan position
	m_dir.set(0, 0);	  //PacMan Direction
	m_elapsedGameTime = 0.0f;	//counter for elapsedGameTime

	//framerate
	//ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
	m_elapsedGameTime = ofGetLastFrameTime();
	//Move not corrected
	//m_pos += m_dir + SPEED; //200 px per frame
	//Move corrected by elapsed time
	m_pos += m_dir * (m_elapsedGameTime * SPEED); //200 px per frame

	//update direction
	m_dir += m_keyDir.normalize();
	m_dir.normalize();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Draw Pacman
	ofCircle(m_pos.x, m_pos.y, 60);

	//draw framerate
	ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 10, 15);

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == 'w')
	{
		m_keyDir.y--;
	}
	if (key == 's')
	{
		m_keyDir.y++;
	}
	if (key == 'a')
	{
		m_keyDir.x--;
	}
	if (key == 'd')
	{
		m_keyDir.x++;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'w')
	{
		m_keyDir.y = 0;
	}
	if (key == 's')
	{
		m_keyDir.y = 0;
	}
	if (key == 'a')
	{
		m_keyDir.x = 0;
	}
	if (key == 'd')
	{
		m_keyDir.x = 0;
	}
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
