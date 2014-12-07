#include "square.h"



Square::Square(int width)
    :PolygonShape(width, width)
{
//    setColor(0, 0, 255);
    setVisible(true);
    initPolygon();
}

void Square::initPolygon()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            polygon.push_back(Point(x, y));
}
