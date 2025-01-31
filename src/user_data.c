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

void wrong_user(sudo_flags_t *flags)
{
    if (flags->user == NULL)
        flags->user = "";
    fprintf(stderr, "sudo: unknown user %s\n", flags->user);
    destroy_flags(flags);
    exit(84);
}

int validate_user(sudo_flags_t *flags)
{
    char line[256];
    char *user;
    FILE *passwd_file = fopen("/etc/passwd", "r");

    if (flags->user == NULL) {
        flags->user = getlogin();
        return 1;
    }
    if (!passwd_file)
        wrong_user(flags);
    while (fgets(line, sizeof(line), passwd_file)) {
        user = strtok(line, ":");
        printf("%s\n", user);
        if (!strcmp(user, flags->user))
            return 1;
    }
    fclose(passwd_file);
    wrong_user(flags);
    return 0;
}

