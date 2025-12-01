#ifndef DESARROLLO_H_INCLUDED
#define DESARROLLO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONGFILE 150
#define ERROR 1
#define OK 0

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      ESTRUCTURAS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef struct{//no respetamos longitudes dadas, ej="Vivienda, agua, electricidad, gas y otros combustibles" son mas de 31 caracteres, adem�s de las tildes que rompen toda logica al ocupar 2 bits.
    char Codigo[21];
    char Descripcion[60];
    char Clasificador[35];
    double Indice_ipc;//accede con %lf
    double v_m_ipc;
    double v_i_a_IPC;
    char region[21];
    char Periodo_codificado[21];
}Tdivisiones;

typedef struct{
    char Codigo[21];
    char Descripcion_aperturas[60];
    char Clasificador[35];
    char Periodo[21];
    double Indice_ipc;//accede con %lf
    double v_m_ipc;
    double v_i_a_IPC;
    char region[21];
}Taperturas;


//structs punto 6
typedef struct
{
    char Periodo[11];
    char Descripcion[31];
    double Indice_IPC;
    char Region[10];
    char Grupo[11];
}Tanalisis_IPC;

typedef struct {
        char Periodo[20];
        char Grupo[11];
        double sumaIndices;
        int cantidad;
}TPromedio;

//struct punto 9
typedef struct{
    char periodo[11];
    double Indice_ipc;
    double variacumulado;
    double montomes;
}Ttabla;

//bajar archivo a vectorgaming

typedef struct
{
    void *vec;
    size_t tamElem;
    int ce;
    int cap;
}Vector;

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      FUNCIONES

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef int (*cmp)(const void*, const void*);
typedef void(*Accion)(const void *,const void *);

int cmpCod(const void*a, const void*b);
int cmpCodAperturas(const void*a, const void*b);
int  crearVector(Vector * vec, size_t tamElem , int cap);
int  insertarVecEnOrd(Vector *vec , const void *elem ,cmp cmp);
void recorrerVector(Vector *vec, Accion accion, void *datosAccion);
void destruirVector(Vector * vec);

int bajarArchivoAVector(char *nombre, Vector *vec, cmp Comparar);
int bajarArchivoAVectorAperturas(char *nombre, Vector *vec, cmp Comparar);

//declaro mis funciones
//lectura archivos
int leoTxtDivisiones(FILE *pt, Tdivisiones *divi);
int mi_atoi(char *cadena);
void eliminarComillas(char*linea);
int leoTxtAperturas(FILE *pt, Taperturas *reg);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 1

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void decodificarFecha(char *periodo);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 2

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int reescribirFecha(char *fechaNum);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 3

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void normalizarDescripcion(char *cadena);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 4 Y 8

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void comaAPunto(char *cadena);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 5

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double calcularMontoAjustado(Vector *vec);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 6

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void clasificarGrupo(const Tdivisiones *divisiones, Tanalisis_IPC *analisis);
void analisisIPC(Vector *vecDivisiones);
int agregarAlFinal(Vector *vec, const void *elem);
void* buscarEnVector(Vector *vec, const void *elem, cmp comparar);
int cmpPromedio(const void *a, const void *b);
int cmpAnalisis(const void *a, const void *b);
void convertirFechaAISO(const char *periodoTexto, char *fechaISO);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 7

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int convertirFecha(char *Aniomes, int modo); //le di un doble uso por el quilombo del 6
//manejo de archivoDivisiones/Aperturas ((opcional))
void mostrarDivisiones(const void *elem, const void *datosAccion);
void mostrarAperturas(const void *elem, const void *datosAccion);
void escribirDivisionesCSV(const void *elem, const void *datosAccion);
int crearNuevoCSVDivisiones(char *nombreArchivo, Vector *vec);
int crearNuevoCSVAperturas(char *nombreArchivo, Vector *vec);
void escribirAperturasCSV(const void *elem, const void *datosAccion);
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 9

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void calcularAlquilerAjustado(Vector *vec, cmp Comparar);
int cmptabla(const void*a, const void*b);
void crearbinariotabla(Vector *vec);
void  mostrararchivobintabla(const char*archbin);

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      DEFENSA

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void menuTP();

typedef struct{
    char Codigo[21];
    char Periodo[21];
    double dato;
}Ttemporal;

//punto 1 defensa

void calcularVariacionesMensuales(Vector *vec);
int cmpCodigoYFechaNumerica(const void*a, const void*b);
int cmpTemporal(const void*a, const void*b);
void imprimirVariaciones(Ttemporal *vecTemp, int ce, FILE *pf);
//CONVERTIRFECHAMODO3
//punto 2 defensa

void calcularIndicePromedioCategorias(Vector *vec);

//punto 3 defensa

typedef struct{
    char Descripcion[62];
    char Region[21];
    double Ponderador;
}TPondera;

typedef struct{
    char Codigo[21];
    char Descripcion[60];
    char Periodo[21];
    double Indice_IPC;
    double Indice_IPC_anterior;
    double Ponderador;
    double Incidencia;
}TIncidencia;

int leoTxtPondera(FILE *pt, TPondera *pond);
int bajarPonderaAVector(char *nombre, Vector *vec, cmp Comparar);
int cmpPondera(const void*a, const void*b);
void calcularIncidenciaDivisiones(Vector *vec, Vector *vectorPondera, const char *periodoDeterminado);

#endif // DESARROLLO_H_INCLUDED
