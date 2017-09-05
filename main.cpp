//
// Created by hy on 17-9-1.
//

#include <iostream>
#include <python3.5/Python.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtGui/QFontDatabase>
#include "cpp/components/MainWindow.h"
// https://www.oschina.net/translate/how-to-write-vim-plugins-with-python
using namespace std;

int main(int argc, char **argv) {

    QApplication app(argc, argv);
    if (QFontDatabase::addApplicationFont("res/font/fontawesome-webfont.ttf") == -1) {
        cout << "字体库加载失败!" << endl;
    } else {
        cout << "字体库加载成功!" << endl;
    }
    MainWindow mainWindow(&app);
    mainWindow.show();
    return app.exec();
}
