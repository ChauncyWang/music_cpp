//
// Created by hy on 17-9-4.
//

#ifndef MUSIC_TITLEBAR_H
#define MUSIC_TITLEBAR_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QMouseEvent>
#include <QtWidgets/QMainWindow>
#include "WButton.h"

/**
 * 因为主窗体未使用系统窗体修饰，故用此作为标题栏
 */
class TitleBar : public QFrame {
Q_OBJECT
public:
    TitleBar(QWidget *parent = NULL);

public slots:

    void search();

signals:

    /**
     * 退出信号
     */
    void quit();

    /**
     * 最小化信号
     */
    void minimized();

    /**
     * 最大化信号
     */
    void maximized();

    /**
     * 搜索信号
     * @param content 要搜索的内容
     */
    void search(QString content);

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

private:
    bool clicked = false;
    WButton *btn_search;
    WButton *btn_min;
    WButton *btn_max;
    WButton *btn_close;
    QLineEdit *input;
    QPoint pos;
};


#endif //MUSIC_TITLEBAR_H
