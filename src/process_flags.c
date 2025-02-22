/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** process_flags.c
*/

#include "my_sudo.h"
#include <stdbool.h>
#include <stdlib.h>

bool add_user(sudo_flags_t *current_flags, char *word, char *next)
{
    if (current_flags->commands[0] != 0)
        return false;
    if (current_flags->current_user->name != NULL)
        return false;
    current_flags->current_user->name = strdup(next);
    return true;
}

bool add_group(sudo_flags_t *current_flags, char *word, char *next)
{
    if (current_flags->commands[0] != 0)
        return false;
    if (current_flags->current_groups->names[0] != 0)
        return false;
    current_flags->current_groups->names[0] = strdup(next);
    return true;
}

bool add_env(sudo_flags_t *current_flags, char *word, char *next)
{
    if (current_flags->commands[0] != 0)
        return false;
    if (current_flags->env_flag == true)
        return false;
    current_flags->env_flag = true;
    return true;
}

bool add_shell(sudo_flags_t *current_flags, char *word, char *next)
{
    if (current_flags->commands[0] != 0)
        return false;
    if (current_flags->s_flag == true)
        return false;
    current_flags->s_flag = true;
    return true;
}
