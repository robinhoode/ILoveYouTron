#ifndef _TRIANGULATED_SPHERE
#define _TRIANGULATED_SPHERE

#include "ofMath.h"
#include "ofMain.h"
#include "ofConstants.h"
#include "ThreeDShape.h"

class TriangulatedSphere : ThreeDShape {

public:

    double scalar;
    double longSteps, latSteps; 
  
    double angleY, angleZ;

    TriangulatedSphere() {
	   scalar    = 500;
	   longSteps = PI/12;
	   latSteps  = PI/12;   
	   angleY    = ofRandom(0, 128)*PI/128;
	   angleZ    = ofRandom(0, 243)*PI/243;    
    }

    void doRotations();

    void draw();

    void drawVertices(int scalar);

    void drawWireframe(int scalar);
    void drawTexture(int scalar);

    void drawTopTriangle(double, double, double, double, double);
    void drawBottomTriangle(double, double, double, double, double);
};

#endif
