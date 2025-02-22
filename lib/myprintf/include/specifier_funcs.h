/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** specifier_funcs.h
*/

#ifndef SPEC_FUNCS
    #define SPEC_FUNCS
    #include "format.h"
    #include <stdarg.h>
char *d_spec(va_list *, format_t *);
char *u_spec(va_list *, format_t *);
char *f_spec(va_list *, format_t *);
char *cap_f_spec(va_list *, format_t *);
char *e_spec(va_list *, format_t *);
char *cap_e_spec(va_list *, format_t *);
char *g_spec(va_list *, format_t *);
char *cap_g_spec(va_list *, format_t *);
char *x_spec(va_list *, format_t *);
char *cap_x_spec(va_list *, format_t *);
char *o_spec(va_list *, format_t *);
char *s_spec(va_list *, format_t *);
char *c_spec(va_list *, format_t *);
char *p_spec(va_list *, format_t *);
char *a_spec(va_list *, format_t *);
char *cap_a_spec(va_list *, format_t *);
char *n_spec(va_list *, format_t *);
char *percent_spec(va_list *, format_t *);
void set_precision(va_list *, format_t *, int);
void set_width(va_list *, format_t *);
char *make_add_buffer(format_t *, char *);
#endif /* SPEC_FUNCS */
