#define _S21_DEPOSIT_CALCULATOR_SUPPORT_FUNCTIONS
#include "s21_Calculate.h"







/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/






s21_deposit_out_t *calculate_deposit(s21_deposit_into_t *deposit_input) {
    s21_deposit_out_t *deposit_output = (s21_deposit_out_t *) calloc(1, sizeof (s21_deposit_out_t));
    deposit_output->f_result = OK;
    if (deposit_output->f_result) {
        Data_lf new_deposit_amount = deposit_input->deposit_amount;
        Data_d  times_of_payment = deposit_input->placement_period / deposit_input->repayment_period;
        Data_lf placement_period_in_years = deposit_input->placement_period / 12.0;
        Data_lf new_rate_of_exchange = deposit_input->rate_of_exchange *
                                       placement_period_in_years / times_of_payment;


        Data_lf exchange = 1 + new_rate_of_exchange / 100;
        Data_d  movie = deposit_input->placement_period / times_of_payment;
        Data_lf total_partial_withdrawal = 0.0;
        Data_lf total_interest_capitalisation = 0.0;
        for (size_t i = 0; i < (size_t)deposit_input->placement_period; i++) {
            if (deposit_input->partial_withdrawal_list[i] != 0.0) {
                new_deposit_amount += deposit_input->partial_withdrawal_list[i];
                total_partial_withdrawal += deposit_input->partial_withdrawal_list[i];
            }
            if (deposit_input->list_of_interest_capitalisation[i] != 0.0) {
                if (deposit_input->list_of_interest_capitalisation[i] > new_deposit_amount) {
                    deposit_output->f_result = ERROR;
                } else {
                    new_deposit_amount -= deposit_input->list_of_interest_capitalisation[i];
                    total_interest_capitalisation += deposit_input->list_of_interest_capitalisation[i];
                }
            }
            if (i % movie == 0) {
                new_deposit_amount = new_deposit_amount * exchange;
            }
        }

        if (deposit_input->capitalization == CAPITALIZATION_ON) {
            deposit_output->all_percent =
                    ((new_deposit_amount - total_partial_withdrawal + total_interest_capitalisation) /
                     deposit_input->deposit_amount - 1) * 100 / placement_period_in_years;
            deposit_output->total_sum = new_deposit_amount;
            deposit_output->amount_profit = new_deposit_amount - deposit_input->deposit_amount -
                    total_partial_withdrawal + total_interest_capitalisation;
            deposit_tax(&deposit_output);
        } else {
            deposit_output->all_percent = deposit_input->rate_of_exchange;
            deposit_output->total_sum = deposit_input->deposit_amount;
            deposit_output->amount_profit = new_deposit_amount - deposit_input->deposit_amount;
            deposit_tax(&deposit_output);
        }



    } else {
        printf("Syntax error!\n");
    }
    return deposit_output;
}





/**
 *  https://clck.ru/sc6LZ
 *  @param limits - Проверка на превышение лимита на необлагаемый процентный доход.
 *           Чтобы рассчитать сумму, которая не облагается налогом,
 *           нужно умножить текущую ключевую ставку, установленную
 *           Центробанком РФ, на 1 миллион рублей
 *  @param result_tax - Рассчитать налог на вклад можно при помощи простой формулы:
 *               (факт. доход по вкладам — освобожденный от налога процентный доход) * 13%
 *               = сумма НДФЛ к уплате.
 */
void deposit_tax(s21_deposit_out_t **deposit_output) {
    double result_tax = 0;
    double profit = (*deposit_output)->amount_profit;

    double limits = 1000000 * 0.08;
    if (profit > limits) {
        result_tax = (profit - limits) * 0.13;
        (*deposit_output)->sum_tax = result_tax;
    } else {
        (*deposit_output)->sum_tax = 0.0;
    }
}
