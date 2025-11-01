#include "hache.h"

/*void CargarElemento(int *p, int ce, int tam)
{
    if(ce<tam)
    {
        for(int i=0;i<ce;i++)
        {
            puts("ingrese elemento");
            scanf("%d", p);
            p++;
        }
    }
}*/
void MostrarElemento(int *p, int ce)
{
    for(int i=0;i<ce;i++)
    {
        printf("%d\n", *p);
        p++;
    }
}

void CargarElemento(int *p, int *ce, int tam)
{
    puts("cantidad de elementos");
    scanf("%d", ce);
    if(*ce<=tam)
    {
        for(int i=0;i<*ce;i++)
        {
            puts("ingrese elemento");
            scanf("%d", p);
            p++;
        }
    }
}

int InsertarElemento(int *p, int *ce, int pos, int elem, int tam)
{
    //muevo todo derecha y meto ashe
    if(pos>tam)
        return 0;
    p+=pos;
    if((*ce==tam))//ruta descarte
    {
        p+=(*ce)-1;
        *ce-=1;
    }else{ //no se descarta dato
        p+=*ce;
    }
    for(int i=*ce;i>pos-1;i--)
    {
        *(p)=*(p-1);
        p--;
    }
    *ce+=1;
    *p=elem;
    return 1;
}

void InsertarElementoPrincipio(int *p, int *ce, int tam)
{
    int elem;
    p+=*ce;
    puts("Ingrese el nuevo primer elemento");
    scanf("%d", &elem);
    if((*ce==tam))
    {
        *ce-=1;
    }
    for(int i=*ce;i>0;i--)
    {
        *(p)=*(p-1);
        p--;
    }
    *p=elem;
    *ce+=1;
}

void InsertarElementoFinal(int *p, int *ce, int tam)
{
    int elem;
    puts("Ingrese el nuevo ultimo elemento");
    scanf("%d", &elem);
    p+=*ce;
    if((*ce==tam))
    {
        p-=1;
    }else{
        *ce+=1;
    }
    *p=elem;
}

/*int EliminarElemento(int *p, int *ce, int pos, int tam)
{
    if(pos>tam)
        return 0;
    p+=pos-1;
    *p=0;
    *ce-=1;
    return 1;
}*/

int EliminarElemento(int *p, int *ce, int pos, int tam)
{
    if (pos>*ce)
        return 0;
    p+=pos-1;
    for (int i=pos-1;i<*ce-1;i++)
    {
        *p= *(p+1);
        p++;
    }
    (*ce)--;
    return 1;
}

int EliminarPrimeraAparicion(int *p, int *ce, int elem)
{
    int *inicio= p;
    int *fin= p+*ce; //INICIO ES POR LO DEL FOR
    while(p<fin && *p!=elem)
        p++;
    if(p==fin)
        return 0; //recorri y el valor no estaba siquiera crgado
    for (int i=(p-inicio);i<*ce-1;i++)
    {
        *p= *(p+1);
        p++;
    }
    (*ce)--;
    return 1;
}

int EliminarConcurrencias(int *p, int *ce, int elem)
{
    int *fin= p+(*ce);
    int cont=0;
    while(p<fin)
    {
        if(*p==elem)
        {
            cont++; //aparecio al menos una vez el elemento a borrar ashe y sumo veces
            int *aux=p; //muevo aux ya que comparte dir con p (NO MOVER P)
            while(aux<(fin-1))
            {
                *aux=*(aux+1);
                aux++;
            }
            (*ce)--;
            fin--;
        }else{
            p++;
        }
    }
    return cont;
}

void Ordenar(int *p, int *ce) //busca carp estructurada
{
    int *i, *j;
    int aux;
    for(i=p;i<(p+(*ce)-1);i++)//pos 1
    {
        for(j=i+1;j<p+(*ce);j++)//pos
        {
            if(*i>*j)//si cambio el signo es de mayor a menor
            {
                aux=*i;
                *i=*j;
                *j=aux;
            }
        }
    }
}
