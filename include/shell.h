#ifndef SHELL_H
#define SHELL_H

struct shell {
    int running;
    int line_number;
    size_t buffer_size;
    char *buffer;
};

#include "shell-utils.h"

#endif