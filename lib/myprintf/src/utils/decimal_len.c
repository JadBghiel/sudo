/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** float_len
*/

#include "my_print.h"

int decimal_len(float just_decimal, int precision)
{
    int int_part = (int)just_decimal;
    int digit = 0;
    float decimal_part = just_decimal - int_part;
    int int_just_decimal = 0;
    int count = 0;

    while (decimal_part > 0.0 && count < precision) {
        decimal_part = decimal_part * 10;
        digit = (int)decimal_part;
        int_just_decimal = int_just_decimal * 10 + digit;
        decimal_part = decimal_part - digit;
        count++;
    }
    return int_just_decimal;
}
