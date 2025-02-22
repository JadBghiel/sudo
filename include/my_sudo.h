/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** sudo_flags.h
*/

#ifndef MY_SUDO
    #define MY_SUDO
    #define MAX_GROUPS 16
    #define ALIAS_LENGTH 256
    #include <stdbool.h>
    #include <sys/stat.h>
    #include "mylist.h"
    #include "common_lib.h"

typedef struct user {
    char *name;
    uid_t uid;
} user_t;

typedef struct my_group {
    char **names;
    gid_t groups[MAX_GROUPS];
} my_groups_t;

typedef enum {
    USER,
    GROUP,
    ENVIOURMENT,
    SHELL,
    MAX_OPTION,
} sudo_options_t;

typedef struct sudo_flags sudo_flags_t;

typedef bool (*add_flag_fn_t)(sudo_flags_t *, char *, char *);

typedef struct full_flag {
    char *abbreviation;
    char *full_flag;
} full_flag_t;

typedef struct tuple {
    full_flag_t abbreviations;
    add_flag_fn_t add_flag;
} tuple_t;

typedef struct sudo_flags {
    bool env_flag;
    bool s_flag;
    char *commands;
    user_t *current_user;
    my_groups_t *current_groups;
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
void execute_command(const char *username, gid_t *group, char *command);
uid_t get_uid_from_passwd(const char *username);
void run_as_user(const char *username, char **const argv);

//sudoers/users.c:
int get_user_aliases(my_groups_t *groups);
int check_user_in_any_alias(const char *username, char aliases[][200],
    int num_aliases);
void fill_command(char **argv, int start, int argc, char **command);
sudo_flags_t *parse_arguments(int argc, char **argv);
void destroy_flags(sudo_flags_t *to_destroy);
int validate_user(sudo_flags_t *flags);
int validate_group(sudo_flags_t *flags);
int ask_password(sudo_flags_t *flags);
char *get_group_by_gid(gid_t current_gid);

#endif
