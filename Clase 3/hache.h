#ifndef HACHE_H_INCLUDED
#define HACHE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void CargarElemento(int *, int *, int);
void MostrarElemento(int *, int);
int InsertarElemento(int *, int *, int, int, int);
void InsertarElementoPrincipio(int *, int *, int);
void InsertarElementoFinal(int *, int *, int);
int EliminarElemento(int *, int *, int, int);
int EliminarPrimeraAparicion(int *, int *, int);
int EliminarConcurrencias(int *, int *, int);
void Ordenar(int *, int *);

#endif // HACHE_H_INCLUDED
