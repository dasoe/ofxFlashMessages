#pragma once

#include "ofMain.h"
#include "ofxFlashMessages.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		ofxFlashMessages flashMessages;

};
