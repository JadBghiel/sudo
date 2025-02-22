/*
** EPITECH PROJECT, 2024
** linked_lists
** File description:
** A file to create, add nodes to a linked list
*/

#include "../include/mylist.h"
#include "mylist.h"
#include <stdlib.h>

linked_list_t *create_node(void *data, linked_list_t *next)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    if (node == NULL)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

int add_node(linked_list_t *node, linked_list_t *new_node)
{
    linked_list_t *old_node = node->next;

    if (node == NULL || new_node == NULL) {
        return 0;
    }
    if (old_node != NULL) {
        free(old_node);
    }
    node->next = new_node;
    return 1;
}

int delete_node(linked_list_t *root, linked_list_t *to_delete)
{
    linked_list_t *current_node = root;

    while (1) {
        if (current_node == to_delete) {
            free(current_node);
            return 1;
        }
        if (current_node->next == to_delete) {
            free(current_node->next);
            current_node->next = NULL;
            return 1;
        }
        if (current_node == NULL)
            return 0;
        current_node = current_node->next;
    }
    return 0;
}

void *pop_node(linked_list_t *root)
{
    linked_list_t *current_node = root;
    void *data;

    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    data = current_node->data;
    delete_node(root, current_node);
    return data;
}

linked_list_t *append_node(void *data, linked_list_t *root)
{
    linked_list_t *current_node = root;
    linked_list_t *new_node = create_node(data, NULL);

    if (root == NULL) {
        return new_node;
    }
    while (current_node->next != NULL)
        current_node = current_node->next;
    add_node(current_node, new_node);
    return root;
}
