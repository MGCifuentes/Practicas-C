#include "Declaracion.h"

int main()
{
    int **mat1=(int**)CrearMatriz(3,3,sizeof(int));
    int **mat2=(int**)CrearMatriz(3,3,sizeof(int));
    CargarMatriz(mat1,3,3);
    CargarMatriz(mat2,3,3);
    int **resultado=ProductoMatriz(mat1,3,3,mat2,3,3);
    MostrarMatriz(resultado,3,3);
    CargarArchivoBin("clientes.bin");
    MostrarArchivoBin("clientes.bin");
    Merge("clientes.bin","modificaciones.txt");
    printf("\n");
    MostrarArchivoBin("clientes.bin");
    return 0;
}
