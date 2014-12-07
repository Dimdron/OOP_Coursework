#ifndef RENDERER_H
#define RENDERER_H

#include <QHash>
#include <QWidget>
#include <QPaintEvent>
#include "polygonshape.h"

class Renderer : public QWidget
{
    Q_OBJECT
//    Q_PROPERTY(QColor background READ getBackground WRITE setBackground)
    typedef QHash<int, Figure*> FiguresContainer;
private:
    FiguresContainer figures;
    QColor background;
    bool repaintScene;
    QImage sceneImage;

    void clearScene();
    void drawScene();
    void drawPolygon(PolygonShape*, QPainter&);
protected:
     void paintEvent(QPaintEvent *event);
public:
    explicit Renderer(QWidget *parent = 0);

    void addFigure(Figure *figure);

    QColor getBackground() const;
    void setBackground(const QColor &value);
//    QSize sizeHint();
    void resizeSceneImage(QImage *image, const QSize &newSize);
    void resizeEvent(QResizeEvent *event);

signals:

public slots:

};

#endif // RENDERER_H
