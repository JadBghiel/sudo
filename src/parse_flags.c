/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** parse_flags.c
*/

#include "my_sudo.h"
#include <stdlib.h>

static tuple_t flag_map[MAX_OPTION] = {
    [USER] =
    {
        .flag_char = 'u',
        .add_flag = add_user,
    },
    [GROUP] =
    {
        .flag_char = 'g',
        .add_flag = add_group,
    },
    [ENVIOURMENT] =
    {
        .flag_char = 'E',
        .add_flag = add_env,
    },
    [SHELL] =
    {
        .flag_char = 's',
        .add_flag = add_shell,
    },
};

static void init_flags(sudo_flags_t *to_init)
{
    to_init->env_flag = false;
    to_init->s_flag = false;
    to_init->user = NULL;
    to_init->group = NULL;
    to_init->commands = NULL;
    to_init->shell = NULL;
}

int check_argument(int index, char **args, sudo_flags_t *flags)
{
    if (args[index][0] == '-')
    return 0;
}

sudo_flags_t *parse_flags(int ac, char **args)
{
    sudo_flags_t *flags_present = malloc(sizeof(sudo_flags_t));
    bool flags_end = false;

    if (!flags_present)
        return NULL;
    for (int i = 1; i < ac; i++) {

    }
    return flags_present;
}