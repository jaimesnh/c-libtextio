#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int head(int N) {
    for (int i = 0; i < N; i++) {
        char line[100];
        if (fgets(line, sizeof(line), stdin) != NULL) {
            fputs(line, stdout);
        } else {
            break;
        }
    }
    return 0;
}

int tail(int N){
    char **lines = malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        lines[i] = NULL;
    }
    char line[1024];
    int count = 0;
    while (fgets(line, sizeof(line), stdin) != NULL) {
        int position = count % N;
        free(lines[position]);
        lines[position] = strdup(line);
        count ++;
    }

    int total = N;
    if (count < N) {
        total = count;
    }

    int start = 0;
    if (count > N) {
        start = count % N;
    }
    for (int i = 0; i < total; i++) {
        int index = (i + start) % N;
        fputs(lines[index], stdout);
        free(lines[index]);
    }
    free(lines);
    return 0;
}