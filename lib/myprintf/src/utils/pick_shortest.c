/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** picks shortest between scientific not and float
*/

#include "my_print.h"

static char *replace_cat(char *dest, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    return dest;
}

int which_format(char *str)
{
    int len = my_strlen(str);
    int is_scientific = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == 'e' || str[i] == 'E') {
            is_scientific = 1;
            break;
        }
    }
    return is_scientific;
}

static char *science_str_cat(char *dest, char *str)
{
    int len_dest = my_strlen(dest);
    int len_str = my_strlen(str);
    int g = -1;
    int j = 0;

    for (int i = 0; i < len_str; i++) {
        if (str[i] == 'e' || str[i] == 'E') {
            g = i;
            break;
        }
    }
    while (str[g] != '\0' && g != -1) {
        dest[len_dest + j] = str[g];
        g++;
        j++;
    }
    dest[len_dest + j] = '\0';
    free(str);
    return dest;
}

int dot_finder(int len, char *str)
{
    int dot = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            dot = i;
            break;
        }
    }
    return dot;
}

char *trim_trailing_zeros(char *str, int is_scientific)
{
    int len = my_strlen(str);
    char *temp_str = malloc((len + 1) * sizeof(char));
    int dot = 0;

    temp_str = replace_cat(temp_str, str);
    dot = dot_finder(len, str);
    if (dot == 0)
        return str;
    len = (is_scientific == 1) ? len - 5 : len -1;
    while (len > dot && str[len] == '0') {
        str[len] = '\0';
        len--;
    }
    if (str[len] == '.') {
        str[len] = '\0';
    }
    str = science_str_cat(str, temp_str);
    return str;
}

static char *chosen_one(char *str_1, char *str_2)
{
    int len1 = 0;
    int len2 = 0;

    len1 = my_strlen(str_1);
    len2 = my_strlen(str_2);
    if (len1 > len2) {
        free(str_1);
        return str_2;
    } else {
        free(str_2);
        return str_1;
    }
}

char *spec_g(double float_nb, int precision, int majuscule)
{
    int is_scientific = 0;
    char *str_1 = "";
    char *str_2 = "";

    str_1 = float_to_str(float_nb, precision);
    str_2 = spec_scientific(float_nb, precision, majuscule);
    is_scientific = which_format(str_1);
    str_1 = trim_trailing_zeros(str_1, is_scientific);
    is_scientific = which_format(str_2);
    str_2 = trim_trailing_zeros(str_2, is_scientific);
    return chosen_one(str_1, str_2);
}
