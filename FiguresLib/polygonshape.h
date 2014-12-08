#ifndef POLYGONSHAPE_H
#define POLYGONSHAPE_H
#include "figure.h"
#include "polygon.h"

class PolygonShape : public Figure
{
private:
    int position(float x, float y, const Point &v, const Point &w) const;
    Point* getEdge(int number) const ;
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
