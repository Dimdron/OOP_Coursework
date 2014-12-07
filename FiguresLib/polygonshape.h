#ifndef POLYGONSHAPE_H
#define POLYGONSHAPE_H
#include "figure.h"
#include "polygon.h"

class PolygonShape : public Figure
{

protected:
    Polygon polygon;
    int width;
    int height;
    Figures::FigurType type() const;
public:
    PolygonShape(int, int);
    Polygon getPolygon();
};

#endif // POLYGONSHAPE_H
