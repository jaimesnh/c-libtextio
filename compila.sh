#!/bin/bash

gcc -c libreria.c -o libreria.o
ar rcs liblibreria.a libreria.o
gcc test.c -L. -llibreria -o test
echo "Compilación completada."

