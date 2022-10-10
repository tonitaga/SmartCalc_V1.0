#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QWidget>





/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





namespace Ui {
class DepositWindow;
}

class DepositWindow : public QWidget {
    Q_OBJECT

public:
    explicit DepositWindow(QWidget *parent = nullptr);
    ~DepositWindow();

signals:
    void firstWindow();
private slots:
    void on_pushButton_back_clicked();
    void on_pushButton_calculate_deposit_clicked();
    void on_pushButton_close_clicked();
    void on_pushButton_add_money_clicked();
    void on_pushButton_close_add_money_clicked();
    void on_pushButton_sub_money_clicked();
    void on_pushButton_close_sub_money_clicked();

private:
    Ui::DepositWindow *ui;
    bool is_clicked_add = false;
    bool is_clicked_sub = false;
    void close_add_sub_visible();
};

#endif // DEPOSITWINDOW_H
