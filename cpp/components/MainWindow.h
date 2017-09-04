//
// Created by hy on 17-9-4.
//

#ifndef MUSIC_MAINWINDOW_H
#define MUSIC_MAINWINDOW_H


#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include "TitleBar.h"

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QApplication *app);

private:
    QApplication *app;
    TitleBar *titleBar;
};


#endif //MUSIC_MAINWINDOW_H
