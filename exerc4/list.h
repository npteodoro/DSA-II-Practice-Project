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
void free_list(list*);
void insert_element(list*, student);
void remove_element(list*, const char*);
student* search(list*, const char*);
student copy_student(const student*); 

#endif