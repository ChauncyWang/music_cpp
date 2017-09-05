//
// Created by chava on 17-9-5.
//

#include "Awesome.h"

QString awesome(int size, char *color) {
    char qss[200];
    char *awesome_qss = (char *) "font: %dpx 'FontAwesome';color:#%s;";
    sprintf(qss, awesome_qss, size, color);
    return QString(qss);
}

QString awesomeCircle(int size, int borderRadius, int paddingLeft, char *color, char *borderColor) {

    char *awesome_qss = (char *) "font: %dpx 'FontAwesome';color:#%s;"
            "border: 2px solid #%s;border-radius:%dpx;padding-left:%dpx";
    char qss[200];
    sprintf(qss, awesome_qss, size, color, borderColor, borderRadius, paddingLeft);
    return QString(qss);
}