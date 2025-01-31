/*
** EPITECH PROJECT, 2025
** password
** File description:
** password
*/
#include "my_sudo.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

// prompt for the user's password and validate it
int validate_password(const char *entered_password,
    const char *encrypted_password)
{
    char *hashed_password;

    hashed_password = crypt(entered_password, encrypted_password);
    if (strcmp(hashed_password, encrypted_password) == 0) {
        return 1;
    }
    return 0;
}

// execute the given command as the specified user
void execute_command(const char *username, gid_t *group, char *current)
{
    setuid(get_uid_from_passwd(username));
    seteuid(get_uid_from_passwd(username));
    setgid(group[0]);
    setegid(group[0]);
    system(current);
}

// get UID from /etc/passwd file
uid_t get_uid_from_passwd(const char *username)
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

char *get_group_by_gid(gid_t current_gid)
{
    FILE *file = fopen("/etc/group", "r");
    char line[ALIAS_LENGTH];
    char *line_gid;
    char *correct_group = NULL;
    char *group;

    while (fgets(line, sizeof(line), file)) {
        group = strdup(strtok(line, ":"));
        strtok(line, ":");
        line_gid = strtok(line, ":");
        if (atoi(line_gid) == current_gid) {
            strtok(NULL, ":");
            correct_group = group;
            break;
        }
    }
    fclose(file);
    return correct_group;
}

void run_as_user(const char *username, char **const argv)
{
    uid_t uid;

    uid = get_uid_from_passwd(username);
    if (uid == (uid_t)-1) {
        fprintf(stderr, "user not found\n");
        _exit(1);
    }
    if (setuid(uid) != 0) {
        perror("setuid");
        _exit(1);
    }
    execvp(argv[0], argv);
    perror("execvp");
    _exit(1);
}
