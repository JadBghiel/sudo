/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** spec_unsigned
*/

#include "my_print.h"

static int prec_padder(int len, int precision, char *str, int i)
{
    int add_zero_nb = precision - len;

    while (add_zero_nb > 0) {
        str[i] = '0';
        i++;
        add_zero_nb--;
    }
    return i;
}

char *unsigned_num_to_str(unsigned int num, int precision)
{
    int len = num_len(num);
    char *result_str = malloc((len + precision + 1) * sizeof(char));
    int i = 0;
    int sign = (num < 0) ? -1 : 1;

    if (num < 0)
        num = num * (-1);
    while (num > 0) {
        result_str[i] = num % 10 + '0';
        i++;
        num /= 10;
    }
    i = prec_padder(len, precision, result_str, i);
    if (sign < 0) {
        result_str[i] = '-';
        i++;
    }
    result_str[i] = '\0';
    my_revstr(result_str);
    return result_str;
}
