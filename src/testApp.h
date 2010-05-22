#ifndef _TEST_APP
#define _TEST_APP

#include "ofxEasyCam.h"
#include "ofMain.h"
#include "ofx3DModelLoader.h"
#include "OuterGrid.h"
#include "TriangulatedSphere.h"
#include "TriangulatedCylinder.h"

class testApp : public ofBaseApp {
	
public:
    testApp() : ofBaseApp() { mouseX = mouseY = 0; }
		
    float centerX;
    float centerY;
    float centerZ;

    bool useCamera;

    ofxEasyCam camera;
    OuterGrid outerGrid;
    TriangulatedSphere sphere;
    TriangulatedCylinder cylinder, cylinder2;

    void cameraInit();
    void lightingInit();
    void openGlInit();

    void setup();

    void cameraUpdate();
    void update();

    void cameraBeginDraw();
    void cameraEndDraw();
    void draw();

    // TODO: Move these to their own class
    void drawWall();
		
    void keyPressed  (int key);
    void keyReleased (int key);
		
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
};

#endif
	
