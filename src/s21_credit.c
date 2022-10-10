#define _S21_CREDIT_CALCULATOR_SUPPORT_FUNCTIONS
#define _S21_CALCULATOR_ENGINE_SUPPORT_FUNCTIONS
#include "s21_Calculate.h"






/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





s21_credit_out_t *calculate_credit(s21_credit_into_t *credit_input) {
    s21_credit_out_t *credit_output = (s21_credit_out_t *) calloc(1, sizeof (s21_credit_out_t));
    credit_output->f_result = general_credit_syntax_check(credit_input);
    if (credit_output->f_result) {
        if (credit_input->type == Annuity) {
            Data_lf procently = credit_input->rate_of_exchange / (100 * 12);
            credit_output->monthly_payment = credit_input->total_credit_sum *
                                (procently / (1 - pow(1 + procently, -credit_input->credit_period)));
            credit_output->total_payout = credit_output->monthly_payment * credit_input->credit_period;
            credit_output->overpayment = credit_output->total_payout - credit_input->total_credit_sum;
        } else if (credit_input->type == Differentiated) {
            credit_output->total_payout = 0.0;
            Data_lf monthly_payment = credit_input->total_credit_sum / credit_input->credit_period;
            for (int i = 0; i < credit_input->credit_period; i++) {
                credit_output->total_payout +=
                    monthly_payment + (credit_input->total_credit_sum - monthly_payment * i) *
                    (credit_input->rate_of_exchange / 100)/12;
            }
            credit_output->monthly_payment = credit_output->total_payout / credit_input->credit_period;
            credit_output->overpayment = credit_output->total_payout - credit_input->total_credit_sum;
        }
    } else {
        printf("Syntax error!\n");
        credit_output->f_result = ERROR;
    }
    return credit_output;
}




/*      Нужна доработка     */
Data_d general_credit_syntax_check(s21_credit_into_t *credit_input) {
    int f_result = OK;
    char str1[255] = "", str2[255] = "", str3[255] = "";
    snprintf(str1, sizeof(str1), "%lf", credit_input->total_credit_sum);
    snprintf(str2, sizeof(str2), "%lf", credit_input->rate_of_exchange);
    snprintf(str3, sizeof(str3), "%d", credit_input->credit_period);
    for (size_t i = 0; i < strlen(str1); i++) {
        if (!this_is_digit(str1[i])) {
            f_result = ERROR;
            break;
        }
    }
    if (f_result == OK) {
        for (size_t i = 0; i < strlen(str2); i++) {
            if (!this_is_digit(str2[i])) {
                f_result = ERROR;
                break;
            }
        }
    }
    if (f_result == OK) {
        for (size_t i = 0; i < strlen(str3); i++) {
            if (!this_is_digit(str3[i])) {
                f_result = ERROR;
                break;
            }
        }
    }
    return f_result;
}
