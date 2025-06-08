#ifndef STUDENT_H
#define STUDENT_H

struct HashTable; // Forward declaration of HashTable structure
/**
 * @brief Structure representing a student
 */
struct Student {
    unsigned int nusp;  /**< Unique student ID number (NUSP) */
    char *name;         /**< Student's name (dynamically allocated) */
    char *course;       /**< Student's course (dynamically allocated) */
};

/**
 * @brief Frees all resources associated with a student object.
 * @param student Pointer to the student object to free.
 */
void freeStudent(struct Student *student);

/**
 * @brief Creates a new student object with the provided information.
 * @param nusp The student's unique ID number.
 * @param name The student's name.
 * @param course The student's course.
 * @return Pointer to the newly created student object.
 */
struct Student* createStudent(unsigned int nusp, const char *name, const char *course);

/**
 * @brief Inserts a new student into the hash table.
 * @param table Pointer to the hash table.
 * @param nusp Student's unique ID number.
 * @param name Student's name.
 * @param course Student's course.
 * @return 1 if insertion is successful, 0 otherwise.
 */
int insertStudent(struct HashTable *table, unsigned int nusp, const char *name, const char *course);

/**
 * @brief Searches for a student by NUSP in the hash table.
 * @param table Pointer to the hash table.
 * @param nusp Student's unique ID to search for.
 * @return Pointer to the found student or NULL if not found.
 */
struct Student* searchStudent(struct HashTable *table, unsigned int nusp);

/**
 * @brief Deletes a student from the hash table.
 * @param table Pointer to the hash table.
 * @param nusp Student's unique ID to delete.
 * @return 1 if deletion is successful, 0 otherwise.
 */
int deleteStudent(struct HashTable *table, unsigned int nusp);

#endif // STUDENT_H