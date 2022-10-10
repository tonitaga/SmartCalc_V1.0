#ifndef SRC_S21_ENGINE_H_
#define SRC_S21_ENGINE_H_







/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





/*     Для работы правильной работы нужен s21_Stack.h     */
#include "s21_Stack.h"





/*===============================================================/
/                                                                /
/          БЛОК ФУНКЦИЙ РЕАЛИЗАЦИИ НАХОЖДЕНИЯ ОТВЕТА             /
/                                                                /
/===============================================================*/





/*     Main functions     */
int         calculate(char *str, double *result, double x);





/*     Support functions     */
#if defined _S21_CALCULATOR_ENGINE_SUPPORT_FUNCTIONS

int         get_math_expression(char *str, size_t *i, s21_Stack_t **list);
void        expression_to_polish_notation(char *str, Data_lf *f_result, Data_lf X);
void        prepare_expression(char *str);
void        calculate_trigonometry(Data_lf value, value_type_t type_t, s21_Stack_t **list);
void        calculate_operation(Data_lf first_value, Data_lf second_value,
                                value_type_t type_t, s21_Stack_t **list);
double      calculate_expression(s21_Stack_t *list, Data_lf *f_result);

int         this_is_digit(int token);
int         this_is_sign(int token);
int         this_is_function(int token);
int         the_x_in_str(const char *str);

int         get_priority(int token);
void        set_priority(s21_Stack_t **list);

int         general_syntax_test(const char *str);


#define CORRECT 0
#define INCORRECT 1

typedef struct symbol {
    char c;
    int count;
} symbol;


typedef struct epres_count {
    int cos_c;
    int sin_c;
    int tan_c;
    int acos_c;
    int asin_c;
    int sqrt_c;
    int ln_c;
    int log_c;
} count_t;

void first_wave(char *str, int *err);
void found_symbol(char *array, char to_found, int *flag);
void staples_smart(char *str, int *err);
void expressions(char *str, int *err);
void ind_plus(char symbol, char symbol_2, int *index);
void operators(char *str, int *err);

void triginomenty_check(char *str, int *err);

#endif  // *_S21_CALCULATOR_ENGINE_SUPPORT_FUNCTIONS





/*===============================================================/
/                                                                /
/        БЛОК ФУНКЦИЙ РЕАЛИЗАЦИИ КРЕДИТНОГО КАЛЬКУЛЯТОРА         /
/                                                                /
/===============================================================*/





typedef enum {
    Annuity,
    Differentiated
} credit_type_t;





/**
 * @param s21_credit_into_t - структура выходных данных кредитного калькулятора 
 * @param total_credit_sum       общая сумма кредита
 * @param credit_period          срок кредита
 * @param rate_of_exchange       процентная ставка
 * @param type тип [1 - Differentiated, 0 - Annuity]
 */
typedef struct {
    Data_lf total_credit_sum;
    Data_d  credit_period;
    Data_lf rate_of_exchange;
    credit_type_t type;
} s21_credit_into_t;





/**
 * @param s21_credit_out_t - структура выходных данных кредитного калькулятора
 * @param monthly_payment       ежемесячный платеж
 * @param total_payout          общая выплата
 * @param overpayment           переплата по кредиту
 * @param f_result - доп переменная для отслеживания успешности калькулирования
 */
typedef struct {
    Data_lf monthly_payment;
    Data_lf total_payout;
    Data_lf overpayment;
    Data_d  f_result;
} s21_credit_out_t;





/*     Main functions     */
s21_credit_out_t *calculate_credit(s21_credit_into_t *credit_input);





/*     Support functions     */
#if defined _S21_CREDIT_CALCULATOR_SUPPORT_FUNCTIONS

Data_d                  general_credit_syntax_check(s21_credit_into_t *credit_input);

#endif  // !_S21_CREDIT_CALCULATOR_SUPPORT_FUNCTIONS





/*===============================================================/
/                                                                /
/        БЛОК ФУНКЦИЙ РЕАЛИЗАЦИИ ДЕПОЗИТНОГО КАЛЬКУЛЯТОРА        /
/                                                                /
/===============================================================*/





#define CAPITALIZATION_ON 1
#define CAPITALIZATION_OFF 0





/**
 *  @param s21_deposit_into_t - структура входных данных депозитного калькулятора
 *  @param deposit_amount                        сумма вклада
 *  @param placement_period                      срок размещения
 *  @param rate_of_exchange                      процентная ставка
 *  @param tax_rate                              налоговая ставка
 *  @param repayment_period                      периодичность выплат
 *  @param capitalization                        капитализация процентов [1 - YES, 0 - NO]
 *  @param partial_withdrawal_list               список пополнений
 *  @param list_of_interest_capitalisation       список частичных снятий
 */
typedef struct {
    Data_lf deposit_amount;
    Data_d  placement_period;
    Data_lf rate_of_exchange;
    Data_lf tax_rate;
    Data_d  repayment_period;
    Data_d  capitalization;
    Data_lf partial_withdrawal_list[255];
    Data_lf list_of_interest_capitalisation[255];
} s21_deposit_into_t;





/**
 *  @param s21_deposit_out_t - структура для возвращения ответа депозитного калькулятора
 *  @param all_percent       начисленные проценты
 *  @param sum_tax           сумма налога
 *  @param total_sum         сумма на вкладе к концу срока
 *  @param f_result - доп переменная для отслеживания успешности калькулирования
 */
typedef struct {
    Data_lf all_percent;
    Data_lf sum_tax;
    Data_lf total_sum;
    Data_d  f_result;
    Data_lf amount_profit;
} s21_deposit_out_t;





/*     Main functions     */
s21_deposit_out_t *     calculate_deposit(s21_deposit_into_t *deposit_input);





/*     Support functions     */
#if defined _S21_DEPOSIT_CALCULATOR_SUPPORT_FUNCTIONS

// Data_d                  general_deposit_syntax_check(s21_deposit_into_t *deposit_input);
void                    deposit_tax(s21_deposit_out_t **deposit_output);

#endif  // !_S21_DEPOSIT_CALCULATOR_SUPPORT_FUNCTIONS





#endif  // SRC_S21_ENGINE_H_
