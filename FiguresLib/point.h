#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x, y;
public:
    Point() {}
    Point(int, int);
    Point(const Point&);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
};

#endif // POINT_H
