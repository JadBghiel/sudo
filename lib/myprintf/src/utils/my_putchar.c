/*
** EPITECH PROJECT, 2024
** putchar
** File description:
** created by oriol
*/
#include "my_print.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
