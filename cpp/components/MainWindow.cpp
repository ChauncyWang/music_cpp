//
// Created by hy on 17-9-4.
//

#include <QtGui/QPainter>
#include "MainWindow.h"

MainWindow::MainWindow(QApplication *app) : app(app) {
    setFixedSize(1000, 600);
    setWindowFlags(Qt::FramelessWindowHint);

    titleBar = new TitleBar(this);
    titleBar->setGeometry(200, 0, 800, 40);

    playBar = new PlayBar(this);
    playBar->setGeometry(0, 540, width(), 60);

    connect(titleBar, SIGNAL(quit()), app, SLOT(quit()));
    connect(titleBar, SIGNAL(minimized()), this, SLOT(showMinimized()));
    connect(titleBar, SIGNAL(maximized()), this, SLOT(showMaximized()));
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QImage image = QImage();
    image.load("res/jpg/background.jpg");
    image = image.scaled(width(),height());
    QPainter painter(this);
    painter.drawImage(0,0,image);
    QWidget::paintEvent(event);
}
