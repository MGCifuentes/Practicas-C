#include "Declaraciones.h"

int main()
{
    printf("%lu",factorialRecursiva(20));

    printf("\n%d",potenciaRecursiva(3,2));
    //aca con strings
    char cad[]="hola";
    int resultado=strlenRecursiva(cad);
    printf("\n%d\n",resultado);

    imprimirRecursiva(5);
    resultado=palindromoRecursiva("neuquen arriba la birra neuquen");
    if(resultado==1)
        printf("\nEs palindromo");
    else printf("\nNo es palindromo");

    printf("\n");
    imprimirCadenaVertical(cad);

    imprimirCadenaVerticalInvertida(cad);

    imprimirCadenaPiramideCreciente(cad);

    imprimirCadenaPiramideDecreciente(cad);

    imprimirCadenaPiramideCrecienteEnOrden(cad);

    imprimirCadenaPiramideDecrecienteEnOrden(cad);

    imprimirCadenaConcatenadaInversa(cad);

    imprimirCadenaConcatenadaInversaAnexada(cad);
    //aca con int
    int n=1234;
    imprimirNumeroVerticalInversa(n);

    imprimirNumeroVertical(n);

    imprimirNumeroPiramideDecrecienteEnOrden(n);

    imprimirNumeroPiramideCrecienteEnOrden(n);

    imprimirNumeroPiramideCreciente(n);

    imprimirNumeroPiramideDecreciente(n);

    imprimirNumeroPiramideInversa(n);

    imprimirNumeroPiramide(n);

    imprimirNumeroVerticalConcatenadoInverso(n);
    //aca las de la tarea
    mostrarNumeroBase(-15,16); //permite negativos

    int arr[]={2,5,8,12,16,23,38,45,56,67,78};
    int indice=busquedaBinaria(arr, (sizeof(arr)/sizeof(arr[0])), 23);
    printf("\nElemento 23 encontrado en indice: %d\n", indice);
    indice=busquedaBinaria(arr, (sizeof(arr)/sizeof(arr[0])), 100);//aca busco dato que no esta
    if(indice==-1)
        printf("Elemento 100 no encontrado\n");

    char cadena1[] = "hola me llamo nashe ";
    printf("cadena original: %s\n", cadena1);
    cmap(cadena1, aMayuscula);
    printf("cadena modificada: %s\n\n", cadena1);
    return 0;
}
