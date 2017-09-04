//
// Created by hy on 17-9-4.
//

#include "MainWindow.h"

MainWindow::MainWindow(QApplication *app) : app(app) {
    setFixedSize(800, 600);
    setWindowFlags(Qt::FramelessWindowHint);

    titleBar = new TitleBar(this);
    titleBar->setGeometry(160, 0, 640, 40);

    connect(titleBar, SIGNAL(quit()), app, SLOT(quit()));
    connect(titleBar, SIGNAL(minimized()), this, SLOT(showMinimized()));
    connect(titleBar, SIGNAL(maximized()), this, SLOT(showMaximized()));
}
