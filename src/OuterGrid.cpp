#include "OuterGrid.h"


void OuterGrid::draw() {
//    ofSetColor(0, 128, 0);

    glEnable(GL_BLEND); {
	   glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	   glColor3f(0, 1.0, 0);
	   glBegin(GL_LINES); {
		  for (int i = -boxSize; i <= boxSize; i += spacing) {
			 bottomWall(i); topWall(i);
			 rightWall(i);  leftWall(i);
			 backWall(i);   frontWall(i);
		  }
	   } glEnd();

    } glDisable(GL_BLEND);
}

void OuterGrid::bottomWall(int i) {
    // Bottom wall
    // (i, +, -) => (i, +, +)
    vertex(i, boxSize, -boxSize); vertex(i, boxSize, boxSize); 
    // (+, +, i) => (-, +, i)    
    vertex(boxSize,  boxSize, i); vertex(-boxSize, boxSize, i);  
} 
  
void OuterGrid::topWall(int i) {
    // Top wall
    // (i, -, -) => (i, -, +)
    vertex(i, -boxSize, -boxSize); vertex(i, -boxSize, boxSize);  
    // (+, -, i) => (-, -, i)
    vertex(boxSize, -boxSize, i); vertex(-boxSize, -boxSize, i); 
}

void OuterGrid::rightWall(int i) {
    // Right wall    
    // (+, +, i) => (+, -, i)        
    vertex(boxSize,  boxSize, i); vertex(boxSize, -boxSize, i); 
    // (+, i, +) => (+, i, -)    
    vertex(boxSize,  i, boxSize); vertex(boxSize, i, -boxSize);   
}
  
void OuterGrid::leftWall(int i) {
    // Left wall
    // (-, -, i) => (-, +, i)    
    vertex(-boxSize, -boxSize, i); vertex(-boxSize, boxSize, i); 
    // (-, i, -) => (-, i, +)    
    vertex(-boxSize, i, -boxSize); vertex(-boxSize, i, boxSize);  
}
  
void OuterGrid::backWall(int i) {
    // Back wall
    // (i, +, +) => (i, -, +)    
    vertex(i, boxSize, boxSize); vertex(i, -boxSize, boxSize);
    // (+, i, +) => (-, i, +)    
    vertex(boxSize, i, boxSize); vertex(-boxSize, i, boxSize);    
}
  
void OuterGrid::frontWall(int i) {
    // Front wall
    // (i, -, -) => (i, +, -)    
    vertex(i, -boxSize, -boxSize); vertex(i, boxSize, -boxSize);  
    // (-, i, -) => (+, i, -)            
    vertex(-boxSize, i, -boxSize); vertex(boxSize, i, -boxSize);  
}

void OuterGrid::vertex(float x, float y, float z) {
    glVertex3f(x, y, z);
}
