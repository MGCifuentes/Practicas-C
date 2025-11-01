#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define CAP 100

typedef struct
{
    int vec[CAP];
    int ce;  //cant de elementos cargados
    int cap;
}Vector;

void crearVector(Vector*);
int InsertarOrden(Vector*, int);
void Mostrar(const Vector*);
int InsertarFinal(Vector*, int);
void destruirVector (Vector *);

#endif // CABECERA_H_INCLUDED
