#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#define esLetra(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
#include <stdio.h>
#include <stdlib.h>

unsigned long factorialRecursiva(int numero);
int potenciaRecursiva(int base, int exp);
int strlenRecursiva(const char *cad);
void imprimirRecursiva(int cont);
int palindromoRecursiva(char *cad);
int RiesPalindromo(char *cad, char *fin);

void imprimirCadenaVertical(const char *cad);
void imprimirCadenaVerticalRec(const char *cad);
void imprimirCadenaVerticalInvertida(const char *cad);
void imprimirCadenaVerticalInvertidaRec(const char *cad);
void imprimirCadenaPiramideCreciente(const char *cad);
void imprimirCadenaPiramideCrecienteRec(const char *cad);
void imprimirCadenaPiramideDecreciente(const char *cad);
void imprimirCadenaPiramideDecrecienteRec(const char *cad);
void imprimirCadenaPiramideCrecienteEnOrden(const char *cad);
void imprimirCadenaPiramideCrecienteEnOrdenRec(const char *cad, int aux);
void imprimirCadenaPiramideDecrecienteEnOrden(const char *cad);
void imprimirCadenaPiramideDecrecienteEnOrdenRec(const char *cad, int aux);
void imprimirCadenaConcatenadaInversa(const char *cad);
void imprimirCadenaConcatenadaInversaAnexada(const char *cad);
char* invertirCadena(const char *cad);

void imprimirNumeroVerticalInversa(int n);
void imprimirNumeroVerticalInversaRec(int n);
void imprimirNumeroVertical(int n);
void imprimirNumeroVerticalRec(int n);
void imprimirNumeroPiramideDecrecienteEnOrden(int n);
void imprimirNumeroPiramideDecrecienteEnOrdenRec(int n);
void imprimirNumeroPiramideCrecienteEnOrden(int n);
void imprimirNumeroPiramideCrecienteEnOrdenRec(int n);
void imprimirNumeroPiramideCreciente(int n);
void imprimirNumeroPiramideCrecienteRec(int n);
void imprimirNumeroPiramideDecreciente(int n);
void imprimirNumeroPiramideDecrecienteRec(int n);
void imprimirNumeroPiramideInversa(int n);
void imprimirNumeroPiramide(int n);
void imprimirNumeroDecrecienteRec(int n);
void imprimirNumeroCrecienteRec(int n);
void imprimirNumeroVerticalConcatenadoInverso(int n);

void mostrarNumeroBase(int num, int base);
void mostrarNumeroBaseRec(int num, int base);

int busquedaBinaria(int* arr, int tam, int valor);
int* busquedaBinariaRec(int* inicio, int* fin, int valor);

void cmap(char* cadena, int (*funcion)(int));
int aMayuscula(int letra);
#endif // DECLARACIONES_H_INCLUDED
