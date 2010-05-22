#ifndef _OUTER_GRID
#define _OUTER_GRID

#include "ofMain.h"
#include "ThreeDShape.h"

class OuterGrid : ThreeDShape {

public:
    int boxSize, spacing, boxCount;


    OuterGrid() {
        boxSize = 1000;
        spacing = 100;
        setup();        
    }
 
    OuterGrid(int b, int s) {
	   boxSize = b;
	   spacing = s;
        setup();        
    }

    void setup();

    void draw();

    void topWall(int i);
    void bottomWall(int i);
    void rightWall(int i);
    void leftWall(int i);
    void backWall(int i);
    void frontWall(int i);

    void topGrid(int i, int j);
    void bottomGrid(int i, int j);
    void rightGrid(int i, int j);
    void leftGrid(int i, int j);
    void backGrid(int i, int j);
    void frontGrid(int i, int j);
    
};

#endif
