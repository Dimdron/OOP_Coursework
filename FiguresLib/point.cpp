#include "point.h"

Point::Point(int x, int y)
    :x(x), y(y)
{
}

Point::Point(Point point)
    :x(point.x), y(point.y)
{
}

int Point::getX()
{
    return x;
}

void Point::setX(int x)
{
    this->x = x;
}

int Point::getY()
{
    return y;
}

void Point::setY(int y)
{
    this->y = y;
}
