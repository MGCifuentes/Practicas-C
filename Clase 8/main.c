#include "Desarrollo.h"

int main()
{
    Vector v;
    int aux=2;
    void *auxi=&aux;
    crearVector(&v, sizeof(int), 8);
    InsertarOrden(&v,auxi,cmpEntero);
    aux=3;
    InsertarOrden(&v,auxi,cmpEntero);
    aux=1;
    InsertarFinal(&v,auxi);
    aux=0;
    InsertarOrden(&v,auxi,cmpEntero);
    Recorrer(&v,MostrarEntero);
    return 0;
}
