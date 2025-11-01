#include "Cabecera.h"

int main()
{
    TFecha finicio;
    TFecha fEjercios;
    IngresarFecha(&finicio);
    /*COMPARA Y SUMA(CLASE)
    int igual;
    TFecha fSuma;
    fSuma=SumaDias(&finicio,90);
    IngresarFecha(&fEjercios);
    MostrarFecha(&fSuma);
    igual=CompararFecha(&finicio,&fEjercios);
    printf("%d", igual);*/
    /*RESTA DIAS
    fEjercios=RestaDias(&finicio, 90);
    MostrarFecha(&fEjercios);*/
    /*DIFERENCIA ENTRE FECHAS
    int cant;
    IngresarFecha(&fEjercios);
    cant=Diferencia(&finicio,&fEjercios);
    printf("\n%d",cant);*/
    /*EDAD
    IngresarFecha(&fEjercios);
    Edad(&finicio,&fEjercios);*/
    int dia;
    dia=Semana(&finicio);
    return 0;
}
