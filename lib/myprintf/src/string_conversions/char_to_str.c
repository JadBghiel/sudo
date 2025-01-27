/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** char_to_str
*/

#include "my_print.h"

char *my_char_to_str(int a)
{
    char c = (char)a;
    char *str = malloc(2);

    if (str == NULL) {
        return NULL;
    }
    str[0] = c;
    str[1] = '\0';
    return str;
}
