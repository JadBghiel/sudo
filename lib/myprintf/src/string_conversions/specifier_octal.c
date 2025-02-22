/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** specifier_octal
*/

#include "my_print.h"

char *int_to_octal(int num, char *octal_string)
{
    int i = 0;
    int remainder = 0;

    if (num == 0) {
        octal_string[0] = '0';
        octal_string[1] = '\0';
        return octal_string;
    }
    while (num > 0) {
        remainder = num % 8;
        octal_string[i] = '0' + remainder;
        i++;
        num /= 8;
    }
    octal_string[i] = '\0';
    octal_string = my_revstr(octal_string);
    return octal_string;
}

char *specifier_octal(unsigned int num)
{
    int len = num_len(num);
    char *octal_string = malloc((len + 3) * sizeof(char));

    if (octal_string == NULL)
        return NULL;
    octal_string = int_to_octal(num, octal_string);
    return octal_string;
}
