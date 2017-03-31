#include "ofApp.h"
#define NUM 1000

float loc_x[NUM];
float loc_y[NUM];

float speed_x[NUM];
float speed_y[NUM];

float radius[NUM];

float red[NUM];
float green[NUM];
float blue[NUM];

bool mouse_pressed;

float gravity;
float friction;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
  
    
    mouse_pressed = false;
    
    gravity = 0.1;
    friction = 0.999;
    
    /*
    loc_x = 20;
    loc_y = 20;
    
    speed_x = 4;
    speed_y = 7;
    */
    

    
    for (int i=0; i<NUM; i++) {
        
        
        loc_x[i] = ofRandom(0,ofGetWidth());
        loc_y[i] = ofRandom(0,ofGetHeight());
        
        speed_x[i] = ofRandom(-10,10);
        speed_y[i] = ofRandom(-10,10);
        
        radius[i] =ofRandom(4,40);
        
        red[i] = ofRandom(0,255);
        blue[i] = ofRandom(0,255);
        green[i] = ofRandom(0,255);
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
  /*
    loc_x = loc_x + speed_x;
    loc_y = loc_y + speed_y;
  */
    
   
    
    for (int i=0; i<NUM; i++) {
        
        if (mouse_pressed) {
            speed_x[i]=(mouseX - loc_x[i])/8.0;
            speed_y[i]=(mouseY - loc_y[i])/8.0;
        }
        
        speed_x[i] = speed_x[i]*friction;
        speed_y[i] = speed_y[i]*friction;
        speed_y[i] = speed_y[i]+gravity;



        
        loc_x[i] = loc_x[i] + speed_x[i];
        loc_y[i] = loc_y[i] + speed_y[i];
   
    
    if (loc_x[i] < 0) {
        loc_x[i] = 0;
        speed_x[i] = speed_x[i]*-1;
    }
    
    if (loc_x[i] > ofGetWidth()) {
        loc_x[i] = ofGetWidth();
        speed_x[i] = speed_x[i]*-1;
    }
    
    if (loc_y[i] < 0) {
        loc_y[i] = 0;
        speed_y[i] = speed_y[i]*-1;
    }
    
    if (loc_y[i] > ofGetHeight()) {
        loc_y[i] = ofGetHeight();
        speed_y[i] = speed_y[i]*-1;
    }
        
    }//ここまでfor文

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0, 0, 0,127);
    ofRect(0,0,ofGetWidth(),ofGetHeight());

    
    for (int i=0; i<NUM; i++) {
     ofSetColor(red[i], green[i], blue[i],127);
     ofCircle(loc_x[i], loc_y[i], radius[i]);
     }
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
    
    mouse_pressed = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    mouse_pressed = false;
    
    for (int i=0; i<NUM; i++) {
        speed_x[i] = ofRandom(-5,5);
        speed_y[i] = ofRandom(-5,5);
    }

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
