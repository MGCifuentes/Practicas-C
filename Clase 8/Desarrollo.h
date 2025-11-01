#ifndef DESARROLLO_H_INCLUDED
#define DESARROLLO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define CAP 100
#define OK 0
#define SIN_MEM 1
#define DUPLICADO 2

typedef struct
{
    void *vec;
    size_t cap;
    size_t tam;
    int ce;  //cant de elementos cargados
}Vector;

typedef int (*cmp)(const void*, const void*);
typedef void (*Accion)(void*);

bool crearVector(Vector*, size_t, size_t);
bool Redimensionar(Vector*, size_t);
int InsertarOrden(Vector*, void*, cmp);
void Recorrer(const Vector *, Accion);
int EliminarOrdenado(Vector *, void*, cmp);
int BuscarOrdenado(const Vector *, void*, cmp);
int cmpEntero(const void *, const void *);
void MostrarEntero(void*);
int InsertarFinal(Vector *, const void*);
void destruirVector (Vector *);

#endif // DESARROLLO_H_INCLUDED
