#include "ofApp.h"

const int MAX_SPEED = 200;
int speed = 200;
int mouthW, mouthH;

ofVec2f keyDir;

//--------------------------------------------------------------
void ofApp::setup(){
	m_pos.set(100, 100);  //PacMan position
	m_dir.set(0, 0);	  //PacMan Direction
	m_elapsedGameTime = 0.0f;	//counter for elapsedGameTime

	mouthH = 60; //width
	mouthW = 30; //
	//framerate
	//ofSetFrameRate(60);	
}

//--------------------------------------------------------------
void ofApp::update(){
	m_elapsedGameTime = ofGetLastFrameTime();
	//Move not corrected
	//m_pos += m_dir + speed; //200 px per frame
	//Move corrected by elapsed time
	m_pos += m_dir * (m_elapsedGameTime * speed); //200 px per frame

	//Update direction based on key input
	if(m_keyDir != ofVec2f::zero())
	{
		m_dir += m_keyDir.normalize();
		m_dir.normalize();
		speed = MAX_SPEED;
		mouthW = sin((m_pos.x/10) + (m_pos.y/10)) * 30; //open and close mouth cheap trick
	}
	else
	{
		//stop if no key pressed
		speed = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Draw Pacman
	
	
	
	//ofRotate(0);
	ofSetColor(ofColor::yellow);
	//circle for pacman
	ofCircle(m_pos.x, m_pos.y, mouthH);
	
	//mouth for pacman
	ofPushMatrix();
		
		ofSetColor(ofColor::black);
		//actual triablge
		//ofTriangle(m_pos.x, m_pos.y, m_pos.x - (w / 2), m_pos.y + (h), m_pos.x + (w / 2), m_pos.y + (h));
		
		//translated rotated triangle
		ofTranslate(m_pos.x, m_pos.y, 0.0);
		ofVec2f invY = m_dir * ofVec2f(1,-1);
		float angle = invY.angle(ofVec2f(0,1)); //invert Y
		ofRotate(angle , 0.0, 0.0, 1.0);
		ofTriangle(0.0, 0.0, -1 * (mouthW / 2), -mouthH, (mouthW / 2), -mouthH);
		
	ofPopMatrix();

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
