/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** sudo_flags.h
*/

#ifndef MY_SUDO
    #define MY_SUDO
    #include <stdbool.h>
    #include "mylist.h"

typedef enum {
    USER,
    GROUP,
    ENVIOURMENT,
    SHELL,
    MAX_OPTION,
} sudo_options_t;

typedef struct sudo_flags sudo_flags_t;

typedef bool (*add_flag_fn)(sudo_flags_t *, char *, char *);

typedef struct full_flag {
    char *abreviation;
    char *full_flag;
} full_flag_t;

typedef struct tuple {
    full_flag_t abreviations;
    add_flag_fn add_flag;
} tuple_t;

typedef struct sudo_flags {
    char *user;
    char *group;
    bool env_flag;
    bool s_flag;
    char **commands;
} sudo_flags_t;

sudo_flags_t *parse_flags(int ac, char **args);

bool add_user(sudo_flags_t *current_flags, char *word, char *next);
bool add_group(sudo_flags_t *current_flags, char *word, char *next);
bool add_env(sudo_flags_t *current_flags, char *word, char *next);
bool add_shell(sudo_flags_t *current_flags, char *word, char *next);

#endif