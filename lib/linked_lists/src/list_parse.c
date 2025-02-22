/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** linked_lists2.c
*/

#include "../include/mylist.h"
#include <stdlib.h>

int list_len(linked_list_t *root)
{
    int length = 0;

        while (root != NULL) {
            length++;
            root = root->next;
        }
    return length;
}

int clear_list(linked_list_t *root)
{
    int initial_length = list_len(root);

    for (int i = 0; i < initial_length; i++)
        free(pop_node(root));
    return 1;
}

linked_list_t *get_node(linked_list_t *root, int pos)
{
    linked_list_t *current_node = root;

    if (pos < 0)
        return NULL;
    for (int i = 0; i < pos && current_node != NULL; i++) {
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return NULL;
    }
    return current_node;
}

//untested
linked_list_t *swap_nodes(linked_list_t *root, int pos1, int pos2)
{
    linked_list_t *first_node = get_node(root, pos1);
    linked_list_t *second_node = get_node(root, pos2);
    linked_list_t *prev_first = get_node(root, pos1 - 1);
    linked_list_t *after_first = get_node(root, pos1 + 1);
    linked_list_t *prev_second = get_node(root, pos2 - 1);
    linked_list_t *after_second = get_node(root, pos2 + 1);

    if (pos1 == 0)
        root = first_node;
    else
        prev_first->next = second_node;
    if (pos2 == 0)
        root = second_node;
    else
        prev_second->next = first_node;
    first_node->next = after_second;
    second_node->next = after_first;
    return root;
}
