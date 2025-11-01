#ifndef DECLARACION_H_INCLUDED
#define DECLARACION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void **CrearMatriz(size_t , size_t , size_t);
void CargarMatriz(int **, size_t, size_t);
int **ProductoMatriz(int **, size_t, size_t, int **, size_t, size_t);
void MostrarMatrizEntera(int **, size_t, size_t);

void DiagonalPrincipal(int **, size_t, size_t);
void DiagonalSecundaria(int **, size_t, size_t);

void TrianguloSuperiorPrincipal(int **, size_t, size_t);
void TrianguloSuperiorPrincipalSinDiag(int **, size_t, size_t);
void TrianguloInferiorPrincipal(int **, size_t, size_t);
void TrianguloInferiorPrincipalSinDiag(int **, size_t, size_t);

void TrianguloSuperiorSecundaria(int **, size_t, size_t);
void TrianguloSuperiorSecundariaSinDiag(int **, size_t, size_t);
void TrianguloInferiorSecundaria(int **, size_t, size_t);
void TrianguloInferiorSecundariaSinDiag(int **, size_t, size_t);

void AmbosTriangulosPrincipal(int **, size_t, size_t);
void AmbosTriangulosSecundaria(int **, size_t, size_t);
void AmbosTriangulosPrincipalSinDiag(int **, size_t, size_t);
void AmbosTriangulosSecundariaSinDiag(int **, size_t, size_t);

void **Transponer(void **, size_t, size_t, size_t);
void TransponerPrincipal(int **, size_t);
void TransponerSecundaria(int **, size_t);
void Transponer90Horizontal(int **, size_t, size_t);
void Transponer90Vertical(int **, size_t, size_t);
void TransponerEjeCentral(int **, size_t, size_t);

int EsMatrizSimetrica(int **, size_t);
int EsMatrizIdentidad(int **, size_t);

void MayorMatrizVecinos(int **, size_t, size_t, int, int);
void MayorMatrizTriangular(int **, size_t, size_t, int, int);
void MayorMatrizCuadrada(int **, size_t, size_t, int, int);
void MenorMatrizCuadrada(int **, size_t, size_t, int, int);

void MostrarEspiral(int **, size_t, size_t);
void DestruirMatriz(void **, size_t);

#endif // DECLARACION_H_INCLUDED
