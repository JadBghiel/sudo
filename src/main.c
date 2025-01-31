/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** main.c
*/

#include "my_sudo.h"
#include <unistd.h>
#include <grp.h>

int main(int argc, char **argv, char **env)
{
    sudo_flags_t *flags = parse_arguments(argc, argv);

    validate_user(flags);
    validate_group(flags);
    if (ask_password(flags)) {
        fprintf(stderr, "sudo: 3 incorrect password attempts\n");
        return 84;
    }
    execute_command(flags->current_user->name, flags->current_groups->groups,
        flags->commands);
    return 0;
}
