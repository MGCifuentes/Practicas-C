#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LONGFILE 100
//

//              PUNTO 1

//
void funcionMerge();

typedef struct{
    int id;
    char nombre[21];
    float nota;
}Testudiante;

typedef struct
{
    void *vec;
    size_t tamElem;
    int ce;
    int cap;
}Vector;

typedef int (*cmp)(const void*, const void*);
int leoTxt(FILE *pf, Testudiante *estudiante, int numlinea);
int cargarBinario(char *archivo);
void mostrarBinario(char *archivo);
void mostrarTxt(FILE *pf, Testudiante *estudiante);
int mergeArchivos(char *archivoTxt, char *archivoBin);
int  insertarVecEnOrd(Vector *vec , const void *elem ,cmp cmp);
int crearVector(Vector * vec, size_t tamElem , int cap);
int cmpPorId(const void *a, const void *b);
int creararchivos(Vector * vec);
//

//              PUNTO 2

//
size_t mi_strlen(const char *s);
int mi_strcmp(const char *s1,  const char *s2);
void aMinuscula(char *v);
int comprobar_anagramas(char *palabra1, char *palabra2);
int leoTxtS(FILE *pt, char * pal1,char *pal2);
void son_anagramas_res();
//

//              PUNTO 3

//
void funcionMatriz();
void **CrearMatriz(size_t fila, size_t columna, size_t tam);
void CargarMatriz(double **mat, size_t fil, size_t col);
void MostrarMatrizDouble(double **matriz, size_t fila, size_t columna);
int esMatrizSimetrica(double **mat, size_t n);
void **Transponer(void **mat, size_t fila, size_t columna, size_t tam);
double **ProductoMatriz(double ** mat1, size_t fila1, size_t columna1, double ** mat2, size_t fila2, size_t columna2);
void DestruirMatriz(void **mat, size_t filas);
//

//              PUNTO 4

//
int suma_hasta(int n);

#endif // DECLARACIONES_H_INCLUDED
