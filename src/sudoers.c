/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** process_flags.c
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
void execute_command(const char *username, char **const argv)
{
    char command[1024] = "";
    strcat(command, "sudo -u ");
    strcat(command, username);
    strcat(command, " ");
    for (int i = 0; argv[i] != NULL; i++) {
        strcat(command, argv[i]);
        strcat(command, " ");
    }
    system(command);
}

// change user and execute command
void run_as_user(const char *username, char **const argv)
{
    struct passwd *pw;
    uid_t uid;

    pw = getpwnam(username); // getpw* not allowed
    if (!pw) {
        fprintf(stderr, "user not found\n");
        _exit(1);
    }
    uid = pw->pw_uid;
    if (setuid(uid) != 0) {
        perror("setuid");
        _exit(1);
    }
    execvp(argv[0], argv);
    perror("execvp");
    _exit(1);
}

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

int main(int argc, char *argv[])
{
    char aliases[100][256];
    int num_aliases;
    char *target_user = NULL;
    char *command[argc];
    int cmd_index = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-u user] command\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-u") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s [-u user] command\n", argv[0]);
            return 1;
        }
        target_user = argv[2];
        for (int i = 3; i < argc; i++) {
            command[cmd_index++] = argv[i];
        }
    } else {
        target_user = getlogin();
        for (int i = 1; i < argc; i++) {
            command[cmd_index++] = argv[i];
        }
    }
    command[cmd_index] = NULL;

    char *real_user = getlogin();
    num_aliases = get_user_aliases(aliases, 100);

    if (check_user_in_any_alias(real_user, aliases, num_aliases) == 1) {
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
