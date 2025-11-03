#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int head(int N) {
    for (int i = 0; i < N; i++) {
        char line[100];
        if (fgets(line, sizeof(line), stdin) == NULL)
            break;
        fgets(line, sizeof(line), stdin);
        fputs(line, stdout);
    }
}