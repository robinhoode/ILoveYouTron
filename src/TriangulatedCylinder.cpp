#include "TriangulatedCylinder.h"

void TriangulatedCylinder::setup() {
    angleY              = ofRandom(0, 128)*PI/128;
    angleZ              = ofRandom(0, 243)*PI/243;
    standardShapeHeight = 20;
    angleStep           = PI/12;
}

void TriangulatedCylinder::drawVertices(double shapeHeight, double scalar) {
    for (double i = 0; i < 2*PI; i += angleStep*iterationSize) {
	   vertex(shapeHeight,  scalar*cos(i),             scalar*sin(i));
	   vertex(shapeHeight,  scalar*cos(i+angleStep),   scalar*sin(i+angleStep));
	   vertex(-shapeHeight, scalar*cos(i+angleStep/2), scalar*sin(i+angleStep/2));
      
	   i += angleStep*iterationSize;

	   vertex(-shapeHeight,  scalar*cos(i),             scalar*sin(i));
	   vertex(-shapeHeight,  scalar*cos(i+angleStep),   scalar*sin(i+angleStep));
	   vertex(shapeHeight,   scalar*cos(i+angleStep/2), scalar*sin(i+angleStep/2));
    }
}
  
void TriangulatedCylinder::draw() {
    double scalar = 150;
   
    glPushMatrix(); {
	   drawWireframe(standardShapeHeight, scalar);
        drawTexture(standardShapeHeight, scalar);
    } glPopMatrix();
} 

void TriangulatedCylinder::drawWireframe(double shapeHeight, double scalar) {
    glEnable(GL_BLEND); {
	   glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	   glBegin(GL_TRIANGLES); {
		  glColor3f(0.0, 0.0, 1.0);
		  drawVertices(shapeHeight, scalar);
	   } glEnd();
    } glDisable(GL_BLEND);
} 

void TriangulatedCylinder::drawTexture(double shapeHeight, double scalar) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_POLYGON_OFFSET_FILL); {
	   glPolygonOffset(1, 1);

	   glBegin(GL_TRIANGLES); {
		    glColor3f(0.0, 0.0, 0.0);
		    drawVertices(shapeHeight, scalar);
	   } glEnd();
    } glDisable(GL_POLYGON_OFFSET_FILL);    
}
