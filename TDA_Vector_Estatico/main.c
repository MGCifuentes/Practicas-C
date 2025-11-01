#include <stdio.h>
#include <stdlib.h>

#define CAP 100
#define SIN_MEM 2
#define TODO_OK 1
#define DUPLICADO 3


typedef struct
{
    int vec[CAP];
    int ce;  //cant de elementos cargados
    int cap;
}Vector;

void crearVector(Vector*);
int insertarEnOrden(Vector*, int);
void mostrar(const Vector *v);
int insertarAlFinal( Vector * v, int elem);
int vectorLLeno ( const Vector *v);
int vectorVacio (const Vector *v);

int main()
{
    Vector v;
    crearVector(&v);
    insertarEnOrden(&v,5);
    insertarEnOrden(&v,3);
    insertarEnOrden(&v,2);
    insertarEnOrden(&v,7);
    insertarEnOrden(&v,9);
    insertarAlFinal(&v,1);
    mostrar(&v);
    return 0;
}


void crearVector(Vector *v)
{
    v->cap=CAP;
    v->ce=0;
}

int insertarEnOrden(Vector *v, int elem)
{
    if(v->cap==v->ce)
        return SIN_MEM;

    int *i= v->vec;
    int *ult = v->vec + v->ce -1 ;
    while(i<=ult && elem>*i)
        i++;
    if(i<=ult && elem == *i)
        return DUPLICADO;

    for(int *j = ult; j>=i ; j--)
        *(j+1)=*j;

    *i=elem;
    v->ce++;

    return TODO_OK;
}

int insertarAlFinal( Vector * v, int elem)
{
    if(v->cap==v->ce)
        return SIN_MEM;


    int *ult = (int*)v->vec + v->ce ;
    *(ult)=elem;
    v->ce++;
    return TODO_OK;

}


void mostrar( const Vector *v)
{
    int *i = (int*)v->vec;
    int *ult = (int*)v->vec + v->ce -1;
    while(i<=ult)
    {
        printf("%d\n",*i);
        i++;
    }
}



int vectorLLeno ( const Vector *v)
{
    return v->ce == v->cap;
}
int vectorVacio (const Vector *v)
{
    return v->ce==0;
}

void destruirVector (Vector *v)
{
    v->ce=0;
}
