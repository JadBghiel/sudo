/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** pointer_to_str.c
*/

#include "my_print.h"

static int pointer_len(unsigned long ptr)
{
    int len = 0;
    int temp = 0;

    while (ptr != 0) {
        temp = ptr % 16;
        if (temp < 10) {
            len += 1;
        } else {
            len += 1;
        }
        ptr /= 16;
    }
    return len;
}

char *pointer_to_str(unsigned long decimal_pointer)
{
    int i = 0;
    int temp = 0;
    int len = pointer_len(decimal_pointer);
    char *ptr_string = malloc(len + 1);

    while (decimal_pointer != 0) {
        temp = decimal_pointer % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 87;
        }
        ptr_string[i] = temp;
        i++;
        decimal_pointer /= 16;
    }
    ptr_string[i] = '\0';
    my_revstr(ptr_string);
    return ptr_string;
}
