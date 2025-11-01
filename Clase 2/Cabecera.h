#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int d;
    int m;
    int a;
}TFecha;

void IngresarFecha(TFecha *F);
void MostrarFecha(TFecha *F);
bool EsFechaValida(const TFecha *F);
int cantDiasMes(int m, int a);
bool esBisiesto(int a);
TFecha SumaDias(const TFecha *, int dias);
TFecha RestaDias(const TFecha *, int dias);
int CompararFecha(const TFecha *F,const TFecha *Ff);
int Diferencia(const TFecha *F,const TFecha *Ff);
int fechaADias(const TFecha *f);
void Edad(const TFecha *F,const TFecha *Ff);
int Semana(const TFecha *F);
#endif // CABECERA_H_INCLUDED
