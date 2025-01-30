/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** main.c
*/

#include "my_sudo.h"

//int main(int ac, char **av)
//{
//    sudo_flags_t *a;
//
//    if (ac < 2)
//        return 84;
//    for (int i = 0; a->commands[i]; i++)
//        printf("%s ", a->commands[i]);
//    printf("\n");
//    return 0;
//}
int main(int argc, char **argv, char **env)
{
    sudo_flags_t *a = parse_arguments(argc, argv);

    printf("%s\n", a->commands);
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
