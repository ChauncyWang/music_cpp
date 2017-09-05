//
// Created by chava on 17-9-5.
//

#ifndef MUSIC_PLAYBAR_H
#define MUSIC_PLAYBAR_H


#include <QtWidgets/QFrame>
#include <QMouseEvent>

#include "WButton.h"

/**
 * 播放进度条
 */
class ProgressBar : public QFrame {
Q_OBJECT
public:
    /**
     * 构造函数
     * @param parent 父控件
     */
    ProgressBar(QWidget *parent = NULL);

public slots:

    /**
     * 重新计算进度百分比
     * @param event 鼠标点击的事件
     */
    void updateRate(QMouseEvent *event);

signals:

    /**
     * 进度百分比改变的信号
     * @param value 进度百分比
     */
    void rateChanged(double value);

protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void enterEvent(QEvent *event) override;

private:
    bool clicked = false;
    double rate = 0;
    bool loaded = true;

    int in_radius = 3;
    int out_radius = 10;

    QColor base_color = QColor(255, 255, 255);
    QColor load_color = QColor(180, 180, 180);
    QColor in_color;
    QColor out_color = QColor(255, 255, 255);
};


class PlayBar : public QFrame {
Q_OBJECT

public:
    PlayBar(QWidget *parent = NULL);

public slots:
signals:

protected:
    void resizeEvent(QResizeEvent *event) override;

private:

    WButton *btn_pre;
    WButton *btn_play;
    WButton *btn_next;

    ProgressBar* progressBar;
};


#endif //MUSIC_PLAYBAR_H
