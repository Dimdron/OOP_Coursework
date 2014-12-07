#include "polygon.h"

Polygon::Polygon()
    :std::vector<Point>()
{
}

Polygon::Polygon(int size)
    :std::vector<Point>(size)
{
}
