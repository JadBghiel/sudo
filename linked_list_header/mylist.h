/*
** EPITECH PROJECT, 2024
** linked_list struct
** File description:
** Contains the struct declaration for linked lists
*/

#ifndef MYLIST_H
    #define MYLIST_H
typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;
linked_list_t *create_node(void *, linked_list_t *);
int add_node(linked_list_t *, linked_list_t *);
int delete_node(linked_list_t *, linked_list_t *);
void *pop_node(linked_list_t *);
linked_list_t *append_node(void *, linked_list_t *);
int list_len(linked_list_t *);
linked_list_t *get_node(linked_list_t *, int);
linked_list_t *swap_nodes(linked_list_t *, int, int);
int clear_list(linked_list_t *root);
#endif /* MYLIST_H */
