#include "color.h"


Color::Color()
{
}

Color::Color(char r, char g, char b)
    :red(r), green(g), blue(b)
{
}

void Color::setColor(Color &value)
{
    red = value.red;
    green = value.green;
    blue = value.blue;
}

void Color::setColor(char r, char g, char b)
{
    red = r;
    green = g;
    blue = b;
}

char Color::getRed() const
{
    return red;
}

void Color::setRed(char value)
{
    red = value;
}

char Color::getGreen() const
{
    return green;
}

void Color::setGreen(char value)
{
    green = value;
}

char Color::getBlue() const
{
    return blue;
}

void Color::setBlue(char value)
{
    blue = value;
}
