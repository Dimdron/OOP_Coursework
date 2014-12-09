#include "figure.h"


int Figure::getId() const
{
    return id;
}

void Figure::setId(int value)
{
    id = value;
}

bool Figure::getSelected() const
{
    return selected;
}

void Figure::setSelected(bool value)
{
    selected = value;
}

Figure::Figure()
{
}

Figure::Figure(const Color &color)
    :color(color)
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

Color Figure::getColor() const {
    return color;
}
