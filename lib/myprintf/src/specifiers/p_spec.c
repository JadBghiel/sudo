/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** p_spec.c
*/

#include "my_print.h"

char *p_spec(va_list *args, format_t *fm)
{
    char *to_add = "";

    set_width(args, fm);
    set_precision(args, fm, 6);
    to_add = pointer_to_str(va_arg(*args, unsigned long));
    fm->flags.hash = true;
    to_add = make_add_buffer(fm, to_add);
    return to_add;
}
