#ifndef COMMANDS_H
#define COMMANDS_H


/**
 * @brief Creates a new hash table with specified size and saves it to a file
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments
 * @return 0 on success, 1 on failure
 */
int criarCommand(int argc, char *argv[]);

/**
 * @brief Inserts students from a formatted string into a hash table file
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments
 * @return 0 on success, 1 on failure
 */
int inserirCommand(int argc, char *argv[]);

/**
 * @brief Searches for students by NUSP in a hash table file
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments
 * @return 0 on success, 1 on failure
 */
int buscarCommand(int argc, char *argv[]);

/**
 * @brief Removes students by NUSP from a hash table file
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments
 * @return 0 on success, 1 on failure
 */
int removerCommand(int argc, char *argv[]);

#endif // COMMANDS_H