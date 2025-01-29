/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** sudo_flags.h
*/

#ifndef MY_SUDO
    #define MY_SUDO
    #include <stdbool.h>
    #include "mylist.h"
    #include "common_lib.h"


typedef enum {
    USER,
    GROUP,
    ENVIOURMENT,
    SHELL,
    MAX_OPTION,
} sudo_options_t;

typedef struct sudo_flags sudo_flags_t;

typedef bool (*add_flag_fn)(sudo_flags_t *, char *, char *);

typedef struct full_flag {
    char *abbreviation;
    char *full_flag;
} full_flag_t;

typedef struct tuple {
    full_flag_t abbreviations;
    add_flag_fn add_flag;
} tuple_t;

typedef struct sudo_flags {
    char *user;
    char *group;
    bool env_flag;
    bool s_flag;
    char **commands;
} sudo_flags_t;

sudo_flags_t *parse_flags(int ac, char **args);

bool add_user(sudo_flags_t *current_flags, char *word, char *next);
bool add_group(sudo_flags_t *current_flags, char *word, char *next);
bool add_env(sudo_flags_t *current_flags, char *word, char *next);
bool add_shell(sudo_flags_t *current_flags, char *word, char *next);

//sudoers/sudoers.c:
int check_user_alias(const char *username, const char *alias);
int search_alias_in_file(FILE *file, const char *username, const char *alias);
int is_username_in_line(const char *line, const char *username);
int authenticate_user(const char *username);
const char *get_hashed_password(const char *username);

//sudoers/password.c:
int validate_password(const char *entered_password,
    const char *encrypted_password);
void execute_command(const char *username, char **const argv);
uid_t get_uid_from_passwd(const char *username);
void run_as_user(const char *username, char **const argv);

//sudoers/users.c:
int get_user_aliases(char aliases[][256], int max_aliases);
int check_user_in_any_alias(const char *username, char aliases[][256],
    int num_aliases);
void fill_command(char **argv, int start, int argc, char **command);
void parse_arguments(int argc, char **argv, char **target_user,
    char **command);

#endif
