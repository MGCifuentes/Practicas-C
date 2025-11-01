#include "decfunc.h"

int main()
{
    int vec[TAM], ce;
    CargarElemento(vec, &ce, TAM);
    Ordenar(vec, ce);
    MostrarElemento(vec, ce);
    /*int aux;
    char valor[7]="-12k3";
    char *p=valor;
    aux=mi_atoi(p);
    printf("%d", aux);*/
    /*int numero=123;
    char cadena[4];
    mi_itoa(numero, cadena, 10);
    printf("%s", cadena);*/
    return 0;
}
