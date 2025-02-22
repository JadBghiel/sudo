/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** float_to_str
*/

#include <stdio.h>
#include <string.h>
#include "my_print.h"

// my_revstr wont work cus i'm passing an incomplete string
void modified_revstr(char *str, int length)
{
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int int_to_str(int float_nb, char *str)
{
    int len = 0;

    while (float_nb != 0 || len == 0) {
        str[len] = (float_nb % 10) + '0';
        len++;
        float_nb = float_nb / 10;
    }
    modified_revstr(str, len);
    str[len] = '\0';
    return len;
}

static int handle_negfloat(double *float_nb_ptr)
{
    if (*float_nb_ptr < 0.0) {
        *float_nb_ptr *= -1;
        return 1;
    }
    return 0;
}

char *float_to_str(double float_nb, int precision)
{
    char *str = malloc(55 * sizeof(char));
    int is_negative = handle_negfloat(&float_nb);
    double dec_part = ((float_nb - (double)((int)float_nb)));
    int i = 0;

    if (is_negative) {
        str[0] = '-';
        i++;
    }
    i += int_to_str(float_nb, str + i);
    if (precision != 0) {
        str[i] = '.';
        i++;
        for (int j = 0; j < precision; j++) {
            dec_part *= 10;
            int_to_str(dec_part, str + i + j);
            dec_part -= (int)dec_part;
        }
    }
    return str;
}
