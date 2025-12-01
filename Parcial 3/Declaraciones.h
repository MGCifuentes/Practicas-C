#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 1
#define OK 0
#define LONGFILE 100

typedef struct{
    char nombre_producto[26];
    unsigned int stock;
    float precio;
}TProducto;

typedef struct{
    char nombre_empresa[26];
    int cod_producto;
    int cantidad;
}TPedido;

int mergeArchivos(char *bin, char *txt);
void leoTxt(FILE *pt, TPedido *pedido);
void mostrarTxt(TPedido *pedido);
float pedidosRealizados(TProducto *producto,TPedido *pedido, FILE *pt);
int pedidosFaltantes(TProducto *producto,TPedido *pedido, FILE *pf);
int cargarBinario(char *bin);
int mostrarBinario(char *bin);
void funcionString(char *cad1);
void invertirCadenaImpares(char *cad1);
void invertirPalabra(char *inicio, char *fin);
#endif // DECLARACIONES_H_INCLUDED
