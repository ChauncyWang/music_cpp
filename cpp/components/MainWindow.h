//
// Created by hy on 17-9-4.
//

#ifndef MUSIC_MAINWINDOW_H
#define MUSIC_MAINWINDOW_H


#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include "TitleBar.h"
#include "PlayBar.h"

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QApplication *app);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QApplication *app;
    TitleBar *titleBar;
    PlayBar *playBar;
};


#endif //MUSIC_MAINWINDOW_H
