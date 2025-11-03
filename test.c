#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int main(int argc, char *argv[]) {
    int N = 10;

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Numero de argumentos incorrecto.\n");
        fprintf(stderr, "Uso: %s -<funcion> [numero_de_lineas]\n", argv[0]);
        return 1;
    } else if (argc == 3) {
        N = atoi(argv[2]);
        if (N <= 0) {
            fprintf(stderr, "Error: El numero de lineas debe ser un entero mayor que 0.\n");
            return 1;
        }

    }
    if (argv[1][0] != '-') {
        fprintf(stderr, "Error: El nombre de la funcion debe empezar con un guion '-'.\n");
        return 1;
    }
    if (strcmp(argv[1], "-head") == 0) {
        head(N);
    } else if (strcmp(argv[1], "-tail") == 0) {
        tail(N);
    }
    else if (strcmp(argv[1], "-long") == 0) {
        longlines(N);
    } else {
        fprintf(stderr, "Error: Funcion '%s' desconocida.\n", argv[1]);
        return 1;
    }
    return 0;
}