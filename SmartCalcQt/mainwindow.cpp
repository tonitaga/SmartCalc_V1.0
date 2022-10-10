#include "mainwindow.h"
#include "ui_mainwindow.h"







/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





/*     Конструктор класса 'MainWindow'     */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->pushButton_zero, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_two, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_three, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_four, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_five, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_six, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_seven, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_eigth, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_nine, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this, SLOT(digits_and_operations()));
    connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this, SLOT(digits_and_operations()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(trigonometry()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(trigonometry()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(trigonometry()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(trigonometry()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(trigonometry()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(trigonometry()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(trigonometry()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(trigonometry()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(trigonometry()));

    Deposit = new DepositWindow();
    connect(Deposit, &DepositWindow::firstWindow, this, &MainWindow::show);
    Credit = new CreditWindow();
    connect(Credit, &CreditWindow::firstWindow, this, &MainWindow::show);


    /*  Позволяет зумить и двигать график   */
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
}





/*     Деструктор класса 'MainWindow'     */
MainWindow::~MainWindow() {
    delete ui;
}





/*     Функция вызывающая и рассчитывающая выражение из ui->label_result,     */
/*     используя функцию calculate из s21_Engine.c                            */
void MainWindow::on_pushButton_calculate_clicked() {
    setlocale(LC_NUMERIC, "C");
    if (!the_x_in_str()) {
        std::string tmp = ui->label_result->text().toStdString();
        const char *str = tmp.c_str();
        double result = 0.0;
        QString result_t;
        if (calculate((char *)str, &result, 0.0)) {
            result_t = QString::number(result);
            ui->label_result->setText(result_t);
        } else {
            ui->label_result->clear();
            ui->label_result->setText("Syntax error!");
            is_start = true;
        }
    }
}





/*     Функция, которая занимается построением графика в ui->widget,     */
/*     используя функцию calculate из s21_Engine.c                       */
void MainWindow::on_pushButton_make_graph_clicked() {
    is_graph_builded = false;
    timer = new QTimer(this);
    ui->widget->clearGraphs();
    time = 0;
    timer->start(20);
    x = x_min;
    x_vec.clear();
    y_vec.clear();

    if (the_x_in_str()) {
        std::string tmp = ui->label_result->text().toStdString();
        const char *str = tmp.c_str();

        x_min = ui->lineEdit_x_min->text().toDouble();
        x_max = ui->lineEdit_x_max->text().toDouble();

        if (x_min == 0.0) x_min = -10;
        if (x_max == 0.0) x_max = 10;

        step = 0.1;
        points = (fabs(x_min) + fabs(x_max)) / 0.1 + 2;
        ui->widget->xAxis->setRange(x_min, x_max);
        ui->widget->yAxis->setRange(-5, 5);

        double result = 0.0;
        int f = 1;
        for (x = x_min; x <= x_max && f == 1; x += step) {
            if (calculate((char *)str, &result, x)) {
                f = 1;
                x_vec.push_back(x);
                y_vec.push_back(result);
            } else {
                f = 0;
                ui->label_result->setText("Syntax error!");
                break;

            }
        }
        if (f == 1) {
            QPen pen;
            pen.setColor(QColor(0, 0, 0));
            ui->widget->addGraph()->setPen(pen);
            ui->widget->graph(0)->addData(x_vec, y_vec);
            ui->widget->replot();
        }
    }
}





/*     Убирает начальный нолик со строки     */
void MainWindow::check_is_start() {
    if (is_start) {
        ui->label_result->clear();
        is_start = false;
    }
}





/*     Проверяет наличие 'x' в ui->label_result     */
int MainWindow::the_x_in_str() {
    int f_result = 0;
    std::string tmp = ui->label_result->text().toStdString();
    std::string syntax_error = "Syntax error!";
    if (tmp == syntax_error) {
        ui->label_result->setText("0");
        is_start = true;
    } else {
        const char *str = tmp.c_str();
        for (size_t i = 0; i < strlen(str); i++) {
            if (str[i] == 'x') {
                f_result = 1;
                break;
            }
        }
    }
    return f_result;
}





void MainWindow::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Return) {
        if(!the_x_in_str()) {
            on_pushButton_calculate_clicked();
        } else {
            on_pushButton_make_graph_clicked();
        }
    }
}





/*     Функция выводит в ui->label_result текст с кнопок цифр и операций     */
void MainWindow::digits_and_operations() {
    QPushButton *button = (QPushButton *)sender();
    check_is_start();
    QString tmp;
    if (button->text() == "÷") {
        tmp = (ui->label_result->text() + "/");
    } else if (button->text() == "×") {
        tmp = (ui->label_result->text() + "*");
    } else {
        tmp = (ui->label_result->text() + button->text());
    }
    ui->label_result->setText(tmp);
}





/*     Функция выводит в ui->label_result текст с кнопок,             */
/*     отвечающих за тригонометрические функции с добавлением '('     */
void MainWindow::trigonometry() {
    QPushButton *button = (QPushButton *)sender();
    check_is_start();
    QString tmp;
    tmp = (ui->label_result->text() + button->text() + "(");
    ui->label_result->setText(tmp);
}





/*     Удаляет все с ui->label_result и вставляет нолик     */
void MainWindow::on_pushButton_delete_all_clicked() {
    ui->label_result->clear();
    ui->label_result->setText("0");
    is_start = true;
}





/*     Вывод операции возведения в степень в ui->label_result     */
void MainWindow::on_pushButton_pow_clicked() {
    check_is_start();
    ui->label_result->setText(ui->label_result->text() + "^");
}





/*     Функция высчитывающая процент от числа     */
void MainWindow::on_pushButton_percent_clicked() {
    double value = ui->label_result->text().toDouble() * 0.01;
    QString tmp = QString::number(value);
    ui->label_result->setText(tmp);
}





/*     Функция последний элемент в ui->label_result     */
void MainWindow::on_pushButton_delete_one_clicked() {
    std::string str= ui->label_result->text().toStdString();
    if (!str.empty()) {
        str.erase(str.size() - 1);
    }
    QString tmp;
    if (str.empty()) {
        tmp = QString::fromStdString(str + "0");
        is_start = true;
    } else {
        tmp = QString::fromStdString(str);
    }
    ui->label_result->setText(tmp);
}





/*     Функция открывает окно отвечающее за депозитный калькулятор     */
void MainWindow::on_pushButton_deposit_clicked() {
    Deposit->show();
    Deposit->setFixedSize(600, 400);
    Deposit->setWindowTitle("Deposit calculator");
    this->close();
}





/*     Функция открывает дополнительное место в основном окне,     */
/*     где будет строиться график                                  */
void MainWindow::on_pushButton_graph_clicked() {
    if (!is_graph) {
        this->setFixedSize(1000, 400);
        is_graph = true;
    } else {
        this->setFixedSize(400, 400);
        is_graph = false;
    }
}






/*     Функция выводит в ui->label_result 'x'     */
void MainWindow::on_pushButton_X_clicked() {
    check_is_start();
    ui->label_result->setText(ui->label_result->text() + "x");
}





/*     Функция открывает окно отвечающее за кредитный калькулятор     */
void MainWindow::on_pushButton_credit_clicked() {
    Credit->show();
    Credit->setFixedSize(600, 400);
    Credit->setWindowTitle("Credit calculator");
    this->close();
}
