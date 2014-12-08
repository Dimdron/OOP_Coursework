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
    for (int i = 0; i < polygon.size(); i++)
    {
        Point p = polygon[i];
        p.setX(p.getX() + dx);
        p.setY(p.getY() + dy);
//        polygon[i] = p;
    }

}

bool PolygonShape::contains(float x, float y) const
{
    Point *vector;
    Point v, w;
    int parity = 0;
    for (int i = 0; i < polygon.size(); i++)
    {
        vector = getEdge(i);
        v = *vector;
        w = *(++vector);
        switch (position(x, y, v, w))
        {
        case 0:
            return true;
        case -1:
            if (v.getY() < y && y <= w.getY())
                parity = 1 - parity;
            break;
        case 1:
            if (w.getY()< y && y <= v.getY())
                parity = 1 - parity;
            break;
        }
    }
    return parity;
}

int PolygonShape::position(float x, float y, const Point &v, const Point &w) const
{
    float a = w.getY() - v.getY();
    float b = v.getX() - w.getX();
    float c = -(a * v.getX() + b * v.getY());
    float result = a * x + b * y + c;
    return result == 0 ? 0 : result < 0 ? -1 : 1;
}

Point* PolygonShape::getEdge(int number) const
{
    int second = 0;
    if (polygon.size() > number)
        second = number + 1;
    Point result[] = {polygon[number], polygon[second]};
    return result;
}

Figures::FigurType PolygonShape::type() const
{
    return Figures::PoligonType;
}
