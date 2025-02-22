/*
** EPITECH PROJECT, 2024
** Task07 Pool Day 3
** File description:
** Gets any integer and outputs with a recursive function
*/

#include "my_print.h"

static void repeating_write_num(int nb)
{
    int result = 0;

    if (nb > 9) {
        repeating_write_num(nb / 10);
        nb = (nb % 10);
    }
    result = (nb + 48);
    write(1, &result, 1);
}

int my_put_nbr(int nb)
{
    int len = 0;

    len = num_len(nb);
    if (nb < 0) {
        nb = nb * (-1);
        write(1, "-", 1);
    }
    repeating_write_num(nb);
    return len;
}
