/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** f_spec.c
*/

#include "my_print.h"

char *f_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 6);
    to_add = specifier_float(va_arg(*args, double), fm->precision);
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
