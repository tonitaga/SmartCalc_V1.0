#define _S21_CALCULATOR_PRINTF_FUNCTIONS
#define _S21_CALCULATOR_ENGINE_SUPPORT_FUNCTIONS
#include "s21_Calculate.h"






/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





void remove_stack(s21_Stack_t *list) {
    while (!is_empty(list)) {
        s21_Stack_t *p = list;
        list = list->next;
        free(p);
    }
}





void push_data_d(Data_d data_d, s21_Stack_t **list) {
    s21_Stack_t *p = (s21_Stack_t *)malloc(sizeof(s21_Stack_t));
    p->data_d = data_d;
    p->next = *list;
    *list = p;
}





void push_data_lf(Data_lf data_lf, s21_Stack_t **list) {
    s21_Stack_t *p = (s21_Stack_t *)malloc(sizeof(s21_Stack_t));
    p->data_lf = data_lf;
    p->type_t = Number;
    p->priority = -1;
    p->next = *list;
    *list = p;
}





void push_value_type_t(value_type_t type_t, s21_Stack_t **list) {
    s21_Stack_t *p = (s21_Stack_t *) malloc(sizeof(s21_Stack_t));
    p->type_t = type_t;
    if (type_t == Mod) {
        p->priority = 2;
    } else {
        p->priority = 4;
    }
    p->next = *list;
    *list = p;
}






Data_d pop_data_d(s21_Stack_t **list) {
    Data_d data;
    s21_Stack_t *p = *list;
    data = p->data_d;
    *list = p->next;
    free(p);
    return data;
}





Data_lf pop_data_lf(s21_Stack_t **list) {
    Data_lf data;
    s21_Stack_t *p = *list;
    data = p->data_lf;
    *list = p->next;
    free(p);
    return data;
}





value_type_t pop_value_type_t(s21_Stack_t **list) {
    value_type_t type_t;
    s21_Stack_t *p = *list;
    type_t = p->type_t;
    *list = p->next;
    free(p);
    return type_t;
}





Data_d peak_data_d(s21_Stack_t **list) {
    Data_d data = 0;
    if (!is_empty(*list)) {
        s21_Stack_t *p = *list;
        data = p->data_d;
    }
    return data;
}





Data_lf peak_data_lf(s21_Stack_t **list) {
    Data_lf data = 0;
    if (!is_empty(*list)) {
        s21_Stack_t *p = *list;
        data = p->data_lf;
    }
    return data;
}





value_type_t peak_value_type_t(s21_Stack_t **list) {
    value_type_t type = -1;
    if (!is_empty(*list)) {
        s21_Stack_t *p = *list;
        type = p->type_t;
    }
    return type;
}





int is_empty(s21_Stack_t *list) {
    return list == NULL;
}





s21_Stack_t *reverse_stack(s21_Stack_t *list) {
    s21_Stack_t *p = list;
    s21_Stack_t *new_list = NULL;
    while (p) {
        new_list = push_all(p, new_list);
        p = p->next;
    }

    return new_list;
}





s21_Stack_t *push_all(s21_Stack_t *list_old, s21_Stack_t *list_new) {
    s21_Stack_t *p = (s21_Stack_t *)malloc(sizeof(s21_Stack_t));

    p->data_d = list_old->data_d;
    p->data_lf = list_old->data_lf;
    p->priority = list_old->priority;
    p->type_t = list_old->type_t;

    p->next = list_new;
    return (p);
}





/*                                                 */
/*          ФУНКЦИИ ПЕЧАТИ НА ЭКРАН СТЕКА          */

/*      ЕСЛИ TYPE_PRINTF = "row" ВЫВОД ТАКОВ:        */
/*      222*+                                        */
/*                                                   */
/*      ЕСЛИ TYPE_PRINTF = "list" ВЫВОД ТАКОВ:       */
/*      1) ... (ИНФОРМАЦИЯ)                          */
/*      2) ... (ИНФОРМАЦИЯ)                          */
void printf_stack_mega(s21_Stack_t *list, const char *type_printf) {
    int i = 1;
    int flag = 0;
    for (s21_Stack_t *p = list; p != NULL; p = p->next, i++) {
        if (strcmp(type_printf, "list") == 0) {
            if (this_is_sign(p->data_d)) {
                printf("%d) data_d  = %c\t\tpriority = %d\ttype_t = %d\n"
                                    , i, p->data_d, p->priority, p->type_t);
            } else {
                printf("%d) data_lf = %lf\tpriority = %d\ttype_t = %d\n"
                                    , i, p->data_lf, p->priority, p->type_t);
            }
        }
        if (strcmp(type_printf, "row") == 0) {
            flag = 1;
            if (this_is_sign(p->data_d)) {
                printf("%c ", p->data_d);
            } else {
                printf("%lf ", p->data_lf);
            }
        }
    }
    if (flag) printf("\n");
}
