#ifndef POINT_H
#define POINT_H

class Point
{
private:
    float x, y;
public:
    Point() {}
    Point(float, float);
    Point(const Point&);
    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);
};

#endif // POINT_H
