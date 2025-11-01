#include "decfunc.h"

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

void OrdenarSeleccion(int *p, int *ce)
{
    int *i,*j,*min;
    int aux;
    for(i=p;i<p+(*ce)-1;i++)
    {
        min=i;
        for(j=i+1;j<p+(*ce);j++)
        {
            if(*j<*min)
                min=j;
        }
        if(min!=i)
        {
            aux=*i;
            *i=*min;
            *min=aux;
        }
    }
}

void OrdenarBurbujeo(int *p, int *ce)
{
    int *j;
    int aux;
    for(int i=0;i<(*ce)-1;i++)
    {
         for(j=p;j<p+(*ce)-1-i;j++)
        {
            if(*j>*(j+1))
            {
                aux=*j;
                *j=*(j+1);
                *(j+1)=aux;
            }
        }
    }
}

void OrdenarInsercion(int *p, int *ce)
{
    int j, aux;

    for(int i=1;i<*ce;i++)
    {
        aux=*(p+i);
        j=i-1;
        while(j>=0 && *(p+j)>aux)
        {
            *(p+j+1)=*(p+j);
            j--;
        }
        *(p+j+1)=aux;
    }
}

int mi_atoi(const char *p)
{
    int resultado=0;
    int signo=1;
    while(*p==' ' || *p=='\t')
        p++;
    if(*p=='-')
    {
        signo=-1;
        p++;
    }else if(*p=='+'){
        p++;
    }
    while(*p>='0' && *p<='9')
    {
        resultado= (resultado*10)+(*p-'0');
        p++;
    }
    return (signo*resultado);
}

void mi_itoa(int numero, char *p, int base)
{
    char *ptr=p, *ptr1=p, auxchar;
    int aux;
    // si ingreso cero
    if(numero==0)
    {
        *ptr++='0';
        *ptr='\0';
        return;
    }
    //negativo base 10
    int negativo=0;
    if(numero<0 && base==10)
    {
        negativo=1;
        numero=(-numero);
    }
    //conversión
    while(numero!=0)
    {
        aux= (numero%base);
        *ptr++=(aux<10)? aux+'0': aux-10+'A';
        numero/=base;
    }
    if (negativo)
    {
        *ptr++='-';
        *ptr='\0';
    }
    // invertir la cadena
    ptr--;
    while (ptr1<ptr) {
        auxchar=*ptr;
        *ptr--=*ptr1;
        *ptr1++=auxchar;
    }
}

void Ordenar(int *p, int ce)
{
    int aux;
    do
    {
        puts("Elija un metodo de ordenamiento (1-Seleccion, 2-Burbujeo, 3-Insercion)");
        scanf("%d",&aux);
    }while(aux<1 || aux>3);
    switch(aux)
    {
        case 1: OrdenarSeleccion(p, &ce);
        break;
        case 2: OrdenarBurbujeo(p, &ce);
        break;
        case 3: OrdenarInsercion(p, &ce);
        break;
        default: puts("Opcion invalida");
    }
}
