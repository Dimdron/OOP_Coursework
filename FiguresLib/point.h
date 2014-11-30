#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x, y;
public:
    Point() {}
    Point(int, int);
    Point(Point);

    int getX() const;
    void setX(int);
    int getY() const;
    void setY(int);
};

#endif // POINT_H
