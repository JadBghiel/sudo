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
    if (flags->user == NULL)
        flags->user = "";
    fprintf(stderr, "my_sudo: unknown %s %s\n", entity, unknown);
    destroy_flags(flags);
    exit(84);
}

int validate_user(sudo_flags_t *flags)
{
    char line[256];
    char *user;
    FILE *passwd_file = fopen("/etc/passwd", "r");

    if (flags->user == NULL) {
        flags->user = strdup("root");
        return 1;
    }
    if (!passwd_file)
        wrong_entity(flags, "user", flags->user);
    while (fgets(line, sizeof(line), passwd_file)) {
        user = strtok(line, ":");
        if (!strcmp(user, flags->user))
            return 1;
    }
    fclose(passwd_file);
    wrong_entity(flags, "user", flags->user);
    return 0;
}

int validate_group(sudo_flags_t *flags)
{
    char line[256];
    char *group;
    FILE *group_file = fopen("/etc/group", "r");

    if (flags->group == NULL) {
        flags->user = strdup("root");
        return 1;
    }
    if (!group_file)
        wrong_entity(flags, "group", flags->group);
    while (fgets(line, sizeof(line), group_file)) {
        group = strtok(line, ":");
        if (!strcmp(group, flags->group))
            return 1;
    }
    fclose(group_file);
    wrong_entity(flags, "group", flags->group);
    return 0;
}
