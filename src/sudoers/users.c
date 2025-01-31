/*
** EPITECH PROJECT, 2025
** users
** File description:
** users
*/
#include "my_sudo.h"

int is_group_in_struct(const char *group, my_groups_t *groups)
{
    for (int i = 0; i < MAX_GROUPS; ++i) {
        if (groups->names[i] && strcmp(group, groups->names[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int process_group_line(const char *line, my_groups_t *groups)
{
    char group[200];

    if (line[0] == '%') {
        sscanf(line, "%%%s", group);
        if (is_group_in_struct(group, groups)) {
            return 1;
        }
    }
    return 0;
}

int get_user_aliases(my_groups_t *groups)
{
    FILE *file;
    char line[256];

    file = fopen("/etc/sudoers", "r");
    if (!file) {
        perror("fopen");
        return 0;
    }
    while (true) {
        if (process_group_line(line, groups)) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
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
