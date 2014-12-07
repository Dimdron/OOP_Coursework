#include "rectangle.h"



Rectangle::Rectangle(float width, float height, float posX, float posY)
    :PolygonShape(4)
{
    // top left
    polygon[0] = Point(posX, posY);

    // top right
    polygon[1] = Point(posX + width, posY);

    // bottom right
    polygon[2] = Point(posX + width, posY + height);

    // bottom left
    polygon[3] =  Point(posX, posY + height);

//    // top left
//    polygon.push_back(Point(posX, posY));

//    // top right
//    polygon.push_back(Point(posX + width, posY));

//    // bottom right
//    polygon.push_back(Point(posX + width, posY + height));

//    // bottom left
//    polygon.push_back(Point(posX, posY + height));
}
