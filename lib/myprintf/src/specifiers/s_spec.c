/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** s_spec.c
*/

#include "my_print.h"

char *s_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 4096);
    to_add = specifier_str(va_arg(*args, char *), fm->precision);
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
