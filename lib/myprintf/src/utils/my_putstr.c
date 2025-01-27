/*
** EPITECH PROJECT, 2024
** Task02 Pool Day 4
** File description:
** Displays the characters of a string one by one
*/

#include "my_print.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        my_putchar(str[i]);
    }
    return my_strlen(str);
}
