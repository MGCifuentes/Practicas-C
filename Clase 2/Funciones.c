#include "Cabecera.h"

void IngresarFecha(TFecha *F)
{
    puts("Ingresar fecha (D/M/A):");
    scanf("%d / %d / %d", &F->d, &F->m, &F->a);
    while(!EsFechaValida(F))
    {
        puts("Ingresar fecha (D/M/A):");
        scanf("%d / %d / %d", &F->d, &F->m, &F->a);
    }
}

void MostrarFecha(TFecha *F)
{
    printf("%02d/%02d/%04d", F->d,F->m,F->a);
}

bool EsFechaValida(const TFecha *F)
{
    if(F->a >= 1601)
        if((F->m >=1) && (F->m <=12))
            if((F->d >=1) && (F->d <=cantDiasMes(F->m,F->a)))
                return true;
    return false;
}

int cantDiasMes(int m, int a)
{
    int Dias[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2 && esBisiesto(a))
        return 29;
    return Dias[m];
}

bool esBisiesto(int a)
{
    return((a%4==0 && a%100!=0) || (a%400==0));
}

TFecha SumaDias(const TFecha *F, int dias)
{
    int cantdias;
    TFecha FSuma= *F;
    FSuma.d+=dias;
    while(FSuma.d > (cantdias=cantDiasMes(FSuma.m,FSuma.a)))
    {
        FSuma.d-=cantdias;
        FSuma.m++;
        if(FSuma.m >12)
        {
            FSuma.m=1;
            FSuma.a++;
        }
    }
    return FSuma;
}

int CompararFecha(const TFecha *F,const TFecha *Ff)
{
    if((F->d == Ff->d) && (F->m == Ff->m) && (F->a == Ff->a))
        return 0; //son la misma fecha
    return 1; //son fechas distintas
}

TFecha RestaDias(const TFecha *F, int dias)
{
    int cdm;
    TFecha fResta= *F;
    fResta.d-=dias;
    while(fResta.d <=0)
    {
        fResta.m--;
        if(fResta.m <1)
        {
            fResta.m=12;
            fResta.a--;
        }
        cdm=cantDiasMes(fResta.m,fResta.a);
        fResta.d+=cdm;
    }
    return fResta;
}

int Diferencia(const TFecha *F,const TFecha *Ff)
{
    int chad;
    chad=fechaADias(Ff);
    chad-=fechaADias(F);
    return chad;
}

int fechaADias(const TFecha *f)
{
    TFecha F= *f;
    int dias=F.d;
    for (int m=1;m<F.m;m++) {
        dias +=cantDiasMes(m,F.a);
    }
    for (int a=1601;a<F.a;a++) {
        dias += esBisiesto(a)?366:365;
    }
    return dias;
}

void Edad(const TFecha *F,const TFecha *Ff)
{
    int edad=F->a; //cargo 2025
    edad-=Ff->a; //resto nacimiento
    if(Ff->m > F->m)
        edad--;
    if(Ff->m == F->m)
        if(Ff->d > F->d)
            edad--; //todavia no cumplio
    printf("%d", edad);
}

int Semana(const TFecha *F)
{
    int aux=fechaADias(F);
    aux--;
    aux%=7;
    switch(aux)
    {
        case 0: printf("lunes");
        break;
        case 1: printf("martes");
        break;
        case 2: printf("miercoles");
        break;
        case 3: printf("jueves");
        break;
        case 4: printf("viernes");
        break;
        case 5: printf("sabado");
        break;
        case 6: printf("domingo");
        break;
    }
    return aux;
}
