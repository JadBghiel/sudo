/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** my_printf.c
*/

#include "my_print.h"
#include "declarations.h"
#include "flag_array.h"

char *char_to_str(char current)
{
    char *newstr = malloc(3);

    if (newstr == NULL) {
        return NULL;
    }
    *newstr = current;
    *(newstr + 1) = 0;
    return newstr;
}

static char *buffer_add(int *count, char *dest, char *src)
{
    int length = my_strlen(src);
    int dest_length = my_strlen(dest);
    int pos = 0;
    char *new_dest = malloc(my_strlen(dest) + length + 1);

    if (new_dest == NULL)
        return 0;
    for (; pos < dest_length; pos++)
        new_dest[pos] = dest[pos];
    for (; pos < length + dest_length; pos++)
        new_dest[pos] = src[pos - dest_length];
    *count += length;
    free(src);
    new_dest[*count] = 0;
    return new_dest;
}

static char *bprintf_return(format_t *formating, char *buffer, int last_char)
{
    free(formating);
    buffer[last_char] = 0;
    return buffer;
}

static char *write_format(int *count, format_t *fm, char *buff, va_list *args)
{
    char *(*spec_funcs[19]) (va_list *, format_t *) = {d_spec, d_spec, u_spec,
        f_spec, cap_f_spec, e_spec, cap_e_spec, g_spec, cap_g_spec, x_spec,
        cap_x_spec, o_spec, s_spec, c_spec, p_spec, a_spec, cap_a_spec, n_spec,
        percent_spec};
    char *to_add = "";
    char id = fm->identifier;
    char *new_buffer;

    to_add = spec_funcs[get_array_pos(id, printf_spec)] (args, fm);
    new_buffer = buffer_add(count, buff, to_add);
    free(fm);
    free(buff);
    return new_buffer;
}

static char *write_char(int *count, char new_char, char *buff)
{
    char *to_add = char_to_str(new_char);
    char *new_buffer = buffer_add(count, buff, to_add);

    free(buff);
    return new_buffer;
}

char *buffer_printf(char const *fm, va_list *args)
{
    int char_count = 0;
    format_t *formating = empty_format();
    char *buffer = my_calloc(1, 1);

    for (int i = 0; fm[i] != 0; i++) {
        formating = process_format(formating, fm, i);
        if (formating->error) {
            i = formating->starting_i;
            free(formating);
            formating = empty_format();
        }
        if (!formating->stage)
            buffer = write_char(&char_count, fm[i], buffer);
        if (formating->stage == 5) {
            buffer = write_format(&char_count, formating, buffer, args);
            formating = empty_format();
        }
        formating->count = char_count;
    }
    return bprintf_return(formating, buffer, char_count);
}

int my_printf(char const *format, ...)
{
    va_list arguments;
    char *buffer;
    int count = 0;

    va_start(arguments, format);
    buffer = buffer_printf(format, &arguments);
    va_end(arguments);
    count = my_putstr(buffer);
    free(buffer);
    return count;
}
