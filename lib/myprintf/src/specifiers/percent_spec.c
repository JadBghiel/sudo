/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** percent_spec.c
*/

#include "my_print.h"

char *percent_spec(va_list *args, format_t *fm)
{
    char *to_add = malloc(2);

    to_add[0] = '%';
    to_add[1] = 0;
    return to_add;
}
