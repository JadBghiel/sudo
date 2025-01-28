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
    #include "common_lib.h"
typedef struct sudo_flags {
    char *user;
    char *group;
    bool env_flag;
    bool s_flag;
    char *shell;
    linked_list_t *commands;
} sudo_flags_t;
sudo_flags_t *parse_flags(int ac, char **args);
#endif