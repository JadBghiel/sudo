/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** is_next_format_stage.c
*/

#include "my_print.h"
#include "flag_array.h"

int get_array_pos(char to_compare, const char *array)
{
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == to_compare)
            return i;
    }
    return -1;
}

static format_t *edit_nothing(format_t *current, const char *str, int i)
{
    return current;
}

static format_t *edit_percentage(format_t *current, const char *str, int i)
{
    if (str[i] != '%') {
        current->error = true;
        return current;
    }
    current->starting_i = i;
    return current;
}

static format_t *edit_flags(format_t *current, const char *str, int i)
{
    int pos = get_array_pos(str[i], printf_flags);

    if (pos == 0)
        current->flags.minus = true;
    if (pos == 1)
        current->flags.plus = true;
    if (pos == 2)
        current->flags.space = true;
    if (pos == 3)
        current->flags.zero = true;
    if (pos == 4)
        current->flags.hash = true;
    if (pos == -1)
        current->error = true;
    return current;
}

static format_t *edit_width(format_t *current, const char *str, int i)
{
    int current_int = (str[i] - 48);

    if (current->width == -1)
        current->width = 0;
    if (current->width == -2)
        current->error = true;
    if (str[i] == '*') {
        current->width = -2;
        return current;
    }
    if (is_num(str[i])) {
        current->width = (current_int + current->width * 10);
        return current;
    }
    current->error = true;
    return current;
}

static format_t *edit_precision(format_t *current, const char *str, int i)
{
    int current_int = (str[i] - 48);

    if (current->precision == -2)
        current->error = true;
    if (str[i] == '*') {
        current->precision = -2;
        return current;
    }
    if (str[i] == '.') {
        current->precision = 0;
        return current;
    }
    if (is_num(str[i])) {
        current->precision = (current_int + current->precision * 10);
        return current;
    }
    return current;
}

static format_t *edit_identifier(format_t *current, const char *str, int i)
{
    current->identifier = str[i];
    return current;
}

format_t *empty_format(void)
{
    format_t *empty = malloc(sizeof(format_t));
    flags_t no_flags;

    no_flags.hash = false;
    no_flags.minus = false;
    no_flags.plus = false;
    no_flags.space = false;
    no_flags.zero = false;
    empty->identifier = '0';
    empty->precision = -1;
    empty->width = -1;
    empty->stage = 0;
    empty->flags = no_flags;
    empty->error = false;
    return empty;
}

int is_next_stage(char current_char, int format_stage)
{
    if (format_stage == 0 || format_stage == 5) {
        if (current_char == '%')
            return 1;
        return 0;
    }
    if (format_stage < 2 && get_array_pos(current_char, printf_flags) != -1)
        return 2;
    if (format_stage < 3 && (is_num(current_char) || current_char == '*'))
        return 3;
    if (format_stage < 4 && current_char == '.')
        return 4;
    if (format_stage < 5 && get_array_pos(current_char, printf_spec) != -1) {
        return 5;
    }
    return format_stage;
}

format_t *process_format(format_t *current, const char *str, int index)
{
    format_t *(*edit_format[6]) (format_t *, const char *, int) = {
    edit_nothing, edit_percentage, edit_flags, edit_width, edit_precision,
    edit_identifier};

    current->stage = is_next_stage(str[index], current->stage);
    current = edit_format[current->stage](current, str, index);
    return current;
}
