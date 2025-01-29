/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** main.c
*/

#include "my_sudo.h"
#include <stdio.h>

int main(int ac, char **av)
{
    sudo_flags_t *a;

    if (ac < 2)
        return 84;
    for (int i = 0; a->commands[i]; i++)
        printf("%s ", a->commands[i]);
    printf("\n");
    return 0;
}