#include "Declaracion.h"

int main()
{
    int filas, columnas;
    puts("Ingrese n de Filas,Columna");
    scanf("%d,%d", &filas, &columnas);
    int **matriz=(int **)CrearMatriz(filas, columnas, sizeof(int));
    //int **matriz1=(int **)CrearMatriz(filas, columnas, sizeof(int));
    CargarMatriz(matriz, filas, columnas);
    //CargarMatriz(matriz1, filas, columnas);
    //int **resultado=ProductoMatriz(matriz,filas,columnas,matriz1,filas,columnas);
    //DiagonalPrincipal(matriz, filas, columnas);
    //DiagonalSecundaria(matriz, filas, columnas);
    TrianguloSuperiorPrincipal(matriz, filas, columnas);
    //MostrarMatrizEntera(resultado,filas,columnas);
    //void **trans=Transponer((void **)matriz,filas,columnas, sizeof(int));
    //MostrarMatrizEntera((int**)trans,filas,columnas);
    DestruirMatriz((void**)matriz,filas);
    return 0;
}
