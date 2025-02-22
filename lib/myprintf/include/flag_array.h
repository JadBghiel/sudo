/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** flag_array.h
*/

#ifndef FLAG_DEFS
    #define FLAG_DEFS
    #ifndef FLAG_DECLS
extern const char printf_flags[7];
extern const char *printf_lens[9];
extern const char printf_spec[20];
    #else
const char printf_flags[7] = {'-', '+', ' ', '0', '#', 0};
const char *printf_lens[9] = {"hh", "h", "l", "ll", "L", "z", "j", "z", 0};
const char printf_spec[20] = {'d', 'i', 'u', 'f', 'F', 'e', 'E',
    'g', 'G', 'x', 'X', 'o', 's', 'c', 'p', 'a', 'A', 'n', '%', 0};
    #endif
#endif
