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
    int id;
    Color color;
    bool visible;
    bool selected;
protected:
    Figure();
    Figure(const Color&);
public:
    ~Figure();
    Color getColor() const;
    void setColor(Color);

    bool isVisible() const;
    void setVisible(bool value);

    virtual bool contains(float x, float y) const = 0;
    virtual void move(float dx, float dy) = 0;
    virtual Figures::FigurType type() const = 0;

    int getId() const;
    void setId(int value);
    bool getSelected() const;
    void setSelected(bool value);
};



#endif // FIGURE_H
