#define _S21_CALCULATOR_PRINTF_FUNCTIONS
#define _S21_CALCULATOR_ENGINE_SUPPORT_FUNCTIONS
#include "s21_Calculate.h"






/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/






/*------------------------------------------------------*/
/*      ЧТО НУЖНО СДЕЛАТЬ В ЭТОМ ФАЙЛЕ?                 */
/*      1) НУЖНО РЕАЛИЗОВАТЬ ПАРСЕР И ПРОВЕРКУ НА       */
/*      КОРРЕКТНОСТЬ ПОДАННОЙ СТРОКИ                    */
/*      2) ПЕРЕВЕСТИ СТРОКУ В СТРОКУ ПРЕДСТАВЛЕННУЮ     */
/*      В ВИДЕ ОБРАТНОЙ ПОЛЬСКОЙ НОТАЦИИ                */
/*      3) ФУНКЦИЮ КОТОРАЯ БУДЕТ ПЕРЕВОДИТЬ ПОЛЬСКУЮ    */
/*      НОТАЦИЮ В ОТВЕТ ТИПА DOUBLE                     */
/*      4) НАПИСАТЬ ФУНКЦИИ УСТНАВЛИВАЮЩИЕ И            */
/*      ПРЕДОСТАВЛЯЮЩИЕ ПРИОРИТЕТ ЭЛЕМЕТНА СТРОКИ       */
/*      5) ФУНКЦИЮ ОПРЕДЕЛЯЮЩУЮ ЯВЛЯЕТСЯ ЛИ БУКВЫ       */
/*      В СТРОКЕ ТОЙ ИЛИ ИНОЙ МАТЕМАТИЧЕСКОЙ Ф-ЕЙ       */
/*      6) ФУНКЦИЯ ОПРЕДЕЛЯЮЩАЯ ЯВЛЯЕТСЯ ЛИ ЭЛЕМЕНТ     */
/*      СТРОКИ ЧИСЛОМ                                   */
/*      7) ФУНКЦИЯ ОПРЕДЕЛЯЮЩАЯ ЯВЛЯЕТСЯ ЛИ ЭЛЕМЕНТ     */
/*      СТРОКИ ЗНАКОМ                                   */
/*------------------------------------------------------*/
/*      ОСНОВНЫЕ ПОЛОЖЕНИЯ КОТОРЫЕ НУЖНО УЧЕСТЬ:        */
/*      1) НАУЧИТЬ ПАРСЕР ОТЛИЧАТЬ УНАРНЫЙ МИНУС        */
/*      ОТ ОБЫЧНОГО МИНУСА                              */
/*      2) УЧЕСТЬ ПРАВИЛЬНОЕ ВОЗВЕДЕНИЕ В СТЕПЕНЬ       */
/*      НАПРИМЕР: a) (2^2)^3 = 64 --> 22^3^             */
/*                b) 2^(2^3)  = 256 --> 223^^           */
/*      3) ЕСЛИ В СТРОКЕ ПОПАДАЕТСЯ ОБРАТНАЯ СКОБКА     */
/*      НУЖНО ВЫТАЩИТЬ ВСЕ ЗНАКИ НАХОДЯЩИЕСЯ ДО         */
/*      ОТКРЫТОЙ СКОБКИ                                 */
/*      В ДАЛЬНЕЙШЕЙ БУДУТ ЕЩЕ ДОБАВЛЕНИЯ 28.07.2022    */






int calculate(char *str, double *result, double x) {
    int f_result = OK;
    if (!general_syntax_test(str)) {
        prepare_expression(str);
        expression_to_polish_notation(str, result, x);
    } else {
        f_result = ERROR;
    }
    return f_result;
}



int the_x_in_str(const char *str) {
    int f_result = ERROR;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == 'x') {
            f_result = OK;
            break;
        }
    }
    return f_result;
}







void expression_to_polish_notation(char *str, Data_lf *result, Data_lf X) {
        s21_Stack_t *output_list = NULL;
        s21_Stack_t *function_list = NULL;

        for (size_t i = 0; i < strlen(str); i++) {
            if (str[i] == 'x') {
                push_data_lf(X, &output_list);
            } else if (this_is_digit(str[i])) {
                char *str_beg = &str[i];
                while (this_is_digit(str[i])) i++;
                char *str_end = &str[--i];
                double data_lf = strtod(str_beg, &str_end);
                push_data_lf(data_lf, &output_list);
                set_priority(&output_list);
            } else if (str[i] == '(') {
                push_data_d(str[i], &function_list);
                set_priority(&function_list);
            } else if (get_math_expression(str, &i, &function_list)) {
            } else if (this_is_sign(str[i])) {
                while (function_list != NULL && function_list->priority >= get_priority(str[i])) {
                    push_data_d(pop_data_d(&function_list), &output_list);
                    set_priority(&output_list);
                }
                push_data_d(str[i], &function_list);
                set_priority(&function_list);
            } else if (str[i] == ')') {
                while (function_list->data_d != '(') {
                    push_data_d(pop_data_d(&function_list), &output_list);
                    set_priority(&output_list);
                }
                pop_data_d(&function_list);
                if (!is_empty(function_list)) {
                    value_type_t type_t = peak_value_type_t(&function_list);
                    if (this_is_function(type_t)) {
                        push_value_type_t(pop_value_type_t(&function_list), &output_list);
                    }
                }
            }
        }
        while (!is_empty(function_list)) {
            value_type_t type_t = peak_value_type_t(&function_list);
            if (this_is_function(type_t)) {
                push_value_type_t(pop_value_type_t(&function_list), &output_list);
            } else {
                push_data_d(pop_data_d(&function_list), &output_list);
                set_priority(&output_list);
            }
        }
        calculate_expression(output_list, result);
        remove_stack(output_list);
        remove_stack(function_list);
}





double calculate_expression(s21_Stack_t *list, Data_lf *f_result) {
    s21_Stack_t *output_list = NULL;
    output_list = reverse_stack(list);
    s21_Stack_t *function_list = NULL;
    while (!is_empty(output_list)) {
        value_type_t type_t = peak_value_type_t(&output_list);
        if (type_t == Number) {
            push_data_lf(pop_data_lf(&output_list), &function_list);
        } else {
            Data_lf first_value = pop_data_lf(&function_list);
            for (value_type_t i = Cos; i <= Log; i++) {
                calculate_trigonometry(first_value, type_t, &function_list);
                break;
            }

            if ((type_t >= Add && type_t <= Pow) || (type_t == Mod)) {
                Data_lf second_value = pop_data_lf(&function_list);
                calculate_operation(first_value, second_value, type_t, &function_list);
            }
            pop_data_lf(&output_list);
        }
    }
    *f_result = pop_data_lf(&function_list);
    if (!is_empty(output_list))   remove_stack(output_list);
    if (!is_empty(function_list)) remove_stack(function_list);
    return *f_result;
}





int get_priority(int token) {
    int f_result = -2;
    if (this_is_digit(token))           f_result = -1;
    if (token == '(' || token == ')')   f_result = 0;
    if (token == '+' || token == '-')   f_result = 1;
    if (token == '*' || token == '/')   f_result = 2;
    if (token == '^')                   f_result = 3;
    return f_result;
}





void set_priority(s21_Stack_t **list) {
    if (this_is_digit((*list)->data_d))
        (*list)->priority = -1, (*list)->type_t = Number;
    if ((*list)->data_d == '(')
        (*list)->priority = 0, (*list)->type_t = OpenBracket;
    if ((*list)->data_d == ')')
        (*list)->priority = 0, (*list)->type_t = CloseBracket;
    if ((*list)->data_d == '+')
        (*list)->priority = 1, (*list)->type_t = Add;
    if ((*list)->data_d == '-')
        (*list)->priority = 1, (*list)->type_t = Sub;
    if ((*list)->data_d == '*')
        (*list)->priority = 2, (*list)->type_t = Mul;
    if ((*list)->data_d == '/')
        (*list)->priority = 2, (*list)->type_t = Div;
    if ((*list)->data_d == '^')
        (*list)->priority = 3, (*list)->type_t = Pow;
}






int get_math_expression(char *str, size_t *i, s21_Stack_t **list) {
    int f_result = ERROR;
    int r_strncmp = -1;

    if (strncmp(str + *i, "sin", 3) == 0) {
        r_strncmp = strncmp(str + *i, "sin", 3);
        if (r_strncmp == 0) {
            push_value_type_t(Sin, list);
            *i += 2;
            f_result = OK;
        }
    }
    if (strncmp(str + *i, "cos", 3) == 0) {
        r_strncmp = strncmp(str + *i, "cos", 3);
        if (r_strncmp == 0) {
            push_value_type_t(Cos, list);
            *i += 2;
            f_result = OK;
        }
    }
    if (strncmp(str + *i, "tan", 3) == 0) {
        r_strncmp = strncmp(str + *i, "tan", 3);
        if (r_strncmp == 0) {
            push_value_type_t(Tan, list);
            *i += 2;
            f_result = OK;
        }
    }
    if (strncmp(str + *i, "acos", 4) == 0) {
        r_strncmp = strncmp(str + *i, "acos", 4);
        if (r_strncmp == 0) {
            push_value_type_t(Acos, list);
            *i += 3;
            f_result = OK;
        }
    }
    if (strncmp(str + *i, "asin", 4) == 0) {
        r_strncmp = strncmp(str + *i, "asin", 4);
        if (r_strncmp == 0) {
            push_value_type_t(Asin, list);
            *i += 3;
            f_result = OK;
        }
    }
    if (strncmp(str + *i, "atan", 4) == 0) {
        r_strncmp = strncmp(str + *i, "atan", 4);
        if (r_strncmp == 0) {
            push_value_type_t(Atan, list);
            *i += 3;
            f_result = OK;
        }
    }
    if (strncmp(str + *i, "sqrt", 4) == 0) {
        r_strncmp = strncmp(str + *i, "sqrt", 4);
        if (r_strncmp == 0) {
            push_value_type_t(Sqrt, list);
            *i += 3;
            f_result = OK;
        }
    }
    if (strncmp(str + *i, "ln", 2) == 0) {
        r_strncmp = strncmp(str + *i, "ln", 2);
        if (r_strncmp == 0) {
            push_value_type_t(Ln, list);
            *i += 1;
            f_result = OK;
        }
    }
    if (strncmp(str + *i, "log", 3) == 0) {
        r_strncmp = strncmp(str + *i, "log", 3);
        if (r_strncmp == 0) {
            push_value_type_t(Log, list);
            *i += 2;
            f_result = OK;
        }
    }
    if (str[*i] == 'm') {
        r_strncmp = strncmp(str + *i, "mod", 3);
        if (r_strncmp == 0) {
            push_value_type_t(Mod, list);
            *i += 2;
            f_result = OK;
        }
    }
    return f_result;
}





void calculate_trigonometry(Data_lf value, value_type_t type_t, s21_Stack_t **list) {
    Data_lf f_result = 0.0;
    if (type_t == Sin) {
        f_result = sin(value);
        push_data_lf(f_result, list);
    }
    if (type_t == Cos) {
        f_result = cos(value);
        push_data_lf(f_result, list);
    }
    if (type_t == Tan) {
        f_result = tan(value);
        push_data_lf(f_result, list);
    }
    if (type_t == Acos) {
        f_result = acos(value);
        push_data_lf(f_result, list);
    }
    if (type_t == Asin) {
        f_result = asin(value);
        push_data_lf(f_result, list);
    }
    if (type_t == Atan) {
        f_result = atan(value);
        push_data_lf(f_result, list);
    }
    if (type_t == Sqrt) {
        f_result = sqrt(value);
        push_data_lf(f_result, list);
    }
    if (type_t == Ln) {
        f_result = log(value);
        push_data_lf(f_result, list);
    }
    if (type_t == Log) {
        f_result = log10(value);
        push_data_lf(f_result, list);
    }
}






void calculate_operation(Data_lf first_value, Data_lf second_value, value_type_t type_t, s21_Stack_t **list) {
    Data_lf result_value = 0.0;
    if (type_t == Add) {
        result_value = first_value + second_value;
    }
    if (type_t == Sub) {
        result_value = second_value - first_value;
    }
    if (type_t == Mul) {
        result_value = first_value * second_value;
    }
    if (type_t == Div) {
        result_value = second_value / first_value;
    }
    if (type_t == Mod) {
        result_value = fmod(second_value, first_value);
    }
    if (type_t == Pow) {
        if (first_value == 0.0) {
            result_value = 1;
        } else {
            result_value = pow(second_value, first_value);
        }
    }
    push_data_lf(result_value, list);
}





int this_is_digit(int token) {
    int f_result = ERROR;
    if (token >= '0' && token <= '9')
        f_result = OK;

    if (token == '.' || token == ',')
        f_result = OK;
    return f_result;
}





int this_is_sign(int token) {
    int f_result = ERROR;
    char sign[] = {'+', '-', '*', '/', '^'};
    for (char *i = sign; i <= sign + 4; i++)
        if (token == *i)
            f_result = OK;

    return f_result;
}




int this_is_function(int token) {
    int f_result = ERROR;
    for (int i = Cos; i <= Mod; i++) {
        if (token == i) {
            f_result = OK;
            break;
        }
    }
    return f_result;
}





void prepare_expression(char *str) {
    size_t k = 0;
    char new_str[255] = "";
    for (size_t i = 0; i < strlen(str); i++) {
        char token = str[i];
        if (token == '-' || token == '+') {
            if (i == 0) {
                new_str[k] = '0';
                k++;
            } else if (str[i - 1] == '(') {
                new_str[k] = '0';
                k++;
            }
        }
        new_str[k++] = token;
    }

    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == ',') new_str[i] = '.';
    }
    strncpy(str, new_str, strlen(new_str));
}
