#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

#include <time.h>

int head(int N) {
    for (int i = 0; i < N; i++) {
        char line[1024];
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
        if (lines[position] == NULL) {
            fprintf(stderr, "Error al reservar la memoria\n");
            free(lines);
            return 1;
        }
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

int longlines(int N) {
    char **lines = NULL;
    int *lengths = NULL;
    int count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        char *copy = strdup(line);
        if (copy == NULL) {
            fprintf(stderr, "Error al reservar la memoria\n");
            free(lines);
            free(lengths);
            return 1;
        }

        char **tmp_lines = realloc(lines, (count+1)*sizeof(char *));
        int *tmp_lengths = realloc(lengths, (count+1)*sizeof(int));

        lines = tmp_lines;
        lengths = tmp_lengths;
        lines[count] = copy;
        lengths[count] = strlen(copy);
        count++;
    }

    if (lines != NULL && lengths != NULL) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (lengths[j] > lengths[i]) {
                    int temp_len = lengths[i];
                    lengths[i] = lengths[j];
                    lengths[j] = temp_len;
                    char *temp_line = lines[i];
                    lines[i] = lines[j];
                    lines[j] = temp_line;
                }
            }
        }



        int total = N;
        if (count < N) {
            total = count;
        }

        for(int i = 0; i < total; i++) {
            fputs(lines[i], stdout);
            free(lines[i]);
        }
        for (int i = total; i < count; i++) {
            free(lines[i]);
        }
        free(lines);
        free(lengths);
    }
    return 0;
    
}