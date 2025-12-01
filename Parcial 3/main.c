#include "Declaraciones.h"

int main()
{
    cargarBinario("productos_veterinaria.dat");
    mergeArchivos("productos_veterinaria.dat","pedidos_consultorios.txt");
    mostrarBinario("productos_veterinaria.dat");
    char cad1[]="      ¡AloH! muNDO, leUrc@ y #OñartxE!! ";//¡AloH! muNDO, leUrc@ y #OñartxE!!
    funcionString(cad1);
    printf("%s",cad1);
    return OK;
}
