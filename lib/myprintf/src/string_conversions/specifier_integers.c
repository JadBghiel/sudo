/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** specifier_integers
*/

#include "my_print.h"

char *specifier_digits(va_list arguments)
{
    int num = va_arg(arguments, int);
    int len = num_len(num);
    char *result_str = malloc((len + 1) * sizeof(char));
    int i = 0;
    int sign = num;

    if (num < 0)
        num *= -1;
    while (num > 0) {
        result_str[i] = num % 10 + '0';
        i++;
        num /= 10;
    }
    if (sign < 0) {
        result_str[i] = '-';
        i++;
    }
    result_str[i] = '\0';
    my_revstr(result_str);
    return result_str;
}
