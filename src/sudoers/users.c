/*
** EPITECH PROJECT, 2025
** users
** File description:
** users
*/
#include "my_sudo.h"

int get_user_aliases(char aliases[][200], int max_aliases)
{
    FILE *file;
    char line[256];
    int alias_count = 0;

    file = fopen("/etc/sudoers", "r");
    if (!file) {
        perror("fopen");
        return 0;
    }
    while (fgets(line, sizeof(line), file) && alias_count < max_aliases) {
        if (line[0] == '%' || line[0] == '#') {
            sscanf(line, "%[^ \t\n]", aliases[alias_count++]);
        }
    }
    fclose(file);
    return alias_count;
}

int check_user_in_any_alias(const char *username, char aliases[][200],
    int num_aliases)
{
    for (int i = 0; i < num_aliases; i++) {
        if (check_user_alias(username, aliases[i])) {
            return 1;
        }
    }
    return 0;
}

void fill_command(char **argv, int start, int argc, char **command)
{
    int cmd_index = 0;

    for (int i = start; i < argc; i++) {
        command[cmd_index] = argv[i];
        cmd_index++;
    }
    command[cmd_index] = NULL;
}

void parse_arguments(int argc, char **argv, char **target_user, char **command)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-u user] command\n", argv[0]);
        exit(1);
    }
    if (strcmp(argv[1], "-u") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s [-u user] command\n", argv[0]);
            exit(1);
        }
        *target_user = argv[2];
        fill_command(argv, 3, argc, command);
    } else {
        *target_user = getlogin();
        fill_command(argv, 1, argc, command);
    }
}
