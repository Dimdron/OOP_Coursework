#ifndef FIGURE_H
#define FIGURE_H
#include "color.h"

namespace Figures {

    enum FigurType {
        PoligonType, GroupType
    };
}

class Figure
{
private:
    double x, y;
    Color color;
    bool visible;
protected:
    Figure();
    Figure(double x, double y);
    Figure(double x, double y, const Color&);
public:
    ~Figure();
    Color getColor();
    void setColor(Color);

    bool isVisible() const;
    void setVisible(bool value);

    double getX() const;
    void setX(double value);
    double getY() const;
    void setY(double value);

    virtual Figures::FigurType type() const = 0;
};



#endif // FIGURE_H
