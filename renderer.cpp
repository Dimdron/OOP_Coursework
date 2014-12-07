#include "renderer.h"
#include <QPainter>


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
        painter.setPen(QColor(color.getRed(), color.getGreen(), color.getBlue()));

        if (figure->type() == Figures::PoligonType)
            drawPolygon(static_cast<PolygonShape*>(figure), painter);
    }

}

void Renderer::drawPolygon(PolygonShape *shape, QPainter &painter)
{
    Polygon polygon = shape->getPolygon();
    Polygon::iterator pointer;

    for (pointer = polygon.begin(); pointer != polygon.end(); pointer++)
    {
        Point point = *pointer;

        painter.drawPoint(point.getX(), point.getY());
    }
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


