/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** user_data.c
*/

#include "my_sudo.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void wrong_entity(sudo_flags_t *flags, char *entity, char *unknown)
{
    fprintf(stderr, "my_sudo: unknown %s %s\n", entity, unknown);
    destroy_flags(flags);
    exit(84);
}

int validate_user(sudo_flags_t *flags)
{
    char line[256];
    char *user;
    FILE *passwd_file = fopen("/etc/passwd", "r");

    if (flags->current_user->name == NULL) {
        flags->current_user->name = strdup("root");
        flags->current_user->uid = 0;
        return 1;
    }
    if (!passwd_file)
        wrong_entity(flags, "user", flags->current_user->name);
    while (fgets(line, sizeof(line), passwd_file)) {
        user = strtok(line, ":");
        if (!strcmp(user, flags->current_user->name))
            return 1;
    }
    fclose(passwd_file);
    wrong_entity(flags, "user", flags->current_user->name);
    return 0;
}

int validate_group(sudo_flags_t *flags)
{
    char line[ALIAS_LENGTH];
    char *group;
    FILE *group_file = fopen("/etc/group", "r");

    if (flags->current_groups->names[0] == 0) {
        flags->current_groups->groups[0] = 0;
        flags->current_groups->names[0] = strdup("root");
        return 1;
    }
    if (!group_file)
        wrong_entity(flags, "group", flags->current_groups->names[0]);
    while (fgets(line, sizeof(line), group_file)) {
        group = strtok(line, ":");
        if (!strcmp(group, flags->current_groups->names[0]))
            return 1;
    }
    fclose(group_file);
    wrong_entity(flags, "group", flags->current_groups->names[0]);
    return 0;
}
