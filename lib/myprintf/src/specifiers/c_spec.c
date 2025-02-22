/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** c_spec.c
*/

#include "my_print.h"

char *c_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 6);
    to_add = my_char_to_str(va_arg(*args, int));
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
