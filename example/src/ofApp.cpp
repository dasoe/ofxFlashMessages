#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
	flashMessages.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawBitmapString("flash messages appear on top of each other and vanish after some time.", 10, 20);
	ofDrawBitmapString("For triggering flash messages please press a, s, d, f, g, h", 10, 35);

	flashMessages.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'a':
		flashMessages.add("standard message with default settings");
		break;
	case 's':
		// here we have to add the time explicitly as a float or double. 
		// Otherwise OF/C++ sees it as an int, which would be then understood as Log Level, not time.
		flashMessages.add("message with specific time", 4.0);
		break;
	case 'd':
		flashMessages.add("message with specific Log Level (Verbose)", 4, OF_LOG_VERBOSE);
		break;
	case 'f':
		flashMessages.add("message with specific Log Level (Notice)", OF_LOG_NOTICE);
		break;
	case 'g':
		flashMessages.add("message with specific Log Level (Warning)", OF_LOG_WARNING);
		break;
	case 'h':
		flashMessages.add("message with specific Log Level (Error)", OF_LOG_ERROR);
		break;
	case 'j':
		flashMessages.add("message with specific Log Level (Error) and specific time", 4, OF_LOG_ERROR);
		break;
	}
}
