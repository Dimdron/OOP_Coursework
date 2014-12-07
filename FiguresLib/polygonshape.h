#ifndef POLYGONSHAPE_H
#define POLYGONSHAPE_H
#include "figure.h"
#include "polygon.h"

class PolygonShape : public Figure
{
protected:
    Polygon polygon;
    Figures::FigurType type() const;
public:
    PolygonShape(int nodes_count);
    Polygon getPolygon();

    void move(float dx, float dy);
    bool contains(float x, float y) const;
};

#endif // POLYGONSHAPE_H
