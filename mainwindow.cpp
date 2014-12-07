#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "square.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    renderer = new Renderer(this);

    renderer->addFigure(new Square(100));

    ui->verticalspace->addWidget(renderer);
}

MainWindow::~MainWindow()
{
    delete renderer;
    delete ui;
}
