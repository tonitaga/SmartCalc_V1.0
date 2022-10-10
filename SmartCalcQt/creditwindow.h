#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QWidget>





/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





namespace Ui {
class CreditWindow;
}

class CreditWindow : public QWidget {
    Q_OBJECT

public:
    explicit CreditWindow(QWidget *parent = nullptr);
    ~CreditWindow();

private slots:
    void on_pushButton_back_clicked();
    void on_pushButton_close_clicked();
    void on_pushButton_calculate_credit_clicked();

signals:
    void firstWindow();

private:
    Ui::CreditWindow *ui;
};

#endif // CREDITWINDOW_H
