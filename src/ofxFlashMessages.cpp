#include "ofxFlashMessages.h"

//--------------------------------------------------------------
void ofxFlashMessages::add(string message) {
	add(message, 5, OF_LOG_NOTICE);
}

//--------------------------------------------------------------
void ofxFlashMessages::add(string message, int logLevel) {
	add(message, 5, logLevel);
}

//--------------------------------------------------------------
void ofxFlashMessages::add(string message, float seconds) {
	add(message, seconds, OF_LOG_NOTICE);
}
//--------------------------------------------------------------
void ofxFlashMessages::add(string message, double seconds) {
	add(message, seconds, OF_LOG_NOTICE);
}


//--------------------------------------------------------------
void ofxFlashMessages::add(string message, float seconds, int logLevel) {
	ofLogVerbose("add FlashMessage: '" + message + "'" );

	flashMessage* messageToAdd = new flashMessage;
	messageToAdd->text = message;
	messageToAdd->startedAt = ofGetElapsedTimeMillis();
	messageToAdd->duration = seconds * 1000;
	messageToAdd->logLevel = logLevel;
	messageToAdd->alpha = 255;

	messages.emplace_back(messageToAdd);
	flashMessageTimer = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
bool ofxFlashMessages::isExpired(flashMessage & messageToCheck) {
	return messageToCheck.alpha <= 0.05;
}

//--------------------------------------------------------------
void ofxFlashMessages::update() {
	actualTime = ofGetElapsedTimeMillis();
	//remove_if(messages.begin(), messages.end(), isExpired );
		//messages.erase(
		//remove_if(messages.begin(), messages.end(), isExpired),
		//messages.end());

}
//--------------------------------------------------------------
void ofxFlashMessages::draw() {
    draw(ofGetWidth());
}

//--------------------------------------------------------------
void ofxFlashMessages::draw(int _width) {


		for (auto i = 0; i < messages.size(); i++) {
			//ofLogNotice(ofToString(actualTime));
			//ofLogNotice(ofToString(messages.at(i)->startedAt) + " + " +  ofToString(messages.at(i)->startedAt + messages.at(i)->duration) + " = " +       ofToString( messages.at(i)->duration)  );

			ofPushStyle();

			switch (messages.at(i)->logLevel) {
			case OF_LOG_VERBOSE:
				ofSetColor(0, 110, 0, messages.at(i)->alpha);
				break;
			case OF_LOG_NOTICE:
				ofSetColor(240, 200, 0, messages.at(i)->alpha);
				break;
			case OF_LOG_WARNING:
				ofSetColor(255, 100, 0, messages.at(i)->alpha);
				break;
			case OF_LOG_ERROR:
				ofSetColor(120, 0, 0, messages.at(i)->alpha);
				break;
			default:
				ofSetColor(255, 100, 0, messages.at(i)->alpha);
				break;

				break;
			}

			ofDrawRectangle(10, 10 + (i * 30), _width - 20, 20);
			switch (messages.at(i)->logLevel) {
			case OF_LOG_VERBOSE:
				ofSetColor(255, 255, 255, messages.at(i)->alpha);
				break;
			case OF_LOG_NOTICE:
				ofSetColor(0, 0, 0, messages.at(i)->alpha);
				break;
			case OF_LOG_WARNING:
				ofSetColor(0, 0, 0, messages.at(i)->alpha);
				break;
			case OF_LOG_ERROR:
				ofSetColor(255, 255, 255, messages.at(i)->alpha);
				break;
			default:
				ofSetColor(0, 0, 0, messages.at(i)->alpha);
				break;

			}
			ofDrawBitmapString(ofToString(messages.at(i)->text), 20, 25 + (i * 30));
			ofPopStyle();

			if (actualTime > (messages.at(i)->startedAt + messages.at(i)->duration)) {
				messages.at(i)->alpha -= 4;
				if (messages.at(i)->alpha <= 4) {
					messages.erase(messages.begin() + i);
				}
			}
		}
}
