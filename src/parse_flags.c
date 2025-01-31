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

static const tuple_t flag_map[MAX_OPTION] = {
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

static add_flag_fn_t get_flag_fn(char *arg)
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
    to_init->current_user = calloc(1, sizeof(user_t));
    to_init->current_groups = calloc(1, sizeof(groups_t));
    to_init->commands = calloc(BUFSIZ, 1);
    to_init->current_user->name = NULL;
    to_init->current_groups->names = calloc(MAX_GROUPS, ALIAS_LENGTH);
}

void destroy_flags(sudo_flags_t *to_destroy)
{
    free(to_destroy->commands);
    free(to_destroy);
}

static void display_usage(sudo_flags_t *flags)
{
    fprintf(stderr, "usage: ./my_sudo -h\n");
    fprintf(stderr, "usage: ./my_sudo [-ugEs] [command [args ...]]\n");
    destroy_flags(flags);
    exit(84);
}

static void validate_flags(sudo_flags_t *current)
{
    if (current->commands[0] == 0 && !current->s_flag)
        display_usage(current);
}

int check_argument(int index, char **args, sudo_flags_t *flags, int ac)
{
    add_flag_fn_t current_fn = get_flag_fn(args[index]);

    if (index == ac - 1 && (current_fn == flag_map[USER].add_flag ||
        current_fn == flag_map[GROUP].add_flag))
        display_usage(flags);
    if (args[index][0] == '-' && !current_fn)
        display_usage(flags);
    if (!current_fn && (get_flag_fn(args[index - 1]) == flag_map[USER].add_flag
        || get_flag_fn(args[index - 1]) == flag_map[GROUP].add_flag))
        return false;
    if (!current_fn) {
        if (flags->commands[0])
            strcat(flags->commands, " ");
        strcat(flags->commands, args[index]);
        return true;
    }
    if (!current_fn(flags, args[index], args[index + 1])) {
        display_usage(flags);
    }
    return false;
}

sudo_flags_t *parse_flags(int ac, char **args)
{
    sudo_flags_t *flags_present = malloc(sizeof(sudo_flags_t));

    init_flags(flags_present);
    if (!flags_present)
        return NULL;
    for (int i = 1; i < ac; i++) {
        check_argument(i, args, flags_present, ac);
    }
    validate_flags(flags_present);
    return flags_present;
}
