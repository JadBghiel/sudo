/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** A_spec.c
*/

#include "my_print.h"

char *cap_a_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 13);
    to_add = specifier_float_to_hex_up(va_arg(*args, double), fm->precision);
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
