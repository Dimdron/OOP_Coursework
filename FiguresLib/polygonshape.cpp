#include "polygonshape.h"

PolygonShape::PolygonShape(int width, int height)
    :Figure(), width(width), height(height)
{
    polygon = Polygon(width * height);
}

Polygon PolygonShape::getPolygon()
{
    return polygon;
}

Figures::FigurType PolygonShape::type() const
{
    return Figures::PoligonType;
}
