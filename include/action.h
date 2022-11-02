#ifndef ACTION_H
#define ACTION_H

#include "shell.h"
#include "string-vector.h"
#include "string-utils.h"

#define STRING_SIZE 1024

typedef void (*action) (
    struct shell *,
    const struct string_vector *
);

/**
 * @brief Get a action.
 * 
 * @param name name of the action
 * @return the action
 */
extern action get_action(char *name);

/**
 * @brief Do a action given.
 * 
 * @param name name of the action
 * @param this shell
 * @param args command read by the shell
 */
extern void do_action(char *name, struct shell *this, const struct string_vector *args);

/**
 * @brief Exit a shell.
 * 
 * @param this shell
 * @param args command read by the shell
 */
extern void do_exit(struct shell *this, const struct string_vector *args);

/**
 * @brief Change directory.
 * 
 * @param this shell
 * @param args command read by the shell
 */
extern void do_cd(struct shell *this, const struct string_vector *args);

/**
 * @brief Print working directory.
 */
extern void do_pwd();

/**
 * @brief Print help.
 */
extern void do_help();

/**
 * @brief Execute a subshell or a subshell command.
 * 
 * @param this shell
 * @param args command read by the shell
 */
extern void do_system(struct shell *this, const struct string_vector *args);

/**
 * @brief Print a reminder message within a specified time (in seconds). 
 * 
 * @param this shell
 * @param args command read by the shell
 */
extern void do_reminder(struct shell *this, const struct string_vector *args);

/**
 * @brief Show the use of an unknown command.
 */
extern void do_execute();
#endif