/*
** EPITECH PROJECT, 2025
** users
** File description:
** users
*/
#include "my_sudo.h"

int get_user_aliases(char aliases[][256], int max_aliases)
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

int check_user_in_any_alias(const char *username, char aliases[][256],
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

sudo_flags_t *parse_arguments(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-ugEs] command [ARGS]\n", argv[0]);
        exit(84);
    }
    if (!strcmp(argv[1], "-h")) {
        printf("usage: ./my_sudo -h\n");
        printf("usage: ./my_sudo [-ugEs] [command [args ...]]\n");
        exit(0);
    }
    return parse_flags(argc, argv);
}
