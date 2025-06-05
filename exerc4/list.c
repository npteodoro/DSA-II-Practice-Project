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

void free_list(list* lst) {
    if(lst == NULL) return;
    node* curr = lst->head;
    while(curr != NULL) {
        node* to_free = curr;
        curr = curr->nxt;
        printf("freeing %s, %s\n", to_free->data.course, to_free->data.name);
        free(to_free->data.course);
        free(to_free->data.name);
        free(to_free);
    }
    free(lst);
}

student copy_student(const student* source) {
    student copy;
    copy.name = malloc( strlen(source->name) + 1 );
    strcpy(copy.name, source->name);

    copy.course = malloc( strlen(source->course) + 1 );
    strcpy(copy.course, source->course);

    copy.nusp = source->nusp;

    return copy;
}

void insert_element(list* lst, student new_student) {
    if(lst == NULL) {
        printf("list does not exist\n");
        return;
    }
    node* new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        return;
    }

    new_node->data = copy_student(&new_student);

    if(lst->head == NULL) {
        lst->head = new_node;
        new_node->nxt = NULL;
        return;
    }

    new_node->nxt = lst->head;
    lst->head = new_node;
    lst->list_size++;
}

void remove_element(list* lst, const char* name_to_remove) {
    if(lst == NULL) {
        printf("list does not exist\n");
        return;
    }

    int remove_pos = 0;
    for(node* curr = lst->head; curr != NULL; curr = curr->nxt) {
        if( strcmp(curr->data.name, name_to_remove) == 0 ) {
            break;
        }
        remove_pos++;
    }

    if(remove_pos == 0) { // element is the head
        node* out = lst->head;
        lst->head = (lst->head->nxt);
        printf("freeing %s, %s\n", out->data.course, out->data.name);
        free(out->data.name);
        free(out->data.course);
        free(out);
        
        return;
    }

    node* prev_out = lst->head;
    while(--remove_pos) {
        prev_out = prev_out->nxt;
    }

    node* out = prev_out->nxt;
    prev_out->nxt = out->nxt;
    printf("freeing %s, %s\n", out->data.course, out->data.name);
    free(out->data.name);
    free(out->data.course);
    free(out);
    lst->list_size--;

}

student* search(list* lst, const char* target_name) {
    if(lst == NULL) {
        return NULL;
    }

    for(node* curr = lst->head; curr != NULL; curr = curr->nxt) {
        if( strcmp(curr->data.name, target_name) == 0 ) {
            //found
            return &(curr->data);
        }
    }

    return NULL;
}