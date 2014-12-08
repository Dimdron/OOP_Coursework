#include "renderer.h"
#include <QPainter>

#include <iostream>

QColor Renderer::getBackground() const
{
    return background;
}

void Renderer::setBackground(const QColor &value)
{
    background = value;
    update();
}

Renderer::Renderer(QWidget *parent) :
    QWidget(parent)
{
    figures = FiguresContainer();

    background = Qt::green;
    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Base);
}

void Renderer::addFigure(Figure *figure) {
    figures[figures.size()] = figure;
}

void Renderer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if(false)
        clearScene();
    drawScene();

    painter.drawImage(event->rect(), sceneImage, event->rect());
}

void Renderer::clearScene()
{
    sceneImage.fill(background);
}

void Renderer::drawScene()
{
    QPainter painter(&sceneImage);
    FiguresContainer::iterator iter;
    for (iter = figures.begin(); iter != figures.end(); iter++)
    {
        Figure *figure = *iter;
        Color color = figure->getColor();
        QColor qcolor(color.getRed(), color.getGreen(), color.getBlue());
        painter.setPen(qcolor);
        painter.setBrush(qcolor);
        if (figure->type() == Figures::PoligonType)
            drawPolygon(static_cast<PolygonShape*>(figure), painter);
    }

}

void Renderer::drawPolygon(PolygonShape *shape, QPainter &painter)
{
    Polygon polygon = shape->getPolygon();
    Polygon::iterator pointer;

    QPolygonF qpolygon;
    for (pointer = polygon.begin(); pointer != polygon.end(); pointer++)
        qpolygon.append(QPointF(pointer->getX(), pointer->getY()));

    painter.drawPolygon(qpolygon);
}

void Renderer::resizeSceneImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(Qt::white);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void Renderer::resizeEvent(QResizeEvent *event)
{
    if (width() > sceneImage.width() || height() > sceneImage.height()) {
        int newWidth = qMax(width() + 128, sceneImage.width());
        int newHeight = qMax(height() + 128, sceneImage.height());
        resizeSceneImage(&sceneImage, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void Renderer::mousePressEvent(QMouseEvent *event)
{
    std::cout<<"mousePressEvent X:"<<event->x()<<" Y:"<<event->y()<<std::endl;
    FiguresContainer::iterator iter;
    for (iter = figures.begin(); iter != figures.end(); iter++)
    {
        Figure *figure = *iter;
        if (figure->contains(event->x(), event->y()))
            std::cout<<"contains"<<std::endl;
        else
            std::cout<<"not contain"<<std::endl;

    }

}

void Renderer::mouseMoveEvent(QMouseEvent *event)
{
    std::cout<<"mouseMoveEvent X:"<<event->x()<<" Y:"<<event->y()<<std::endl;
}


