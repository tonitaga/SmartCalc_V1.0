#include "creditwindow.h"
#include "ui_creditwindow.h"

#include "mainwindow.h"





/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





/*     Конструктор класса 'CreditWindow'     */
CreditWindow::CreditWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditWindow) {
    ui->setupUi(this);

    ui->comboBox_credit_type->addItem("Аннуитетный");
    ui->comboBox_credit_type->addItem("Дифференцированный");

    ui->comboBox_time->addItem("месяцев");
    ui->comboBox_time->addItem("лет");
}





/*     Деструктор класса 'CreditWindow'     */
CreditWindow::~CreditWindow() {
    delete ui;
}





/*     Функция закрывает окно кредитного калькулятора      */
/*     и открывает главное окно класса 'MainWindow'        */
void CreditWindow::on_pushButton_back_clicked() {
    emit firstWindow();
    this->close();
}





/*      Функция принимает и отправляет параметры в структуры      */
/*      из s21_Engine.h и использует функцию calculate_credit     */
/*      Можно было конечно сделать и без костылей но мне лень     */
void CreditWindow::on_pushButton_calculate_credit_clicked() {
   setlocale(LC_NUMERIC, "C");
   s21_credit_into_t *credit_input = (s21_credit_into_t *)calloc(1, sizeof(s21_credit_into_t));
   s21_credit_out_t  *credit_output = nullptr;

   credit_input->total_credit_sum = ui->lineEdit_credit_money->text().toDouble();
   credit_input->rate_of_exchange = ui->lineEdit_rate_of_exchange->text().toDouble();
   if (ui->comboBox_time->currentIndex() == 0) {
       credit_input->credit_period = ui->lineEdit_time_replament->text().toDouble();
   } else{
       credit_input->credit_period = ui->lineEdit_time_replament->text().toInt() * 12;
   }

   int index = ui->comboBox_credit_type->currentIndex();
   if (index == 0) {
       credit_input->type = Annuity;
   } else {
       credit_input->type = Differentiated;
   }

   credit_output = calculate_credit(credit_input);
   this->setFixedSize(600, 600);

   QString total_monthly_payment = QString::number(credit_output->monthly_payment);
   QString total_payment = QString::number(credit_output->total_payout);
   QString total_overpay = QString::number(credit_output->overpayment);

   ui->label_total_payment->setText(total_payment + " руб.");
   ui->label_total_monthly_payment->setText(total_monthly_payment + " руб.");
   ui->label_total_above_payment->setText(total_overpay + " руб.");
}




void CreditWindow::on_pushButton_close_clicked() {
    this->setFixedSize(600, 400);
}
