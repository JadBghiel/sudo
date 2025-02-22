/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** specifier_hexadecimal
*/

#include "my_print.h"

int hexadecimal_len(int decimal_number)
{
    int len = 0;
    int temp = 0;

    while (decimal_number != 0) {
        temp = decimal_number % 16;
        if (temp < 10) {
            len += 1;
        } else {
            len += 1;
        }
        decimal_number = decimal_number / 16;
    }
    return len;
}

char *put_specifier_hexadecimal_uppercase(unsigned int decimal_number)
{
    int i = 0;
    int temp = 0;
    int len = hexadecimal_len(decimal_number);
    char *hexadecimal = malloc((len + 1) * sizeof(char));

    while (decimal_number != 0) {
        temp = decimal_number % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        hexadecimal[i] = temp;
        i++;
        decimal_number = decimal_number / 16;
    }
    hexadecimal[i] = '\0';
    my_revstr(hexadecimal);
    return hexadecimal;
}

char *put_specifier_hexadecimal_lowercase(unsigned int decimal_number)
{
    int i = 0;
    int temp = 0;
    int len = hexadecimal_len(decimal_number);
    char *hexadecimal = malloc((len + 1) * sizeof(char));

    while (decimal_number != 0) {
        temp = decimal_number % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 87;
        }
        hexadecimal[i] = temp;
        i++;
        decimal_number = decimal_number / 16;
    }
    hexadecimal[i] = '\0';
    my_revstr(hexadecimal);
    return hexadecimal;
}
