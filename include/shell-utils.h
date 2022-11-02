#ifndef SHELL_UTILS_H
#define SHELL_UTILS_H

#include "shell.h"
#include "string-utils.h"
#include "action.h"

#define STRING_SIZE 1024

// colors
#define CYN "\x1B[36m"
#define GRN "\x1B[32m"
#define RESET "\x1B[0m"

/**
 * @brief Initialize a shell.
 * 
 * @param s shell to initialize
 */
extern void shell_init(struct shell *s);

/**
 * @brief Run a shell.
 * 
 * @param s shell to run
 */
extern void shell_run(struct shell *s);

/**
 * @brief Destroy a shell.
 * 
 * @param s shell to destroy
 */
extern void shell_destroy(struct shell *s);

/**
 * @brief Read a line of a shell.
 * 
 * @param s shell for which the line is read
 */
extern void shell_read_line(struct shell *s);

/**
 * @brief Display a shell prompt.
 * 
 * @param s shell for which the prompt is displayed
 */
extern void shell_prompt(struct shell *s);

/**
 * @brief Interpret and execute a line of a shell.
 * 
 * @param s shell for which the line is interpreted and executed
 */
extern void shell_execute_line(struct shell *s);
#endif