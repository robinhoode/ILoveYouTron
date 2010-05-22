#ifndef _OUTER_GRID
#define _OUTER_GRID

#include "ofMain.h"

class OuterGrid {

public:
    int boxSize;
    int spacing;

    OuterGrid() {
        boxSize = 1000;
        spacing = 100;
    }
 
    OuterGrid(int b, int s) {
	   boxSize = b;
	   spacing = s;
    }

    void draw();

    void vertex(float x, float y, float z);

    void topWall(int i);
    void bottomWall(int i);
    void rightWall(int i);
    void leftWall(int i);
    void backWall(int i);
    void frontWall(int i);
    
};

#endif
