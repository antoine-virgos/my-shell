#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(void) {
    struct shell shell;

    shell_init(&shell);
    shell_run(&shell);
    shell_destroy(&shell);

    return 0;
}