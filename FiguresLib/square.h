#ifndef SQUARE_H
#define SQUARE_H
#include "polygonshape.h"

class Square : public PolygonShape
{
protected:
    void initPolygon();
public:
    Square(int width);
};

#endif // SQUARE_H
