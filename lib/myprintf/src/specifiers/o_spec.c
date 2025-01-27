/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** o_spec.c
*/

#include "my_print.h"

char *o_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 6);
    to_add = specifier_octal(va_arg(*args, int));
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
