#ifndef COLOR_H
#define COLOR_H

class Color
{
    char red, green, blue;
public:
    Color(char, char, char);
    void setColor(Color);
    void setColor(char, char, char);

    char getRed() const;
    void setRed(char value);
    char getGreen() const;
    void setGreen(char value);
    char getBlue() const;
    void setBlue(char value);
};

#endif // COLOR_H
