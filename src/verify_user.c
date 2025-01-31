/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** verify_user.c
*/

#include "my_sudo.h"
#include <grp.h>
#include <unistd.h>

int ask_password(sudo_flags_t *flags)
{
    if (!flags->current_user->uid && !flags->current_groups->groups[0]) {
        setgroups(0, NULL);
    }
    if (getuid() == 0)
        return 0;
    for (int i = 0; i < 3; i++) {
        if (authenticate_user(getlogin()))
            return 0;
    }
    return 1;
}
