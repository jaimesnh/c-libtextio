#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

#include <time.h>

// Función head: Muestra las primeras N líneas de la entrada estándar stdin
int head(int N) {
    for (int i = 0; i < N; i++) {
        char line[1024]; // Buffer para almacenar temporalmente una línea
        if (fgets(line, sizeof(line), stdin) != NULL) { // Lee la línea de la entrada estandar stdin
            fputs(line, stdout); // Escribe la línea leída en la salida estándar stdout
        } else {
            break; // Si llega al EOF antes de N líneas, detiene el bucle
        }
    }
    return 0;
}

// Función tail: Muestra las últimas N líneas de la entrada estándar
int tail(int N){
    // Reserva memoria para un array de N punteros a char para almacenar las N líneas
    char **lines = malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        lines[i] = NULL;
    }
    char line[1024]; // Buffer temporal para la línea actual
    int count = 0;

    // Bucle para leer todas las líneas de la entrada
    while (fgets(line, sizeof(line), stdin) != NULL) {
        int position = count % N; // Calcula la posición en el buffer circular
        free(lines[position]);
        lines[position] = strdup(line); // Copia dinámicamente la línea actual al buffer
        if (lines[position] == NULL) {
            fprintf(stderr, "Error al reservar la memoria\n");
            free(lines);
            return 1;
        }
        count ++;
    }

    // Si se leen menos de N líneas, solo se imprime count líneas
    int total = N;
    if (count < N) {
        total = count;
    }

    // Si se leen más de N líneas (count > N), calcula el índice de la línea más antigua
    int start = 0;
    if (count > N) {
        start = count % N;
    }
    // Bucle para imprimir las últimas N líneas
    for (int i = 0; i < total; i++) {
        int index = (i + start) % N;
        fputs(lines[index], stdout);
        free(lines[index]); // Libera la memoria de la línea después de imprimir
    }
    free(lines); // Libera el array principal de punteros
    return 0;
}

int longlines(int N) {
    char **lines = NULL; // Array de punteros a líneas
    int *lengths = NULL; // Array para almacenar la longitud de cada línea
    int count = 0;
    char line[1024]; // Buffer temporal para la línea actual

    // Lee todas las líneas de la entrada
    while (fgets(line, sizeof(line), stdin) != NULL) {
        char *copy = strdup(line);
        if (copy == NULL) {
            fprintf(stderr, "Error al reservar la memoria\n");
            free(lines);
            free(lengths);
            return 1;
        }

        char **tmp_lines = realloc(lines, (count+1)*sizeof(char *)); // Redimensiona dinámicamente el array de punteros para añadir uno más
        int *tmp_lengths = realloc(lengths, (count+1)*sizeof(int)); // Redimensiona dinámicamente el array de longitudes para añadir un entero más

        // Asigna el nuevo puntero en ambos arrays
        lines = tmp_lines;
        lengths = tmp_lengths;
        
        lines[count] = copy; // Almacena el puntero a la nueva línea copiada
        lengths[count] = strlen(copy); // Almacena la longitud de la línea
        count++;
    }

    // Algoritmo de ordanemiento
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

        // Determina cuántas líneas imprimir
        int total = N;
        if (count < N) {
            total = count;
        }

        // Escribe las N líneas más largas en stdout y libera la memoria de las lineas escritas
        for(int i = 0; i < total; i++) {
            fputs(lines[i], stdout);
            free(lines[i]);
        }
        // Libera la memoria de las lineas restantes
        for (int i = total; i < count; i++) {
            free(lines[i]);
        }
        // Libera el array principal de punteros y el de longitudes
        free(lines);
        free(lengths);
    }
    return 0;
    
}
