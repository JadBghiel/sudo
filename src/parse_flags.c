/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** parse_flags.c
*/

#include "my_sudo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static tuple_t flag_map[MAX_OPTION] = {
    [USER] =
    {
        .abbreviations =
            {
                "-u",
                "--user",
            },
        .add_flag = add_user,
    },
    [GROUP] =
    {
        .abbreviations =
            {
                "-g",
                "--group",
            },
        .add_flag = add_group,
    },
    [ENVIOURMENT] =
    {
        .abbreviations =
            {
                "-E",
                "--preserve-env",
            },
        .add_flag = add_env,
    },
    [SHELL] =
    {
        .abbreviations =
            {
                "-s",
                "--shell",
            },
        .add_flag = add_shell,
    },
};

static add_flag_fn get_flag_fn(char *arg)
{
    for (int i = 0; i < MAX_OPTION; i++) {
        if (!strcmp(flag_map[i].abbreviations.abbreviation, arg) || !strcmp(
            flag_map[i].abbreviations.full_flag, arg)) {
            return flag_map[i].add_flag;
        }
    }
    return NULL;
}

static void init_flags(sudo_flags_t *to_init)
{
    to_init->env_flag = false;
    to_init->s_flag = false;
    to_init->user = NULL;
    to_init->group = NULL;
    to_init->commands = NULL;
}

void destroy_flags(sudo_flags_t *to_destroy)
{
    free(to_destroy->commands);
    free(to_destroy);
}

static void validate_flags(sudo_flags_t *current)
{
    if (current->user == current->commands[0] || current->group ==
        current->commands[0]) {
        destroy_flags(current);
        exit(84);
    }
    if (get_flag_fn(current->commands[0]) != NULL) {
        destroy_flags(current);
        exit(84);
    }
}

bool check_argument(int index, char **args, sudo_flags_t *flags)
{
    add_flag_fn current_fn = get_flag_fn(args[index]);

    if (!current_fn && (get_flag_fn(args[index - 1]) == flag_map[USER].add_flag
        || get_flag_fn(args[index - 1]) == flag_map[GROUP].add_flag))
        return false;
    if (!current_fn)
        return true;
    if (!current_fn(flags, args[index], args[index + 1]))
        exit(84);
    return false;
}

sudo_flags_t *parse_flags(int ac, char **args)
{
    sudo_flags_t *flags_present = malloc(sizeof(sudo_flags_t));
    bool flags_end = false;
    int i;

    init_flags(flags_present);
    if (!flags_present)
        return NULL;
    for (i = 1; i < (ac - 1) && !flags_end; i++)
        flags_end = check_argument(i, args, flags_present);
    if (flags_end)
        i--;
    flags_present->commands = calloc(ac - i, sizeof(char *));
    for (int j = 0; i < ac; i++) {
        flags_present->commands[j] = args[i];
        j++;
    }
    validate_flags(flags_present);
    return flags_present;
}