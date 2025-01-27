/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** specifier_scientific_notation
*/

#include "my_print.h"

char *my_strcat(char *dest, char const *str)
{
    char *dest_start = dest;

    while (dest[0] != '\0') {
        dest++;
    }
    while (str[0] != '\0') {
        dest[0] = str[0];
        dest++;
        str++;
    }
    dest = dest_start;
    return dest;
}

static int draft_excess_count(double float_nb)
{
    float temp_value = float_nb;
    int pos_count = 0;

    if (float_nb >= 10) {
        while (temp_value >= 10) {
            temp_value = temp_value / 10;
            pos_count++;
        }
        return pos_count;
    }
    if (float_nb < 1)
        return -1;
    return 0;
}

static int draft_insufficient_count(double float_nb)
{
    float temp_value = float_nb;
    int neg_count = 0;

    if (draft_excess_count(float_nb) == -1) {
        while (temp_value < 1) {
            temp_value = temp_value * 10;
            neg_count++;
        }
        return (neg_count);
    }
    return 0;
}

static float draft_correct_size_function(double float_nb)
{
    long excess_count = draft_excess_count(float_nb);
    long insufficient_count = draft_insufficient_count(float_nb);

    if (excess_count == -1) {
        float_nb = float_nb * my_compute_power_rec(10, insufficient_count);
    } else {
        float_nb = float_nb / my_compute_power_rec(10, excess_count);
    }
    return (float_nb);
}

char *num_to_str(int num)
{
    int len = num_len(num);
    char *result_str = malloc((len + 2) * sizeof(char));
    int i = 0;

    if (num < 0)
        num = num * (-1);
    while (num > 0) {
        result_str[i] = num % 10 + '0';
        i++;
        num /= 10;
    }
    if (len < 2) {
        result_str[i] = '0';
        i++;
    }
    result_str[i] = '\0';
    my_revstr(result_str);
    return result_str;
}

static int handle_negative(double *float_nb_ptr)
{
    if (*float_nb_ptr < 0) {
        *float_nb_ptr *= -1;
        return 1;
    }
    return 0;
}

char *spec_scientific(double float_nb, int precision, int capital)
{
    int multiplier = draft_excess_count(float_nb);
    int pos_multiplier = 0;
    char *str;

    handle_negative(&float_nb);
    if (multiplier >= 0)
        pos_multiplier = -1;
    if (multiplier == -1)
        multiplier = draft_insufficient_count(float_nb);
    float_nb = draft_correct_size_function(float_nb);
    str = float_to_str(float_nb, precision);
    str[my_strlen(str)] = 'e' + capital;
    if (pos_multiplier == -1)
        str[my_strlen(str)] = '+';
    else
        str[my_strlen(str)] = '-';
    return my_strcat(str, num_to_str(multiplier));
}
