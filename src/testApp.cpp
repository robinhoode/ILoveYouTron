#include <iostream>
#include <cstdlib>

#include "testApp.h"

/* initialize lighting */
void testApp::lightingInit() {

/*
    GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
    GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

    GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
    GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};

    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);
    glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);
*/

    // Use global lighting


    GLfloat globalAmbient[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, globalAmbient);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}

void testApp::openGlInit() { 
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_LINE_SMOOTH); 

    //some model / light stuff
    glEnable(GL_DEPTH_TEST);
    // Enable Blending


//    glBlendFunc(GL_ONE, GL_ZERO);

//    glBlendFunc(GL_ZERO, GL_ONE);

//    glShadeModel(GL_SMOOTH);

//    lightingInit();

//    glEnable(GL_COLOR_MATERIAL);
//    Using this option will turn everything white.. WTF??
//    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);

}

void testApp::cameraInit() {
     useCamera = true;

    	centerX = ofGetWidth()/2;
	centerY = ofGetHeight()/2;
	centerZ = 0;

     camera = ofxEasyCam();
     camera.zoomSpeed = 50;
	camera.setOrigin(OF_ORIGIN_ZERO);
	camera.position(centerX, centerY, 5000); //initialize the camera at a far position from the sphere
}

//--------------------------------------------------------------
void testApp::setup(){	
    int boxSize = 1000;
    int spacing = boxSize / 10;

//    sphere    = TriangulatedSphere();
    outerGrid = OuterGrid(boxSize, spacing);


    /* Black background */
    ofBackground(0,0,0);    		
    ofSetVerticalSync(true);

    openGlInit();
    cameraInit();
//    useCamera = false;

}

void testApp::cameraUpdate() {
//    camera.lerpPosition(centerX, centerY, 500, 0.1); //interpolate the camera into a closer position
}	

//--------------------------------------------------------------
void testApp::update(){
    cameraUpdate();
/*
    squirrelModel.setRotation(1, 270 + ofGetElapsedTimef() * 60, 0, 0, 1);
*/
}

void testApp::cameraBeginDraw() {
    if (useCamera)
	   camera.place();
}

void testApp::cameraEndDraw() {
    if (useCamera)
	   camera.remove();
}

//--------------------------------------------------------------
void testApp::draw() {
    cameraBeginDraw(); {
        outerGrid.draw();
        sphere.draw();
    } cameraEndDraw();

    // ofSetColor(0x000000);
    // Set text color to white
    ofSetColor(0xffffff);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 10, 15);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 

}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}
