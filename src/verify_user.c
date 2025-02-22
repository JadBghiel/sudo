/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** verify_user.c
*/

#include "my_sudo.h"
#include <grp.h>
#include <unistd.h>

static uid_t get_gid_from_passwd(const char *username)
{
    FILE *file;
    char line[256];
    uid_t uid = -1;
    char *user;

    file = fopen("/etc/passwd", "r");
    while (fgets(line, sizeof(line), file)) {
        user = strtok(line, ":");
        if (strcmp(user, username) == 0) {
            strtok(NULL, ":");
            uid = (uid_t)atoi(strtok(NULL, ":"));
            break;
        }
    }
    fclose(file);
    return uid;
}

int ask_password(sudo_flags_t *flags)
{
    setgroups(0, NULL);
    initgroups(flags->current_user->name, get_gid_from_passwd(
        flags->current_user->name));
    setgid(get_gid_from_passwd(flags->current_user->name));
    setegid(get_gid_from_passwd(flags->current_user->name));
    if (getuid() == 0)
        return 0;
    for (int i = 0; i < 3; i++) {
        if (authenticate_user(getlogin()))
            return 0;
    }
    return 1;
}
