/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** x_spec.c
*/

#include "my_print.h"
#include <stdio.h>

char *x_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 6);
    to_add = put_specifier_hexadecimal_lowercase(va_arg(*args, int));
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
