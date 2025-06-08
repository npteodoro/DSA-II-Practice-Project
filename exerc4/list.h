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

/**
 * creates a new singly linked list
 * @return pointer to the new list created
*/
list* create_list();

/**
 * frees a previously allocated list
 * @param lst pointer to the list that will be freed 
*/
void free_list(list* lst);

/**
 * inserts a student at the beginning of a list
 * @param lst the list to add the student
 * @param new_student the new student to add
*/
void insert_element(list* lst, student new_student);

/**
 * removes the first student with the specified name from the list
 * @param lst the list that will be searched
 * @param name_to_remove the name of the student to be removed
*/
void remove_element(list* lst, const char* name_to_remove);

/**
 * searches through a list for a specific student name 
 * and the returns a pointer to the found student or NULL 
 * if not found
 * @param lst the list to search
 * @param target_name name of the target student
 * @return pointer to the found student or NULL if not
*/
student* search(list* lst, const char* target_name);

/**
 * copies the contents of a student to another one and 
 * returns it (mainly used to add new students to lists)
 * @param source student to be copied
 * @return new student with the copied informations
*/
student copy_student(const student* source); 

#endif