#ifndef PUNTOH_H_INCLUDED
#define PUNTOH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

size_t mi_strlen(const char *);
int mi_strcmp(const char *,  const char *);
char *mi_strcpy(char *s1, const char *s2);
char *mi_strcat(char *s1, const char *s2);
char *mi_strstr(const char *s1, const char *s2);
char *mi_strrchr(char *s, int c);
int mi_strcmpi(const char *s1,  const char *s2);
char *mi_strchr(char *s, int c);
void EliminarBlanco(char *);
void EliminarBlancoP(char *);
void EliminarBlancoI(char *);
void EliminarBlancoF(char *);
void Capitalizar(char *);
int CuentaVocal(const char *);
void VocalesMayus(char *);
int Palindromo(char *);
void aMinuscula(char *);
char *ReemplazarCadena(char *, char *);
char *InvertirCadena(char *);
void CorrimientoTexto(char *, int);

#endif // PUNTOH_H_INCLUDED
