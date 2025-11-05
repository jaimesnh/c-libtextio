# liblineutils

A simple C library for text stream processing that provides three functions similar to the UNIX commands `head`, `tail`, and `longlines`.  
This project is part of the **Operating Systems** course — *Software Engineering Degree, 2025–26*.

---

## 🧑‍💻 Authors

Iván Pina Brox: @ivannpinna
Jaime Sánchez Vázquez: @jaimesnh

---

## 📄 Description

This library allows you to read text from the standard input and display:
- The **first N lines** (`head`)
- The **last N lines** (`tail`)
- The **N longest lines** (`longlines`)

It is designed as a reusable C library (`.a` or `.so`) and includes a test program to verify and demonstrate its functionality.

---

## ⚙️ Functions

### `int head(int N)`
Prints the first **N** lines from the standard input to the standard output.

### `int tail(int N)`
Prints the last **N** lines from the standard input to the standard output.

### `int longlines(int N)`
Prints the **N longest lines** (from longest to shortest) read from the standard input.

All functions return `0` on success and `-1` on error.

---

## 🧩 File Structure

├── libreria.c          # Implementación de las funciones: head, tail, longlines, etc.
├── libreria.h          # Cabecera con los prototipos de las funciones
├── test.c              # Programa principal: lee argumentos (-head, -tail, -longlines)
└── compile.sh          # Script de compilación y generación de la librería estática
