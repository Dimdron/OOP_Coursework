#include "point.h"

Point::Point(int x, int y)
    :x(x), y(y)
{
}

Point::Point(const Point &point)
    :x(point.x), y(point.y)
{
}

int Point::getY() const
{
    return y;
}

void Point::setY(int value)
{
    y = value;
}
int Point::getX() const
{
    return x;
}

void Point::setX(int value)
{
    x = value;
}
