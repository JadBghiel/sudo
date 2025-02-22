/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** cap_g_spec.c
*/

#include "my_print.h"

char *cap_g_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 6);
    to_add = spec_g(va_arg(*args, double), fm->precision, -32);
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
