#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list* create_list() {
    list* new_list = malloc(sizeof(*new_list));
    if(new_list == NULL) return NULL;

    new_list->list_size = 0;
    new_list->head = NULL;

    return new_list;
}

void delete_list(list* lst) {

}

void insert(list* lst, student new_student) {
    if(lst == NULL) {
        printf("list does not exist\n");
        return;
    }
    node* new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        return;
    }
    new_node->data = new_student;
    if(lst->head == NULL) {
        lst->head = new_node;
        new_node->nxt = NULL;
        return;
    }

    new_node->nxt = lst->head;
    lst->head = new_node;
}

void remove(list* lst, student to_be_removed) {
    if(lst == NULL) {
        printf("list does not exist\n");
        return;
    }

    int remove_pos = 0;
    for(node* curr = lst->head; curr != NULL; curr = curr->nxt) {
        if( strcmp(curr->data.name, to_be_removed.name) == 0 ) {
            break;
        }
        remove_pos++;
    }

    if(remove_pos == 0) { // element is the head
        node* out = lst->head;
        lst->head = (lst->head->nxt);
        free(out);
        return;
    }

    node* prev_out = lst->head;
    while(--remove_pos) {
        node* prev_out = prev_out->nxt;
    }

    node* out = prev_out->nxt;
    prev_out->nxt = out->nxt;
    free(out);

}

student* search(list* lst, student target) {
    if(lst == NULL) {
        return NULL;
    }

    for(node* curr = lst->head; curr != NULL; curr = curr->nxt) {
        if( strcmp(curr->data.name, target.name) == 0 ) {
            //found
            return &(curr->data);
        }
    }

    return NULL;
}