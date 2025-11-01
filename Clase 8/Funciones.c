#include "Desarrollo.h"

bool crearVector(Vector *v, size_t tam, size_t cap)
{
    v->vec=(void*)malloc(cap*tam);
    if(!v->vec)
        return false;
    v->cap=cap;
    v->ce=0;
    v->tam=tam;
    return true;
}

bool Redimensionar(Vector *v, size_t ncap)
{
    void *nvec;
    nvec=realloc(v->vec, ncap*v->tam);
    if(!nvec)
        return false;
    v->vec=nvec;
    v->cap=ncap;
    return true;
}

int InsertarOrden(Vector* v, void* elem, cmp cmp)
{
    if(v->cap==v->ce)
        {
            if(!Redimensionar(v, v->cap*2))
                return SIN_MEM;
        }
    void *i=v->vec;
    void *ult=v->vec + (v->ce-1)*v->tam;
    while(i<=ult && cmp(elem,i)>0)
        i+=v->tam;
    if(i<=ult && cmp(elem,i)==0)
        return DUPLICADO;
    memmove(i+v->tam,i,ult-i+v->tam);
//    for(void *j=ult;j>=i;j-=v->tam)
//    {
//        memcpy(j+v->tam,j,v->ce);
//        *(j+1)=*j;
//    }
    memcpy(i,elem,v->tam);
    v->ce++;
    return OK;
}

void Recorrer(const Vector *v, Accion accion)
{
    void *ult=v->vec + (v->ce-1)*v->tam;
    for(void *i=v->vec;i<=ult;i+=v->tam)
        accion(i);
}

int cmpEntero(const void *a, const void *b)
{
    return (*(int*)a)-(*(int*)b);
}

void MostrarEntero(void *a)
{
    printf("\n%d", *(int*)a);
}

int EliminarOrdenado(Vector *v, void *elem, cmp cmp)
{
    void *i=v->vec;
    void *ult=v->vec + (v->ce-1)*v->tam;
    while(i<=ult && cmp(elem,i)!=0)
        i+=v->tam;
    if(i>ult)
        return 1; //no esta el elemento buscado
    while(i<=ult)
    {
        memcpy(i,i+v->tam,v->tam);
        i+=v->tam;
    }
    v->ce--;
    return 0;
}

int InsertarFinal(Vector *v, const void* elem)
{
    if(v->cap==v->ce)
        if(!Redimensionar(v,v->cap*2))
            return SIN_MEM;
    void *ult=v->vec + v->ce*v->tam;
    memcpy(ult,elem,v->tam);
    v->ce++;
    return OK; //ta todo ok
}

void destruirVector (Vector *v)
{
    free(v->vec);
}

int BuscarOrdenado(const Vector *v, void* elem, cmp cmp)
{
    void *i=v->vec;
    void *ult=v->vec + (v->ce-1)*v->tam;
    while(cmp(elem,i)!=0)
    {
        i+=v->tam;
    }
    if(i>=ult)
        return 1; //no estaba
    return 0; //si retorna puntero modifica
}
