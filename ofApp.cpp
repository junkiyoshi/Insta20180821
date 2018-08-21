#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
}
//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 72;
	int radius = 30;

	for (int x = span * 0.5; x < ofGetWidth(); x += span) {

		for (int y = span * 0.5; y < ofGetHeight(); y += span) {

			ofBeginShape();
			for (int deg = 0; deg < 360; deg += 5) {

				int circle_x = radius * cos(deg * DEG_TO_RAD);
				int circle_y = radius * sin(deg * DEG_TO_RAD);

				int noise_radius = radius * ofNoise((x + circle_x) * 0.05, (y + circle_y) * 0.05, ofGetFrameNum() * 0.01);

				circle_x = noise_radius * cos(deg * DEG_TO_RAD);
				circle_y = noise_radius * sin(deg * DEG_TO_RAD);

				ofVertex(x + circle_x, y + circle_y);
			}
			ofEndShape(true);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}