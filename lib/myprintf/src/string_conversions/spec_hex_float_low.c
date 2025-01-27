/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** specifier hexa_float
*/

#include "my_print.h"

static char *strcat_and_numstr(int exponent, char *result, int len)
{
    int exponent_digits[10];
    int exp_len = 0;

    len += 2;
    do {
        exponent_digits[exp_len] = exponent % 10;
        exp_len++;
        exponent /= 10;
    } while (exponent > 0);
    for (int i = exp_len - 1; i >= 0; i--) {
        result[len] = '0' + exponent_digits[i];
        len++;
    }
    result[len] = '\0';
    return result;
}

static char *prefix(char *result, int len)
{
    result[len] = '0';
    len++;
    result[len] = 'x';
    len++;
    result[len] = '1';
    len++;
    result[len] = '.';
    len++;
    return result;
}

static int suffix(int len, char *result, int exponent)
{
    result[len] = 'p';
    len++;
    if (exponent >= 0) {
        result[len] = '+';
        len++;
    } else {
        result[len] = '-';
        len++;
        exponent = -exponent;
    }
    return exponent;
}

int hex_float_to_str_low(int precision, double copy, char *result, int len)
{
    int hex_dig = 0;

    for (int i = 0; i < precision; i++) {
        copy *= 16;
        hex_dig = (int)copy;
        result[len] = (hex_dig < 10) ? '0' + hex_dig : 'a' + (hex_dig - 10);
        len++;
        copy -= hex_dig;
    }
    return len;
}

double sign_implementer_low(double num, double copy, char *result, int *len)
{
    int sign = (num < 0) ? -1 : 1;

    if (sign == -1) {
        copy = -copy;
        result[0] = '-';
        (*len) += 1;
    }
    return copy;
}

char *double_to_hex(double num, char *result, int precision)
{
    double copy = num;
    int exponent = 0;
    int len = 0;

    copy = sign_implementer_low(num, copy, result, &len);
    while (copy >= 2.0) {
        copy /= 2.0;
        exponent++;
    }
    while (copy < 1.0 && copy > 0.0) {
        copy *= 2.0;
        exponent--;
    }
    copy -= 1.0;
    result = prefix(result, len);
    len = len + 4;
    len = hex_float_to_str_low(precision, copy, result, len);
    exponent = suffix(len, result, exponent);
    result = strcat_and_numstr(exponent, result, len);
    return result;
}

char *specifier_float_to_hex_low(double num, int precision)
{
    char *result = malloc(40 * sizeof(char));

    result = double_to_hex(num, result, precision);
    return result;
}
