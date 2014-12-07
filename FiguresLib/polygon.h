#ifndef POLYGON_H
#define POLYGON_H
#include <vector>
#include "point.h"

class Polygon: public std::vector<Point>
{
public:
    Polygon();
    Polygon(int);
};

#endif // POLYGON_H
