/*
** EPITECH PROJECT, 2025
** sudoers
** File description:
** sudoers
*/
#include "my_sudo.h"

// read the sudoers file and check if the user belongs to the given alias
int check_user_alias(const char *username, const char *alias)
{
    FILE *file;
    int result;

    file = fopen("/etc/sudoers", "r");
    if (!file) {
        perror("fopen");
        return 0;
    }
    result = search_alias_in_file(file, username, alias);
    fclose(file);
    return result;
}

// search for alias in the sudoers file
int search_alias_in_file(FILE *file, const char *username, const char *alias)
{
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, alias)) {
            return is_username_in_line(line, username);
        }
    }
    return 0;
}

// check if the username is in the tokenized line
int is_username_in_line(const char *line, const char *username)
{
    char *token;
    char line_copy[256];

    strncpy(line_copy, line, sizeof(line_copy));
    line_copy[sizeof(line_copy) - 1] = '\0';
    token = strtok(line_copy, " ");
    while (token) {
        if (strcmp(token, username) == 0) {
            return 1;
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int authenticate_user(const char *username)
{
    const char *encrypted_password;
    char *entered_password;
    int result;

    encrypted_password = get_hashed_password(username);
    if (!encrypted_password) {
        fprintf(stderr, "user not found or error retrieving psswrd\n");
        return 0;
    }
    entered_password = getpass("Password: ");
    result = validate_password(entered_password, encrypted_password);
    if (!result) {
        fprintf(stderr, "authentification failed\n");
    }
    return result;
}

// get the hashed password for the user
const char *get_hashed_password(const char *username)
{
    FILE *shadow_file;
    char line[256];
    char *user;
    char *hash;

    shadow_file = fopen("/etc/shadow", "r");
    if (!shadow_file) {
        perror("fopen");
        return NULL;
    }
    while (fgets(line, sizeof(line), shadow_file)) {
        user = strtok(line, ":");
        if (strcmp(user, username) == 0) {
            hash = strtok(NULL, ":");
            fclose(shadow_file);
            return strdup(hash);
        }
    }
    fclose(shadow_file);
    return NULL;
}
