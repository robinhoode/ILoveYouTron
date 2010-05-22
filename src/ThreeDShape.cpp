#include "ThreeDShape.h"

void ThreeDShape::vertex(double x, double y, double z) {
    glVertex3f((float) x, (float) y, (float) z);
}