#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_







/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                          BY TONITAGA                           /
/                                                                /
/===============================================================*/





/*     Libraries need to this project     */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>





/*     value_type_t - нужен для того чтобы       */
/*     записывать тип символа или переменной     */
/*     в структуру s21_Stack_t                   */
typedef enum {
    OpenBracket = 0,    /*      '('      */
    CloseBracket,       /*      ')'      */
    Number,             /*      0-9      */
    X,                  /*      'x'      */
    Add,                /*      '+'      */
    Sub = 5,            /*      '-'      */
    Mul,                /*      '*'      */
    Div,                /*      '/'      */
    Pow,                /*      '^'      */
    Cos,                /*     cos(x)    */
    Sin = 10,           /*     sin(x)    */
    Tan,                /*     tan(x)    */
    Acos,               /*     acos(x)   */
    Asin,               /*     asin(x)   */
    Atan,               /*     atan(x)   */
    Sqrt = 15,          /*     sqrt(x)   */
    Ln,                 /*      ln(x)    */
    Log,                /*     log(x)    */
    Mod                 /*      mod      */
} value_type_t;





typedef char Data_d;
typedef double Data_lf;
typedef char * Data_s;


#define OK 1
#define ERROR 0





/*     Односвязный список типа LIFO - (Stack)     */
/*     LIFO - last in, first out                  */

/**
 * @param s21_Stack_t   Струткура представляющая обычный односвязный список типа LIFO
 * @param data_d        переменная для хранения данных типа char
 * @param data_lf       переменная для записи чисел
 * @param priority      переменная для хранения приоритета той или иной переменной
 * @param type_t        переменная указывающая на тип сохраненной переменной
 * @param next          указатель на следующий узел в списке
 */
typedef struct Node {
    Data_d data_d;
    Data_lf data_lf;
    int priority;
    value_type_t type_t;
    struct Node *next;
} s21_Stack_t;






/*===============================================================/
/                                                                /
/              БЛОК ФУНКЦИЙ РЕАЛИЗАЦИИ S21_STACK_T               /
/                                                                /
/===============================================================*/





/*      Функции добавления элемента (иначе проталкивание, push)      */

void            push_data_d(Data_d data_d, s21_Stack_t **list);
void            push_data_lf(Data_lf data_lf, s21_Stack_t **list);
void            push_value_type_t(value_type_t type_t, s21_Stack_t **list);
s21_Stack_t *   push_all(s21_Stack_t *list_old, s21_Stack_t *list_new);


/*      Функции удаления элемента      */

Data_d          pop_data_d(s21_Stack_t **list);
Data_lf         pop_data_lf(s21_Stack_t **list);
value_type_t    pop_value_type_t(s21_Stack_t **list);


/*      Функции чтения головного элемента      */

Data_d          peak_data_d(s21_Stack_t **list);
Data_lf         peak_data_lf(s21_Stack_t **list);
value_type_t    peak_value_type_t(s21_Stack_t **list);


/*      Функция проверки на пустоту стека      */

int             is_empty(s21_Stack_t *list);


/*      Функция переворода стека задом наперед      */

s21_Stack_t *   reverse_stack(s21_Stack_t *list);


/*      Удаление стека      */

void            remove_stack(s21_Stack_t *list);





#if defined _S21_CALCULATOR_PRINTF_FUNCTIONS

void            printf_stack_mega(s21_Stack_t *list, const char *type_printf);

#endif  // !_S21_CALCULATOR_PRINTF_FUNCTIONS





#endif  // SRC_S21_STACK_H_
