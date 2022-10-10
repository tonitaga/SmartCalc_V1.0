#include "mainwindow.h"
#include <QApplication>







/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Calculator");
    w.setFixedSize(400, 400);
    w.show();

    return a.exec();
}
