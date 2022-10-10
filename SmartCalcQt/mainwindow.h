#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <clocale>
#include "depositwindow.h"
#include "creditwindow.h"
#include <cstring>
#include <QVector>
#include <QTimer>









/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





extern "C" {
    #include "../src/s21_Calculate.h"
    #include "../src/s21_Engine.h"
    #include "../src/s21_Stack.h"
}




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void firstWindow();
private slots:
    void digits_and_operations();
    void trigonometry();
    void on_pushButton_delete_all_clicked();
    void on_pushButton_pow_clicked();
    void on_pushButton_percent_clicked();
    void on_pushButton_delete_one_clicked();
    void on_pushButton_deposit_clicked();
    void on_pushButton_graph_clicked();
    void on_pushButton_calculate_clicked();
    void on_pushButton_X_clicked();
//    void on_pushButton_close_bracket_clicked();
//    void on_pushButton_open_bracket_clicked();
    void on_pushButton_make_graph_clicked();
    void on_pushButton_credit_clicked();

private:
    Ui::MainWindow *ui;

    void check_is_start();
    int  the_x_in_str();

    bool is_start = true;
    bool is_graph = false;
    bool is_graph_builded = false;

    int count_taps_on_mak_graph = 0;
    double x, x_max = 10, x_min = -10, y_max = 10, y_min = -10, step;
    int points;
    QVector<double> x_vec, y_vec;
    QTimer *timer;
    int time;

    DepositWindow *Deposit;
    CreditWindow *Credit;
    void keyPressEvent(QKeyEvent *e);
};

#endif // MAINWINDOW_H
