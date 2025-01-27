/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_print
*/

#ifndef MY_PRINT_H
    #define MY_PRINT_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include "format.h"
    #include "specifier_funcs.h"
int my_printf(char const *, ...);
char *buffer_printf(char const *, va_list *);
void *my_realloc(char *, int);
void *my_calloc(int, int);
int my_putchar(char);
int my_putstr(const char *);
int my_strlen(char const *);
int my_put_float(float);
int decimal_len(float, int);
char *my_revstr(char *);
long my_compute_power_rec(int, int);
char *float_to_str(double, int);
int my_put_nbr(int nb);
int num_len(int nb);
int is_num(char);
int is_next_stage(char, int);
int get_array_pos(char, const char *);
char *spec_scientific(double, int, int);
int int_to_str(int, char *);
char *my_strcat(char *, char const *);
char *specifier_str(char *, int);
char *put_specifier_hexadecimal_uppercase(unsigned int);
char *put_specifier_hexadecimal_lowercase(unsigned int);
char *specifier_octal(unsigned int);
char *specifier_float(double, int);
char *specifier_float_to_hex_low(double, int);
char *my_numtostr(int, int);
char *specifier_float_to_hex_up(double, int);
char *alrik_num_to_str(int, int);
char *unsigned_num_to_str(unsigned int, int);
char *my_char_to_str(int);
char *pointer_to_str(unsigned long);
char *spec_g(double, int, int);
format_t *empty_format(void);
format_t *process_format(format_t *, const char *, int);
int my_dprintf(int, char const *, ...);
int my_sprintf(char *, char const *, ...);
char *my_bprintf(char const *, ...);
#endif
