/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** my_numtostr.c
*/

#include "my_print.h"

char *my_numtostr(int num, int precision)
{
    char *filled_numstr = "";
    int numlength = num_len(num);
    int is_neg = (num < 0);

    if (numlength + is_neg < precision)
        filled_numstr = my_calloc(precision + 1, 1);
    else {
        filled_numstr = my_calloc(numlength + is_neg + 1, 1);
        precision = numlength;
    }
    if (is_neg) {
        filled_numstr[precision - numlength] = '-';
        num *= -1;
    }
    for (int i = precision; i > 0; i--) {
        filled_numstr[i - 1] = ((num % 10) + 48);
        num /= 10;
    }
    return filled_numstr;
}

int precision_padder(int len, int precision, char *str, int i)
{
    int add_zero_nb = precision - len;

    while (add_zero_nb > 0) {
        str[i] = '0';
        i++;
        add_zero_nb--;
    }
    return i;
}

char *alrik_num_to_str(int num, int precision)
{
    char *result_str = malloc((num_len(num) + precision + 2));
    int i = 0;
    int sign = (num < 0) ? -1 : 1;

    if (result_str == NULL)
        return NULL;
    if (num < 0)
        num *= -1;
    for (; num > 0 || i == 0; i++) {
        result_str[i] = num % 10 + '0';
        num /= 10;
    }
    i = precision_padder(num_len(num), precision, result_str, i);
    if (sign < 0) {
        result_str[i] = '-';
        i++;
    }
    result_str[i] = '\0';
    my_revstr(result_str);
    return result_str;
}
