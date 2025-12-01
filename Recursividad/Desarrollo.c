#include "Declaraciones.h"

unsigned long factorialRecursiva(int numero)
{
    if(numero<=1)
        return 1;
    else return (numero*factorialRecursiva(numero-1));
}

int potenciaRecursiva(int base, int exp)
{
    if(exp==0)//este es mi caso base
        return 1;
    else return base*potenciaRecursiva(base,exp-1);
}

int strlenRecursiva(const char *cad)
{
    if (*cad!='\0')
    {
        return strlenRecursiva(cad+1)+1;
    }
    return 0;
}

void imprimirRecursiva(int cont)
{
    if(cont==0)
        return;
    else{
        printf(" %d ", cont);
        imprimirRecursiva(--cont);
    }
}

int palindromoRecursiva(char *cad)
{
    char *fin=cad+strlenRecursiva(cad)-1;
    return RiesPalindromo(cad,fin);//funcion envoltorio, explicado en clase
}

int RiesPalindromo(char *cad, char *fin)
{
    if(cad>=fin)
        return 1;
    if(!esLetra(*cad))//uso de macro bastante copada
        return RiesPalindromo(cad+1,fin);
    if(!esLetra(*fin))
        return RiesPalindromo(cad,fin-1);
    if(*cad==*fin)
        return RiesPalindromo(cad+1,fin-1);
    else return 0;
}

void imprimirCadenaVertical(const char *cad)
{
    printf("*\n");
    imprimirCadenaVerticalRec(cad);
    printf("*\n");
}

void imprimirCadenaVerticalRec(const char *cad)
{
    if(*cad=='\0')
        return;
    printf("%c\n", *cad);
    imprimirCadenaVerticalRec(cad+1);
}

void imprimirCadenaVerticalInvertida(const char *cad)
{
    printf("*\n");
    imprimirCadenaVerticalInvertidaRec(cad);
    printf("*\n");
}

void imprimirCadenaVerticalInvertidaRec(const char *cad)
{
    if(*cad=='\0')
        return;
    imprimirCadenaVerticalInvertidaRec(cad+1);
    printf("%c\n",*cad);
}

void imprimirCadenaPiramideCreciente(const char *cad)
{
    printf("*\n");
    imprimirCadenaPiramideCrecienteRec(cad);
    printf("*\n");
}

void imprimirCadenaPiramideCrecienteRec(const char *cad)
{
    if(*cad=='\0')
        return;
    printf("%s\n", cad);
    imprimirCadenaPiramideCrecienteRec(cad+1);
}

void imprimirCadenaPiramideDecreciente(const char *cad)
{
    printf("*\n");
    imprimirCadenaPiramideDecrecienteRec(cad);
    printf("*\n");
}

void imprimirCadenaPiramideDecrecienteRec(const char *cad)
{
    if(*cad=='\0')
        return;
    imprimirCadenaPiramideDecrecienteRec(cad+1);
    printf("%s\n", cad);
}

void imprimirCadenaPiramideCrecienteEnOrden(const char *cad)
{
    printf("*\n");
    imprimirCadenaPiramideCrecienteEnOrdenRec(cad,1);
    printf("*\n");
}

void imprimirCadenaPiramideCrecienteEnOrdenRec(const char *cad, int aux)
{
    if(aux>strlenRecursiva(cad))
       return;
    printf("%.*s\n",aux,cad); //le defino cuantos caracteres imprimir con presicion *=aux
    imprimirCadenaPiramideCrecienteEnOrdenRec(cad,aux+1);
}

void imprimirCadenaPiramideDecrecienteEnOrden(const char *cad)
{
    printf("*\n");
    imprimirCadenaPiramideDecrecienteEnOrdenRec(cad, 1);
    printf("*\n");
}

void imprimirCadenaPiramideDecrecienteEnOrdenRec(const char *cad, int aux)
{
    if(aux>strlenRecursiva(cad))
       return;
    imprimirCadenaPiramideDecrecienteEnOrdenRec(cad,aux+1);
    printf("%.*s\n",aux,cad);
}

void imprimirCadenaConcatenadaInversa(const char *cad)
{
    printf("*\n");
    imprimirCadenaVerticalRec(cad);
    imprimirCadenaVerticalInvertidaRec(cad);
    printf("*\n");
}

void imprimirCadenaConcatenadaInversaAnexada(const char *cad)
{
    printf("*\n");
    imprimirCadenaVerticalRec(cad);
    imprimirCadenaVerticalRec(invertirCadena(cad)+1);
    printf("*\n");
}

char* invertirCadena(const char *cad)
{
    const char *fin;
    const char *p;
    int len;
    char *invertida;
    char *aux;
    const char *izq;
    fin=cad;
    while (*fin != '\0')
        fin++;
    fin--;
    p=cad;
    len=0;
    while(*p)
    {
        len++;
        p++;
    }
    invertida=malloc(len+1);
    aux=invertida;
    izq=fin;
    while(izq>=cad)
    {
        *aux=*izq;
        aux++;
        izq--;
    }
    *aux='\0';
    return invertida;
}


void imprimirNumeroVerticalInversa(int n)
{
    printf("*\n");
    imprimirNumeroVerticalInversaRec(n);
    printf("*\n");
}

void imprimirNumeroVerticalInversaRec(int n)
{
    if(n==0)
        return;
    printf("%d\n",n%10);
    imprimirNumeroVerticalInversaRec(n/10);
}

void imprimirNumeroVertical(int n)
{
    printf("*\n");
    imprimirNumeroVerticalRec(n);
    printf("*\n");
}

void imprimirNumeroVerticalRec(int n)
{
    if(n==0)
        return;
    imprimirNumeroVerticalRec(n/10);
    printf("%d\n",n%10);
}

void imprimirNumeroPiramideDecrecienteEnOrden(int n)
{
    printf("*\n");
    imprimirNumeroPiramideDecrecienteEnOrdenRec(n);
}

void imprimirNumeroPiramideDecrecienteEnOrdenRec(int n)
{
    if(n==0)
    {
        printf("*\n");
        return;
    }
    printf("%d\n", n);
    imprimirNumeroPiramideDecrecienteEnOrdenRec(n/10);
}

void imprimirNumeroPiramideCrecienteEnOrden(int n)
{
    printf("*\n");
    imprimirNumeroPiramideCrecienteEnOrdenRec(n);
    printf("*\n");
}

void imprimirNumeroPiramideCrecienteEnOrdenRec(int n)
{
    if(n==0)
        return;
    imprimirNumeroPiramideCrecienteEnOrdenRec(n/10);
    printf("%d\n", n);
}

void imprimirNumeroPiramideCreciente(int n)
{
    printf("*\n");
    imprimirNumeroPiramideCrecienteRec(n);
    printf("*\n");
}

void imprimirNumeroPiramideCrecienteRec(int n)
{
    if(n<10)
    {
        printf("%d\n", n);
        return;
    }
    int temp=n;
    int divisor=1;
    while(temp>=10)
    {
        temp/=10;
        divisor*=10;
    }
    int aux= n % divisor;
    imprimirNumeroPiramideCrecienteRec(aux);
    printf("%d\n", n);
}

void imprimirNumeroPiramideDecreciente(int n)
{
    printf("*\n");
    imprimirNumeroPiramideDecrecienteRec(n);
    printf("*\n");
}

void imprimirNumeroPiramideDecrecienteRec(int n)
{
    printf("%d\n",n);
    if(n<10)
        return;
    int temp=n;
    int divisor=1;
    while(temp>=10)
    {
        temp/=10;
        divisor*=10;
    }
    int aux=n%divisor;
    imprimirNumeroPiramideDecrecienteRec(aux);
}

void imprimirNumeroPiramideInversa(int n)
{
    printf("*\n");
    imprimirNumeroDecrecienteRec(n);
    imprimirNumeroCrecienteRec(n);
    printf("*\n");
}

void imprimirNumeroPiramide(int n)
{
    printf("*\n");
    imprimirNumeroCrecienteRec(n);
    imprimirNumeroDecrecienteRec(n);
    printf("*\n");
}

void imprimirNumeroDecrecienteRec(int n)
{
    if(n==0)
        return;
    printf("%d\n", n);
    imprimirNumeroDecrecienteRec(n/10);
}

void imprimirNumeroCrecienteRec(int n)
{
    if(n==0)
        return;
    imprimirNumeroPiramideCrecienteEnOrdenRec(n/10);
    printf("%d\n", n);
}

void imprimirNumeroVerticalConcatenadoInverso(int n)
{
    printf("*\n");
    imprimirNumeroVerticalInversaRec(n);
    imprimirNumeroVerticalRec(n);
    printf("*\n");
}

void mostrarNumeroBase(int num, int base)
{
    if(num==0)
    {
        printf("0");
        return;
    }
    if(num<0)
    {
        printf("-");
        num=-num;
    }
    mostrarNumeroBaseRec(num, base);
}

void mostrarNumeroBaseRec(int num, int base)
{
    if(num==0)
        return;

    mostrarNumeroBaseRec(num/base, base);

    int digito=(num%base);

    if(digito<10)
        printf("%d", digito);
    else
        printf("%c", 'A'+(digito-10));
}

int* busquedaBinariaRec(int* inicio, int* fin, int valor)
{
    if(inicio>fin)
        return NULL;

    int *medio=inicio+(fin-inicio)/ 2;
    if(*medio==valor)
        return medio;

    if(valor<*medio)
        return busquedaBinariaRec(inicio, medio-1, valor);
    return busquedaBinariaRec(medio+1, fin, valor);
}

int busquedaBinaria(int* arr, int tamano, int valor)
{
    int *resultado=busquedaBinariaRec(arr, arr+tamano-1, valor);

    if(resultado==NULL)
        return -1;
    return resultado-arr;
}

void cmap(char* cadena, int (*funcion)(int))
{
    if(*cadena=='\0')
        return;
    *cadena=funcion(*cadena);
    cmap(cadena+1, funcion);
}

int aMayuscula(int letra)
{
    if ((letra>='a') && (letra<='z'))
        return (letra-('a'-'A'));

    return letra;
}
