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

    background = Qt::white;
    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Base);
}

void Renderer::addFigure(Figure *figure) {
    figures[figures.size()] = figure;
}

void Renderer::paintEvent(QPaintEvent *event)
{
    std::cout<<"called paintEvent"<<std::endl;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if(true)
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
    std::cout<<"called resizeEvent"<<std::endl;
    QWidget::resizeEvent(event);
}

void Renderer::mousePressEvent(QMouseEvent *event)
{
    FiguresContainer::iterator iter;
    for (iter = figures.begin(); iter != figures.end(); iter++)
    {
        Figure *figure = *iter;
        if (figure->contains(event->x(), event->y()))
        {
            selected = figure;
            lastPosition = event->localPos();
        }
        else
        {
            selected = NULL;
        }

    }

}

void Renderer::mouseMoveEvent(QMouseEvent *event)
{
    if (selected == NULL)
        return;
    std::cout<<"lastMouseEvent "<< lastPosition.x() << " " << lastPosition.y() <<std::endl;
    std::cout<<"event "<< event->x() << " " << event->y() <<std::endl;
    selected->move(event->x() - lastPosition.x(), event->y() - lastPosition.y());
    lastPosition = event->localPos();
    update();
}


