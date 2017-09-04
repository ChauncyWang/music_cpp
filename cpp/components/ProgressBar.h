//
// Created by hy on 17-9-4.
//

#ifndef MUSIC_PROGRESSBAR_H
#define MUSIC_PROGRESSBAR_H


#include <QtWidgets/QFrame>
#include <QMouseEvent>

class ProgressBar: public QFrame {
Q_OBJECT
public:
    /**
     * 构造函数
     * @param parent 父控件
     */
    ProgressBar(QWidget *parent=NULL);

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

    QColor base_color = QColor(255,255,255);
    QColor load_color = QColor(180,180,180);
    QColor in_color;
    QColor out_color = QColor(255,255,255);
};


#endif //MUSIC_PROGRESSBAR_H
