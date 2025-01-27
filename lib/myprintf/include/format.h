/*
** EPITECH PROJECT, 2024
** My_printf
** File description:
** format.h
*/

#ifndef FORMAT_H
    #define FORMAT_H
typedef struct flags {
    bool minus;
    bool plus;
    bool space;
    bool zero;
    bool hash;
} flags_t;
typedef struct format {
    int stage;
    int width;
    int precision;
    flags_t flags;
    char identifier;
    bool error;
    int starting_i;
    int count;
} format_t;
#endif
