/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** main.c
*/

#include "my_sudo.h"


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
/*
int main(int argc, char **argv)
{
    char aliases[100][256];
    int num_aliases;
    char *target_user = NULL;
    char *command[argc];
    char *real_user;

    parse_arguments(argc, argv, &target_user, command);
    real_user = getlogin();
    num_aliases = get_user_aliases(aliases, 100);
    if (check_user_in_any_alias(real_user, aliases, num_aliases)) {
        fprintf(stderr, "user %s is not allowed to run the command\n",
            real_user);
        return 1;
    }
    printf("[my_sudo] password for %s: ", real_user);
    if (!authenticate_user(real_user)) {
        return 1;
    }
    execute_command(target_user, command);
    return 0;
}
*/
