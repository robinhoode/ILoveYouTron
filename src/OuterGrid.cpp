#include "OuterGrid.h"

void OuterGrid::setup() {
    boxCount = boxSize / spacing;
}

void OuterGrid::draw() {
    glEnable(GL_BLEND); {
	   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	   glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	   glColor3f(0, 1.0, 0);
	   glBegin(GL_QUADS); {
		  for (int i = -boxSize; i < boxSize; i += spacing) {
			 for (int j = -boxSize; j < boxSize; j += spacing) {
				bottomGrid(i, j); topGrid(i, j);
				leftGrid(i, j);   rightGrid(i, j);
				frontGrid(i, j);  backGrid(i, j);
			 }
		  }
	   } glEnd();
/*
	   glBegin(GL_LINES); {
		  for (int i = -boxSize; i <= boxSize; i += spacing) {
			 bottomWall(i); topWall(i);
			 rightWall(i);  leftWall(i);
			 backWall(i);   frontWall(i);
		  }
	   } glEnd();
*/
    } glDisable(GL_BLEND);
}

void OuterGrid::bottomWall(int i) {
    // Bottom wall
    // (i, +, -) => (i, +, +)
    vertex(i, boxSize, -boxSize); vertex(i, boxSize, boxSize); 
    // (+, +, i) => (-, +, i)    
    vertex(boxSize,  boxSize, i); vertex(-boxSize, boxSize, i);  
} 

void OuterGrid::bottomGrid(int i, int j) {
    vertex(i          , boxSize, j          );
    vertex(i + spacing, boxSize, j          );
    vertex(i + spacing, boxSize, j + spacing);
    vertex(i          , boxSize, j + spacing);
}
  
void OuterGrid::topWall(int i) {
    // Top wall
    // (i, -, -) => (i, -, +)
    vertex(i, -boxSize, -boxSize); vertex(i, -boxSize, boxSize);  
    // (+, -, i) => (-, -, i)
    vertex(boxSize, -boxSize, i); vertex(-boxSize, -boxSize, i); 
}

void OuterGrid::topGrid(int i, int j) {
    vertex(i          , -boxSize, j          );
    vertex(i + spacing, -boxSize, j          );
    vertex(i + spacing, -boxSize, j + spacing);
    vertex(i          , -boxSize, j + spacing);
}

void OuterGrid::rightWall(int i) {
    // Right wall    
    // (+, +, i) => (+, -, i)        
    vertex(boxSize,  boxSize, i); vertex(boxSize, -boxSize, i); 
    // (+, i, +) => (+, i, -)    
    vertex(boxSize,  i, boxSize); vertex(boxSize, i, -boxSize);   
}

void OuterGrid::rightGrid(int i, int j) {
    vertex(boxSize, i          , j          );
    vertex(boxSize, i + spacing, j          );
    vertex(boxSize, i + spacing, j + spacing);
    vertex(boxSize, i          , j + spacing);
}

void OuterGrid::leftWall(int i) {
    // Left wall
    // (-, -, i) => (-, +, i)    
    vertex(-boxSize, -boxSize, i); vertex(-boxSize, boxSize, i); 
    // (-, i, -) => (-, i, +)    
    vertex(-boxSize, i, -boxSize); vertex(-boxSize, i, boxSize);  
}

void OuterGrid::leftGrid(int i, int j) {
    vertex(-boxSize, i          , j          );
    vertex(-boxSize, i + spacing, j          );
    vertex(-boxSize, i + spacing, j + spacing);
    vertex(-boxSize, i          , j + spacing);
}
  
void OuterGrid::backWall(int i) {
    // Back wall
    // (i, +, +) => (i, -, +)    
    vertex(i, boxSize, boxSize); vertex(i, -boxSize, boxSize);
    // (+, i, +) => (-, i, +)    
    vertex(boxSize, i, boxSize); vertex(-boxSize, i, boxSize);    
}

void OuterGrid::backGrid(int i, int j) {
    vertex(i          , j          , boxSize);
    vertex(i + spacing, j          , boxSize);
    vertex(i + spacing, j + spacing, boxSize);
    vertex(i          , j + spacing, boxSize);
}
  
void OuterGrid::frontWall(int i) {
    // Front wall
    // (i, -, -) => (i, +, -)    
    vertex(i, -boxSize, -boxSize); vertex(i, boxSize, -boxSize);  
    // (-, i, -) => (+, i, -)            
    vertex(-boxSize, i, -boxSize); vertex(boxSize, i, -boxSize);  
}

void OuterGrid::frontGrid(int i, int j) {
    vertex(i          , j          , -boxSize);
    vertex(i + spacing, j          , -boxSize);
    vertex(i + spacing, j + spacing, -boxSize);
    vertex(i          , j + spacing, -boxSize);
}
