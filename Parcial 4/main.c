#include "Declaraciones.h"

int main()
{
//    funcionMatriz();
//    printf("%d",suma_hasta(6));
//    char cad1[]="HoLa";
//    char cad2[]="aLoh";
//    if(comprobar_anagramas(cad1,cad2)==1)
//        printf("Son anagrama\n");
//    else
//        printf("No son anagrama\n");

    son_anagramas_res();



    cargarBinario("estudiantes.bin");
    mergeArchivos("nuevos.txt","estudiantes.bin");
    return 0;
}
