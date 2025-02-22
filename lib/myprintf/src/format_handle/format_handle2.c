/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** format_handle2.c
*/

#include "my_print.h"

void set_precision(va_list *args, format_t *fm, int def)
{
    if (fm->precision == -2) {
        fm->precision = va_arg(*args, int);
    }
    if (fm->precision == -1) {
        fm->precision = def;
    }
}

void set_width(va_list *args, format_t *fm)
{
    if (fm->width == -2) {
        fm->width = va_arg(*args, int);
    }
}

static char lower_char(char to_lower)
{
    if (to_lower >= 'A' && to_lower <= 'Z') {
        return (to_lower - 32);
    }
    return to_lower;
}

static char *do_hash(format_t *fm, char *to_add)
{
    char id = lower_char(fm->identifier);
    int length = my_strlen(to_add);
    char *new_str = "";

    if (id == 'o' || id == 'x' || id == 'p') {
        new_str = my_calloc(length + 3, 1);
        new_str[0] = '0';
        new_str[1] = 'x';
        for (int i = 2; i < (length + 2); i++) {
            new_str[i] = to_add[i - 2];
        }
        free(to_add);
        return new_str;
    }
    return to_add;
}

static char get_first_char(format_t *fm, char *to_add)
{
    char id = lower_char(fm->identifier);
    flags_t f = fm->flags;
    const char *signed_id = "difega";

    if (to_add[0] != '-' && get_array_pos(id, signed_id) != -1) {
        if (f.plus)
            return '+';
        if (f.space)
            return ' ';
    }
    return to_add[0];
}

static char *startchar_handle(format_t *fm, char *to_add)
{
    char start_char = get_first_char(fm, to_add);
    char *new_str = "";

    if (start_char == '+' || start_char == ' ') {
        new_str = my_calloc(my_strlen(to_add) + 2, 1);
        new_str[0] = start_char;
        for (int i = 0; i < my_strlen(to_add); i++) {
            new_str[i + 1] = to_add[i];
        }
        free(to_add);
        return new_str;
    }
    return to_add;
}

static char *width_add(format_t *fm, char *dest, char *src)
{
    int src_width = my_strlen(src);

    if (fm->flags.minus) {
        for (int i = 0; i < my_strlen(src); i++) {
            dest[i] = src[i];
        }
        return dest;
    }
    for (int i = fm->width - src_width; i < fm->width; i++) {
        dest[i] = src[i - (fm->width - src_width)];
    }
    return dest;
}

char *make_add_buffer(format_t *fm, char *to_add)
{
    char *str = "";
    char id = lower_char(fm->identifier);
    char empty_space = ' ';

    if (fm->flags.zero && (id != 's' && id != 'c' && id != 'p'))
        empty_space = '0';
    if (fm->flags.hash)
        to_add = do_hash(fm, to_add);
    to_add = startchar_handle(fm, to_add);
    if (fm->width > my_strlen(to_add)) {
        str = my_calloc(1, fm->width + 1);
        for (int i = 0; i < fm->width; i++)
            str[i] = empty_space;
        str = width_add(fm, str, to_add);
        free(to_add);
        return str;
    }
    return to_add;
}
