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

typedef bool (*add_flag_fn)(sudo_flags_t *, char *);

typedef struct tuple {
    char flag_char;
    add_flag_fn add_flag;
} tuple_t;

typedef struct sudo_flags {
    char *user;
    char *group;
    bool env_flag;
    bool s_flag;
    char *shell;
    linked_list_t *commands;
} sudo_flags_t;

sudo_flags_t *parse_flags(int ac, char **args);

bool add_user(sudo_flags_t *current_flags, char *next_word);
bool add_group(sudo_flags_t *current_flags, char *next_word);
bool add_env(sudo_flags_t *current_flags, char *next_word);
bool add_shell(sudo_flags_t *current_flags, char *next_word);

#endif