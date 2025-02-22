/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** dprintf.c
*/

#include "../include/my_print.h"

int my_dprintf(int fd, char const *format, ...)
{
    va_list arguments;
    char *buffer;
    int count = 0;

    va_start(arguments, format);
    buffer = buffer_printf(format, &arguments);
    va_end(arguments);
    count = my_strlen(buffer);
    write(fd, buffer, count);
    free(buffer);
    return count;
}
