/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** put_specifier_str
*/

#include "my_print.h"

char *my_fake_strcat(char *dest, char const *str, int precision, int len)
{
    int n = 0;

    while (str[n] != '\0' && n < precision) {
        dest[n] = str[n];
        n++;
    }
    dest[n] = '\0';
    return dest;
}

char *specifier_str(char *str, int precision)
{
    int len = my_strlen(str);
    char *result_string = malloc((len + 1) * sizeof(char));

    result_string = my_fake_strcat(result_string, str, precision, len);
    return result_string;
}
