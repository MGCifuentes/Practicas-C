#ifndef DECLARACION_H_INCLUDED
#define DECLARACION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LONGFILE 100

typedef struct
{
    int CodCliente;
    char ApellidoyNombre[31];
    float Saldo;
    char NombreFantasia[27];
}Cliente;

void leotxt(FILE *pt,Cliente *clitxt);
bool ManejoError(const char*, Cliente*);
void ManejoNuevo(Cliente*,FILE *,FILE *);
bool CargarArchivoBin(char *);
bool MostrarArchivoBin(const char*);
void **CrearMatriz(size_t fila, size_t columna, size_t tdato);
void CargarMatriz(int **mat, size_t fila, size_t columna);
int **ProductoMatriz(int **mat_1, size_t fila_1, size_t columna_1, int **mat_2, size_t fila_2, size_t columna_2);
void MostrarMatriz(int **resultado,size_t fila,size_t columna);
void Normalizar(char *);
bool Merge(const char*, const char*);
int LargoReal(char*);

#endif // DECLARACION_H_INCLUDED
