/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** d_spec.c
*/
#include "my_print.h"

char *d_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 0);
    to_add = alrik_num_to_str(va_arg(*args, int), fm->precision);
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
