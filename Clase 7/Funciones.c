#include "Cabecera.h"

void crearVector(Vector *v)
{
    v->cap=CAP;
    v->ce=0;
}

int InsertarOrden(Vector* v, int elem)
{
    if(v->cap==v->ce)
        return 1; //se lleno
    int *i=v->vec;
    int *ult=v->vec + v->ce -1;
    while(i<=ult && elem>*i)
        i++;
    if(i<=ult && elem==*i)
        return 2; //duplicado
    for(int *j=ult;j>=i;j--)
        *(j+1)=*j;
    *i=elem;
    v->ce++;
    return 0; //ta todo bien papu
}

void Mostrar(const Vector* v)
{
    int *i=(int*)v->vec;
    int *ult=(int*)v->vec + v->ce -1;
    while(i<=ult)
    {
        printf("%d\t", *i);
        i++;
    }
}

int InsertarFinal(Vector *v, int elem)
{
    if(v->cap==v->ce)
        return 1; //lleno
    int *ult=(int *)v->vec + v->ce;
    *ult=elem;
    v->ce++;
    return 0; //ta todo ok
}

void destruirVector (Vector *v)
{
    v->ce=0;
}
