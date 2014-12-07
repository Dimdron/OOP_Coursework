#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "polygonshape.h"

class Rectangle: public PolygonShape
{
public:
    Rectangle(float width, float height, float posX, float posY);
};

#endif // RECTANGLE_H
