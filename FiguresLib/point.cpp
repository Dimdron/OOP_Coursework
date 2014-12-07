#include "point.h"

Point::Point(float x, float y)
    :x(x), y(y)
{
}

Point::Point(const Point &point)
    :x(point.x), y(point.y)
{
}

float Point::getY() const
{
    return y;
}

void Point::setY(float value)
{
    y = value;
}
float Point::getX() const
{
    return x;
}

void Point::setX(float value)
{
    x = value;
}
