/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** bprintf.c
*/

#include "../include/my_print.h"

char *my_bprintf(char const *format, ...)
{
    va_list arguments;
    char *buffer;

    va_start(arguments, format);
    buffer = buffer_printf(format, &arguments);
    va_end(arguments);
    return buffer;
}
