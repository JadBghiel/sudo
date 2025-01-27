/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** e_spec.c
*/

#include "my_print.h"
#include <stdio.h>

char *e_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 6);
    to_add = spec_scientific(va_arg(*args, double), fm->precision, 0);
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
