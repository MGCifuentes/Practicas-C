#ifndef DESARROLLO_H_INCLUDED
#define DESARROLLO_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define ERROR_APERTURA 1
#define OK 0
#define LONGFILE 100

typedef struct
{
    char descripcion [21];
    int stock;
    float precio;
}TProductos;

typedef struct
{
    int cod_prod;
    int cantidad;
}TPedidos;

void mi_strcat(char*s1, char *s2);
int mi_strlen(const char*);
int CargarArchivoBin(char*);
void LeerTxt(TPedidos *,FILE *);
bool Realizado(float,TPedidos);
bool Faltantes(TPedidos);
int Merge(char *archbin,char *archtxt);

#endif // DESARROLLO_H_INCLUDED
