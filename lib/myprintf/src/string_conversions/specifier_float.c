/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** specifier_float
*/

#include "my_print.h"

char *specifier_float(double float_num, int precision)
{
    return float_to_str(float_num, precision);
}
