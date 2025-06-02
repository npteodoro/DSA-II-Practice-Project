#ifndef LIST_H
#define LIST_H 

typedef struct student
{
    char* name;
    char* course;
    unsigned int nusp;
} student;

typedef struct node {
    struct node* nxt;
    student data;
} node;

typedef struct list {
    node* head;
    int list_size;
} list;

list* create_list();
void delete_list(list*);
void insert(list*, student);
void remove(list*, student);
student* search(list*, student);

#endif