/*
** EPITECH PROJECT, 2024
** my_sudo
** File description:
** verify_user.c
*/

#include "my_sudo.h"

int ask_password(sudo_flags_t *flags)
{
    for (int i = 0; i < 3; i++) {
        if (authenticate_user(flags->current_user->name))
            return 0;
    }
    return 1;
}
