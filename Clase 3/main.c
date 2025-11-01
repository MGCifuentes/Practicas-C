#include "hache.h"
int main()
{
    int vec[TAM], ce;
    /*ce=(sizeof(vec)/sizeof(vec[0]));*/
    /*int pos=4;*/
    /*int elem=184;*/
    /*CargarElemento(vec, ce, TAM);*/
    CargarElemento(vec, &ce, TAM);
    /*MostrarElemento(vec, ce);*/
    /*InsertarElemento(vec, &ce, pos, elem, TAM);*/
    /*InsertarElementoPrincipio(vec, &ce, TAM);*/
    /*InsertarElementoFinal(vec, &ce, TAM);*/
    /*EliminarElemento(vec, &ce, pos, TAM);*/
    /*EliminarPrimeraAparicion(vec, &ce, elem);*/
    /*EliminarConcurrencias(vec, &ce, elem);*/
    /*Ordenar(vec, &ce);*/
    MostrarElemento(vec, ce);
    return 0;
}
