/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** sprintf.c
*/

#include "my_print.h"

int my_sprintf(char *str, char const *format, ...)
{
    va_list arguments;
    char *buffer;
    int i = 0;

    va_start(arguments, format);
    buffer = buffer_printf(format, &arguments);
    for (i = 0; buffer[i] != 0; i++) {
        str[i] = buffer[i];
    }
    str[i] = 0;
    free(buffer);
    va_end(arguments);
    return (my_strlen(str) + 1);
}
