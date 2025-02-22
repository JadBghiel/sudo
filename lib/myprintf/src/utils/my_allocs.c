/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** my_realloc.c
*/

#include "my_print.h"

void *my_calloc(int elem_num, int size)
{
    char *current = malloc(size * elem_num);

    if (current == NULL)
        return NULL;
    for (int i = 0; i < size * elem_num; i++)
        *(current + i) = 0;
    return current;
}

void *my_realloc(char *old_malloc, int size)
{
    char *new_malloc = my_calloc(size, 1);
    char *src = old_malloc;

    if (new_malloc == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        if (src[i] != 0)
            new_malloc[i] = src[i];
    }
    free(old_malloc);
    return new_malloc;
}
