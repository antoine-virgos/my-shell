#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell-utils.h"

void shell_init(struct shell *s) {
    s->running = 1;
    s->line_number = 0;
    s->buffer_size = 256;
    s->buffer = malloc(s->buffer_size * sizeof(char));
}

void shell_run(struct shell *s) {
    while(s->running == 1) {
        shell_read_line(s);
        shell_execute_line(s);
    }
}

void shell_destroy(struct shell *s) {
    free(s->buffer);
    s->buffer = NULL;
}

void shell_read_line(struct shell *s) {
    shell_prompt(s);
    
    fgets(s->buffer, s->buffer_size, stdin);

    ++s->line_number; 
}

void shell_prompt(struct shell *s) {
    char *cwd = malloc(STRING_SIZE * sizeof(char));
    getcwd(cwd, STRING_SIZE);

    char *user = getenv("USER");

    char *home = getenv("HOME");

    if (strstr(cwd, home) != NULL) {
        char *cwd_replace = strreplace(cwd, home, "~");

        printf("%d|%s%s:%s%s%s $ ", s->line_number, CYN, user, GRN, cwd_replace, RESET);

        free(cwd_replace);
    } else {
        printf("%d|%s%s:%s%s%s $ ", s->line_number, CYN, user, GRN, cwd, RESET);
    }

    fflush(stdout);

    free(cwd);
}

void shell_execute_line(struct shell *s) {
    struct string_vector tokens = split_line(s->buffer);
    size_t tokens_number = string_vector_size(&tokens);

    if (tokens_number == 0) {
        string_vector_free(&tokens);
        return;
    } else {
        char *first_token = string_vector_get(&tokens, 0);

        do_action(first_token, s, &tokens);
    }

    string_vector_free(&tokens);
}