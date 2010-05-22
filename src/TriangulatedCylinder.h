#ifndef _TRIANGULATED_CYLINDER
#define _TRIANGULATED_CYLINDER

#include "ofMath.h"
#include "ofMain.h"
#include "ofConstants.h"
#include "ThreeDShape.h"

class TriangulatedCylinder : ThreeDShape {

public:
  double angleY, angleZ, angleStep;

  double standardShapeHeight, shapeHeight, levelShape;
  double iterationSize, levelScale;
  
  TriangulatedCylinder() {
      setup();

	 levelScale    = 1500;
	 iterationSize = 2;
  }

  TriangulatedCylinder(double l, double i) {
      setup();

	 levelScale          = l;
	 iterationSize       = i;
  }

  void setup();

  void draw();
  void drawVertices(double shapeHeight, double scalar);

  void drawWireframe(double shapeHeight, double scalar);
  void drawTexture(double shapeHeight, double scalar);

/*
  void doRotation() {
	 angleY += PI/128;
	 rotateY(angleY);
	 angleZ += PI/243;
	 rotateZ(angleZ);    
  }
*/
};

#endif