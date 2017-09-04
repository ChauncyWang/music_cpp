//
// Created by hy on 17-9-4.
//

#include <QtGui/QPainter>
#include "ProgressBar.h"

ProgressBar::ProgressBar(QWidget *parent):QFrame(parent) {
    setMouseTracking(true);
    int color;
    sscanf("A0FF0066","%x",&color);
    in_color = QColor::fromRgba((QRgb) color);
}

void ProgressBar::updateRate(QMouseEvent *event) {
    int x = event->x();
    if (x > out_radius && loaded) {
        if (x < width()-out_radius) {
            rate = (x - out_radius) * 1.0 /(width() - 2 * out_radius);
            emit rateChanged(rate);
            update();
        }
    }
}

void ProgressBar::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    int d_r = out_radius - in_radius;
    int w = width() - 2 * out_radius;

    QPainter painter(this);
    //平滑绘制防锯齿
    painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::Antialiasing);

    QColor c1,c2;
    if (loaded) {
        c1 = load_color;
        c2 = in_color;
    } else {
        c1 = base_color;
        c2 = load_color;
    }

    painter.setPen(Qt::NoPen);
    //绘制进度条背景
    painter.setBrush(c1);
    QRectF rect = QRectF(d_r,d_r,w + 2 * in_radius,2 * in_radius);
    painter.drawRoundedRect(rect,in_radius,in_radius);
    // 绘制进度条
    painter.setBrush(c2);
    rect = QRectF(d_r,d_r,w * rate + 2 * in_radius,2*in_radius);
    painter.drawRoundedRect(rect,in_radius,in_radius);

    if (loaded) {
        // 绘制进度条节点外圆
        painter.setBrush(out_color);
        painter.drawEllipse((int) (w * rate), 0, 2 * out_radius, 2 * out_radius);
        // 绘制进度条节点内圆
        painter.setBrush(in_color);
        painter.drawEllipse((int) (w * rate + d_r), d_r, 2 * in_radius, 2 * in_radius);

    }

}

void ProgressBar::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    clicked = true;
}

void ProgressBar::mouseReleaseEvent(QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);
    clicked = false;
}

void ProgressBar::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
    if (clicked) {
        updateRate(event);
    }
}

void ProgressBar::enterEvent(QEvent *event) {
    QWidget::enterEvent(event);
    if (loaded) {
        setCursor(Qt::PointingHandCursor);
    }
}
