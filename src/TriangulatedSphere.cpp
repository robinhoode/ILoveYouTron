
#include "TriangulatedSphere.h"

void TriangulatedSphere::draw() {
    scalar = 100;
 
    glPushMatrix(); {
	   drawTexture(scalar);
	   drawWireframe(scalar);
    } glPopMatrix();

    doRotations();
}

void TriangulatedSphere::doRotations() {
    // Do the rotations
    angleY += PI/128;
    glRotatef(angleY, 0, 1, 0);
    angleZ += PI/243;
    glRotatef(angleZ, 0, 0, 1);
}

void TriangulatedSphere::drawWireframe(int scalar) {
//    glDisable(GL_POLYGON_OFFSET_FILL);
//    glDisable(GL_LIGHTING);

    glEnable(GL_BLEND); {
	   glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	   glBegin(GL_TRIANGLES); {
		  glColor3f(0.0, 0.0, 1.0);
		  drawVertices(scalar);
	   } glEnd();
    } glDisable(GL_BLEND);
}

void TriangulatedSphere::drawTexture(int scalar) {
    // Then fill with texture (solid black fill but still called a texture)
/*
    GLfloat black[] = {0, 0, 0, 0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, black);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
*/

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_POLYGON_OFFSET_FILL); {
	   glPolygonOffset(1, 1);

	   glBegin(GL_TRIANGLES); {
		  glColor3f(0.0, 0.0, 0.0);
		  drawVertices(scalar);
	   } glEnd();

    } glDisable(GL_POLYGON_OFFSET_FILL);
}

void TriangulatedSphere::drawVertices(int scalar) {
    for (double i = 0; i <= 2*PI; i += latSteps) {
	   for (double j = 0; j <= PI; j += longSteps/2) {
		  drawTopTriangle(scalar*cos(i), scalar*cos(i+latSteps), scalar*sin(i), scalar*sin(i+latSteps), j);        
		  j += longSteps/2;
		  drawBottomTriangle(scalar*cos(i), scalar*cos(i+latSteps), scalar*sin(i), scalar*sin(i+latSteps), j);
	   }
      
	   i += latSteps;

	   for (double j = longSteps/2; j <= PI + longSteps/2; j += longSteps/2) {
		  drawTopTriangle(scalar*cos(i), scalar*cos(i+latSteps), scalar*sin(i), scalar*sin(i+latSteps), j);        
		  j += longSteps/2;
		  drawBottomTriangle(scalar*cos(i), scalar*cos(i+latSteps), scalar*sin(i), scalar*sin(i+latSteps), j);
	   }
    }    
}

void TriangulatedSphere::drawTopTriangle(double s0, double s1, double top, double bottom, double j) {
    vertex(top,    s0*cos(j),             s0*sin(j));
    vertex(top,    s0*cos(j+longSteps),   s0*sin(j+longSteps)); 
    vertex(bottom, s1*cos(j+longSteps/2), s1*sin(j+longSteps/2));
}

void TriangulatedSphere::drawBottomTriangle(double s0, double s1, double top, double bottom, double j) {
    vertex(bottom, s1*cos(j),             s1*sin(j));
    vertex(bottom, s1*cos(j+longSteps),   s1*sin(j+longSteps));      
    vertex(top,    s0*cos(j+longSteps/2), s0*sin(j+longSteps/2));
}
