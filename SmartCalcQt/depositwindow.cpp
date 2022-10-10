#include "depositwindow.h"
#include "ui_depositwindow.h"
#include "mainwindow.h"






/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





/*     Конструктор класса 'DepositWindow'     */
DepositWindow::DepositWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepositWindow) {
    ui->setupUi(this);

    ui->comboBox_add_money->setVisible(false);
    ui->comboBox_sub_money->setVisible(false);

    ui->lineEdit_add_money->setVisible(false);
    ui->lineEdit_sub_money->setVisible(false);
    ui->pushButton_close_add_money->setVisible(false);
    ui->pushButton_close_sub_money->setVisible(false);

    ui->comboBox_rate_of_payment->addItem("Раз в месяц");
    ui->comboBox_rate_of_payment->addItem("Раз в три месяца");
    ui->comboBox_rate_of_payment->addItem("Раз в полгода");
    ui->comboBox_rate_of_payment->addItem("Раз в год");

    ui->comboBox_time->addItem("месяцев");
    ui->comboBox_time->addItem("лет");

    ui->checkBox->animateClick();
}





/*     Деструктор класса 'DepositWindow'     */
DepositWindow::~DepositWindow() {
    delete ui;
}





/*     Функция закрывает окно депозитного калькулятора     */
/*     и открывает главное окно класса 'MainWindow'        */
void DepositWindow::on_pushButton_back_clicked() {
    close_add_sub_visible();
    emit firstWindow();
    this->close();
}





/*      Функция принимает и отправляет параметры в структуры      */
/*      из s21_Engine.h и использует функцию calculate_deposit    */
/*      Можно было конечно сделать и без костылей но мне лень     */
void DepositWindow::on_pushButton_calculate_deposit_clicked() {
    setlocale(LC_NUMERIC, "C");
    s21_deposit_into_t *deposit_input = (s21_deposit_into_t *)calloc(
                1, sizeof(s21_deposit_into_t));
    s21_deposit_out_t *deposit_output = nullptr;

    deposit_input->deposit_amount = ui->lineEdit_amount_money->text().toDouble();
    deposit_input->rate_of_exchange = ui->lineEdit_rate_of_exchange->text().toDouble();

    if (ui->comboBox_time->currentIndex() == 0) deposit_input->placement_period = ui->lineEdit_time_replament->text().toInt();
    else if (ui->comboBox_time->currentIndex() == 1) deposit_input->placement_period = ui->lineEdit_time_replament->text().toInt() * 12;

    int currect_index_rate_of_payment = ui->comboBox_rate_of_payment->currentIndex();
    if (currect_index_rate_of_payment == 0) {
        deposit_input->repayment_period = 1;
    } else if (currect_index_rate_of_payment == 1) {
        deposit_input->repayment_period = 3;
    } else if (currect_index_rate_of_payment == 2) {
        deposit_input->repayment_period = 6;
    } else if (currect_index_rate_of_payment == 3) {
        deposit_input->repayment_period = 12;
    }

    if (ui->checkBox->checkState()) deposit_input->capitalization = CAPITALIZATION_ON;
    else deposit_input->capitalization = CAPITALIZATION_OFF;

    int current_index_cmbx_add_money = ui->comboBox_add_money->currentIndex();
    if (current_index_cmbx_add_money == 0) {
        deposit_input->partial_withdrawal_list[0] = ui->lineEdit_add_money->text().toDouble();
    } else if (current_index_cmbx_add_money == 1) {
        for (int i = 0; i < deposit_input->placement_period; i++) {
            deposit_input->partial_withdrawal_list[i] = ui->lineEdit_add_money->text().toDouble();
        }
    } else if (current_index_cmbx_add_money == 2) {
        for (int i = 0; i < deposit_input->placement_period; i+=3) {
            deposit_input->partial_withdrawal_list[i] = ui->lineEdit_add_money->text().toDouble();
        }
    } else if (current_index_cmbx_add_money == 3) {
        for (int i = 0; i < deposit_input->placement_period; i+=6) {
            deposit_input->partial_withdrawal_list[i] = ui->lineEdit_add_money->text().toDouble();
        }
    }

    int current_index_cmbx_sub_money = ui->comboBox_sub_money->currentIndex();
    if (current_index_cmbx_sub_money == 0) {
        deposit_input->list_of_interest_capitalisation[0] = ui->lineEdit_sub_money->text().toDouble();
    } else if (current_index_cmbx_sub_money == 1) {
        for (int i = 0; i < deposit_input->placement_period; i++) {
            deposit_input->list_of_interest_capitalisation[i] = ui->lineEdit_sub_money->text().toDouble();
        }
    } else if (current_index_cmbx_sub_money == 2) {
        for (int i = 0; i < deposit_input->placement_period; i+=3) {
            deposit_input->list_of_interest_capitalisation[i] = ui->lineEdit_sub_money->text().toDouble();
        }
    } else if (current_index_cmbx_sub_money == 3) {
        for (int i = 0; i < deposit_input->placement_period; i+=6) {
            deposit_input->list_of_interest_capitalisation[i] = ui->lineEdit_sub_money->text().toDouble();
        }
    }

    deposit_output = calculate_deposit(deposit_input);
    this->setFixedSize(600, 600);

    QString total_money = QString::number(deposit_output->total_sum);
    QString total_percent = QString::number(deposit_output->all_percent);
    QString total_tax = QString::number(deposit_output->sum_tax);
    QString total_amount_profit = QString::number(deposit_output->amount_profit);

    ui->label_total_money->setText(total_money + " руб.");
    ui->label_total_percent->setText(total_percent + " %");
    ui->label_total_tax->setText(total_tax + " руб.");
    ui->label_amount_profit->setText(total_amount_profit + " руб.");

    free(deposit_input);
    free(deposit_output);
    close_add_sub_visible();
}




void DepositWindow::on_pushButton_close_clicked() {
    this->setFixedSize(600, 400);
    close_add_sub_visible();

}






void DepositWindow::on_pushButton_add_money_clicked() {

    if (!is_clicked_add) {
        is_clicked_add = true;
        if (!is_clicked_sub) this->setFixedSize(this->width() + 50, this->height());
        ui->comboBox_add_money->setVisible(true);
        ui->lineEdit_add_money->setVisible(true);
        ui->pushButton_close_add_money->setVisible(true);
    }

}






void DepositWindow::on_pushButton_close_add_money_clicked()
{
    if (is_clicked_add) {
        is_clicked_add = false;
        if (!is_clicked_sub) this->setFixedSize(this->width() - 50, this->height());
        ui->comboBox_add_money->setVisible(false);
        ui->lineEdit_add_money->setVisible(false);
        ui->pushButton_close_add_money->setVisible(false);
    }
}






void DepositWindow::on_pushButton_sub_money_clicked()
{
    if (!is_clicked_sub) {
        is_clicked_sub = true;
        if (!is_clicked_add) this->setFixedSize(this->width() + 50, this->height());
        ui->comboBox_sub_money->setVisible(true);
        ui->lineEdit_sub_money->setVisible(true);
        ui->pushButton_close_sub_money->setVisible(true);
    }
}






void DepositWindow::on_pushButton_close_sub_money_clicked()
{
    if (is_clicked_sub) {
        is_clicked_sub = false;
        if (!is_clicked_add) this->setFixedSize(this->width() - 50, this->height());
        ui->comboBox_sub_money->setVisible(false);
        ui->lineEdit_sub_money->setVisible(false);
        ui->pushButton_close_sub_money->setVisible(false);
    }
}






void DepositWindow::close_add_sub_visible() {
    ui->comboBox_add_money->setVisible(false);
    ui->comboBox_sub_money->setVisible(false);

    ui->lineEdit_add_money->setVisible(false);
    ui->lineEdit_add_money->setText("0");
    ui->lineEdit_sub_money->setVisible(false);
    ui->lineEdit_sub_money->setText("0");
    ui->pushButton_close_add_money->setVisible(false);
    ui->pushButton_close_sub_money->setVisible(false);

    is_clicked_add = false;
    is_clicked_sub = false;
}
