/*
** EPITECH PROJECT, 2024
** positve put float
** File description:
** writing a positive float nbr
*/

#include "my_print.h"

int float_num_len(int int_nb, int int_just_decimal, int len)
{
    len += num_len(int_nb);
    len += num_len(int_just_decimal);
    return len;
}

int my_put_float(float float_nb)
{
    int len = 0;
    int int_nb;
    float just_decimal;
    int int_just_decimal;

    if (float_nb < 0) {
        float_nb = float_nb * -1;
        len += write(1, "-", 1);
    }
    int_nb = (int)float_nb;
    just_decimal = (float)(float_nb - int_nb);
    int_just_decimal = decimal_len(just_decimal, len);
    my_put_nbr(int_nb);
    len += write(1, ".", 1);
    if (int_just_decimal <= 9) {
        my_put_nbr(0);
    }
    my_put_nbr(int_just_decimal);
    return float_num_len(int_nb, int_just_decimal, len);
}
