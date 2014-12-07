#include "figure.h"

Figure::Figure()
{
}

Figure::Figure(double x, double y)
    :x(x), y(y)
{
}

Figure::Figure(double x, double y, const Color &color)
    :x(x), y(y), color(color)
{
}

Figure::~Figure()
{
}

bool Figure::isVisible() const
{
    return visible;
}

void Figure::setVisible(bool value)
{
    visible = value;
}

double Figure::getX() const
{
    return x;
}

void Figure::setX(double value)
{
    x = value;
}

double Figure::getY() const
{
    return y;
}

void Figure::setY(double value)
{
    y = value;
}

Color Figure::getColor() {
    return color;
}
