//
// Created by hy on 17-9-4.
//

#include "TitleBar.h"
#include "Awesome.h"
#include "iostream"

using namespace std;

/**
 * 构造函数
 * @param parent 父控件
 */
TitleBar::TitleBar(QWidget *parent) : QFrame(parent) {
    char qss[200];
    sprintf(qss, awesome_qss, 20, "80FF00FF");

    // 搜索框
    input = new QLineEdit(this);
    input->setGeometry(20, 5, 150, 30);
    input->setStyleSheet("color:#FFFFFF;border:1px solid;border-radius:15px;"
                                 "background-color:#80808080;padding-left:10px;");
    // 搜索按钮
    btn_search = new WButton(this);
    btn_search->setText(icon_search);
    btn_search->setGeometry(180, 5, 30, 30);
    btn_search->setStyleSheet(qss);
    // 最小化按钮
    btn_min = new WButton(this);
    btn_min->setText(icon_chevron_down);
    btn_min->setStyleSheet(qss);
    // 最大化按钮
    btn_max = new WButton(this);
    btn_max->setText(icon_chevron_up);
    btn_max->setStyleSheet(qss);
    // 关闭按钮
    btn_close = new WButton(this);
    btn_close->setText(icon_remove);
    btn_close->setStyleSheet(qss);

    // 传递信号
    connect(btn_close, SIGNAL(press()), this, SIGNAL(quit()));
    connect(btn_min, SIGNAL(press()), this, SIGNAL(minimized()));
    connect(btn_max, SIGNAL(press()), this, SIGNAL(maximized()));
    connect(btn_search,SIGNAL(press()),this,SLOT(search()));
}

void TitleBar::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    clicked = true;
    pos = event->pos();
}


void TitleBar::mouseReleaseEvent(QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);
    clicked = false;
}

void TitleBar::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
    if (clicked) {
        QWidget *p = ((QWidget *) parent());
        QPoint point = p->pos();
        int x = event->x() - pos.x() + point.x();
        int y = event->y() - pos.y() + point.y();
        p->setGeometry(x, y, p->width(), p->height());
    }
}

void TitleBar::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    btn_min->setGeometry(width() - 90, 10, 30, 20);
    btn_max->setGeometry(width() - 60, 10, 30, 20);
    btn_close->setGeometry(width() - 30, 10, 30, 20);
}

void TitleBar::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);
    if (event -> key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        search();
    }
}

void TitleBar::search() {
    emit search(input->text());
}