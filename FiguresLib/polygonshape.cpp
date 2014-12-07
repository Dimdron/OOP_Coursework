#include "polygonshape.h"

PolygonShape::PolygonShape(int nodes_count)
    :Figure()
{
    polygon = Polygon(nodes_count);
}

Polygon PolygonShape::getPolygon()
{
    return polygon;
}

void PolygonShape::move(float dx, float dy)
{
    for (int i = 0; i < polygon.size(); i++) {
        Point p = polygon[i];
        p.setX(p.getX() + dx);
        p.setY(p.getY() + dy);
//        polygon[i] = p;
    }

}

bool PolygonShape::contains(float x, float y) const
{

}

Figures::FigurType PolygonShape::type() const
{
    return Figures::PoligonType;
}
