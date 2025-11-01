#include "Declaracion.h"

void **CrearMatriz(size_t fila, size_t columna, size_t tam)
{
    void **mat=malloc(fila*sizeof(void*));
    if(!mat)
        return NULL;
    void **ult=mat+fila-1;
    for(void **i=mat;i<=ult;i++)
    {
        *i=malloc(columna*tam);
        if(!*i)
        {
            for(void **j=mat;j<i;j++)
                free(*j);
            free(mat);
            return NULL;
        }
    }
    return mat;
}

void DiagonalPrincipal(int **matriz, size_t filas, size_t columnas)
{
    if(filas!=columnas)
    {
        puts("NO ES CUADRADA\n");
        return;
    }
    for(size_t i=0;i<columnas;i++)
    {
        printf("\n%d", matriz[i][i]);
    }
}

void MostrarEspiral(int **mat, size_t filas, size_t columnas)
{
    size_t top = 0, bottom = filas - 1;
    size_t left = 0, right = columnas - 1;

    while(top <= bottom && left <= right)
    {
        // Recorre fila superior de izquierda a derecha
        for(size_t j = left; j <= right; j++)
            printf("%3d", mat[top][j]);
        top++;

        // Recorre columna derecha de arriba a abajo
        for(size_t i = top; i <= bottom; i++)
            printf("%3d", mat[i][right]);
        if(right == 0) break;  // Para evitar underflow en unsigned
        right--;

        // Recorre fila inferior de derecha a izquierda
        if(top <= bottom)
        {
            for(size_t j = right + 1; j-- > left; )
                printf("%3d", mat[bottom][j]);
            if(bottom == 0) break;
            bottom--;
        }

        // Recorre columna izquierda de abajo a arriba
        if(left <= right)
        {
            for(size_t i = bottom + 1; i-- > top; )
                printf("%3d", mat[i][left]);
            left++;
        }
    }

    printf("\n");
}

void DiagonalSecundaria(int **matriz, size_t filas, size_t columnas)
{
    if(filas!=columnas)
    {
        puts("NO ES CUADRADA\n");
        return;
    }
    for(size_t i=0;i<columnas;i++)
    {
        size_t j=columnas-1-i;
        printf("\n%d", matriz[i][j]);
    }
}

void CargarMatriz(int **mat, size_t fil, size_t col)
{
    int **ult=mat+fil;
    for(int **i=mat;i<ult;i++)
    {
        int *fc=*i+col;
        for(int *j=*i;j<fc;j++)
        {
            puts("Ingrese elemento: ");
            scanf("%d", j);
        }
    }
}

int **ProductoMatriz(int ** mat1, size_t fila1, size_t columna1, int ** mat2, size_t fila2, size_t columna2)
{
    if(columna1!=fila2)
    {
        puts("No calculable.\n");
        return NULL;
    }
    int **resultado=(int**)CrearMatriz(fila1, columna2, sizeof(int));
    for(size_t i=0;i<fila1;i++)
        for(size_t j=0;j<columna2;j++)
        {
            resultado[i][j]=0;
            for(size_t a=0; a<columna1;a++)
                resultado[i][j]+= mat1[i][a]*mat2[a][j];
        }
    return resultado;
}

void MostrarMatrizEntera(int **matriz, size_t fila, size_t columna)
{
    for(size_t i=0;i<fila;i++)
    {
        for(size_t j=0;j<columna;j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void **Transponer(void **mat, size_t fila, size_t columna, size_t tam)
{
    void **resultado=CrearMatriz(columna,fila,tam);
    for(size_t i=0;i<fila;i++)
        for(size_t j=0;j<columna;j++)
        {
            void *inicio=(char*)mat[i]+j*tam;
            void *fin=(char*)resultado[j]+i*tam;
            memcpy(fin,inicio,tam);
        }
    return resultado;
}

void TrianguloSuperiorPrincipal(int **mat, size_t filas, size_t columnas)
{
    if(filas!=columnas)
        return;
    for(size_t i=0;i<filas;i++)
        for(size_t j=0;j<columnas;j++)
            if(i<=j)
                printf("%d", mat[i][j]);
}

void TrianguloSuperiorPrincipalSinDiag(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    for(size_t i = 0; i < filas; i++)
    {
        for(size_t j = 0; j < columnas; j++)
        {
            if(i < j)
                printf("%3d", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void TrianguloInferiorPrincipal(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    for(size_t i = 0; i < filas; i++)
    {
        for(size_t j = 0; j < columnas; j++)
        {
            if(i >= j)
                printf("%3d", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void TrianguloInferiorPrincipalSinDiag(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    for(size_t i = 0; i < filas; i++)
    {
        for(size_t j = 0; j < columnas; j++)
        {
            if(i > j)
                printf("%3d", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void TrianguloSuperiorSecundaria(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    size_t n = filas;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i + j <= n - 1)
                printf("%3d", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void TrianguloSuperiorSecundariaSinDiag(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    size_t n = filas;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i + j < n - 1)
                printf("%3d", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void TrianguloInferiorSecundaria(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    size_t n = filas;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i + j >= n - 1)
                printf("%3d", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void TrianguloInferiorSecundariaSinDiag(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    size_t n = filas;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i + j > n - 1)
                printf("%3d", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void AmbosTriangulosPrincipal(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    size_t n = filas;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i <= j || i >= j)
                printf("%3d", mat[i][j]); // básicamente todo
            else
                printf("   ");
        }
        printf("\n");
    }
}

void AmbosTriangulosSecundaria(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    size_t n = filas;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i + j <= n - 1 || i + j >= n - 1)
                printf("%3d", mat[i][j]); // muestra todo
            else
                printf("   ");
        }
        printf("\n");
    }
}

void AmbosTriangulosPrincipalSinDiag(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    size_t n = filas;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i < j || i > j)
                printf("%3d", mat[i][j]); // todos menos diagonal principal
            else
                printf("   ");
        }
        printf("\n");
    }
}

void AmbosTriangulosSecundariaSinDiag(int **mat, size_t filas, size_t columnas)
{
    if(filas != columnas)
        return;

    size_t n = filas;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i + j < n - 1 || i + j > n - 1)
                printf("%3d", mat[i][j]); // todo menos diagonal secundaria
            else
                printf("   ");
        }
        printf("\n");
    }
}

void TransponerPrincipal(int **mat, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = i + 1; j < n; j++)
        {
            int aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
}

void TransponerSecundaria(int **mat, size_t n)
{
    for(size_t i = 0; i < n - 1; i++)
    {
        for(size_t j = 0; j < n - 1 - i; j++)
        {
            int aux = mat[i][j];
            mat[i][j] = mat[n - 1 - j][n - 1 - i];
            mat[n - 1 - j][n - 1 - i] = aux;
        }
    }
}

void Transponer90Horizontal(int **mat, size_t filas, size_t columnas)
{
    for(size_t i = 0; i < filas / 2; i++)
    {
        int *aux = mat[i];
        mat[i] = mat[filas - 1 - i];
        mat[filas - 1 - i] = aux;
    }
}

void Transponer90Vertical(int **mat, size_t filas, size_t columnas)
{
    for(size_t i = 0; i < filas; i++)
    {
        for(size_t j = 0; j < columnas / 2; j++)
        {
            int aux = mat[i][j];
            mat[i][j] = mat[i][columnas - 1 - j];
            mat[i][columnas - 1 - j] = aux;
        }
    }
}

void TransponerEjeCentral(int **mat, size_t filas, size_t columnas)
{
    for(size_t i = 0; i < filas / 2; i++)
    {
        for(size_t j = 0; j < columnas; j++)
        {
            int aux = mat[i][j];
            mat[i][j] = mat[filas - 1 - i][columnas - 1 - j];
            mat[filas - 1 - i][columnas - 1 - j] = aux;
        }
    }

    // Si tiene cantidad impar de filas, invertir la fila del medio
    if(filas % 2 != 0)
    {
        size_t i = filas / 2;
        for(size_t j = 0; j < columnas / 2; j++)
        {
            int aux = mat[i][j];
            mat[i][j] = mat[i][columnas - 1 - j];
            mat[i][columnas - 1 - j] = aux;
        }
    }
}

int EsMatrizSimetrica(int **mat, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = i + 1; j < n; j++)
        {
            if(mat[i][j] != mat[j][i])
                return 0;  // No es simétrica
        }
    }
    return 1;  // Es simétrica
}

int EsMatrizIdentidad(int **mat, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i == j && mat[i][j] != 1)
                return 0;
            if(i != j && mat[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

void MayorMatrizVecinos(int **mat, size_t filas, size_t columnas, int i, int j)
{
    int max = mat[i][j];  // Opcional: puede excluir el centro si querés solo vecinos

    for(int dx = -1; dx <= 1; dx++)
    {
        for(int dy = -1; dy <= 1; dy++)
        {
            if(dx == 0 && dy == 0)
                continue;

            int ni = i + dx;
            int nj = j + dy;

            if(ni >= 0 && ni < (int)filas && nj >= 0 && nj < (int)columnas)
            {
                if(mat[ni][nj] > max)
                    max = mat[ni][nj];
            }
        }
    }

    printf("Mayor vecino de (%d, %d): %d\n", i, j, max);
}

void MayorMatrizTriangular(int **mat, size_t filas, size_t columnas, int i, int j)
{
    int max = mat[i][j];

    for(int x = i; x < (int)filas; x++)
    {
        for(int y = j - (x - i); y <= j + (x - i); y++)
        {
            if(y >= 0 && y < (int)columnas)
            {
                if(mat[x][y] > max)
                    max = mat[x][y];
            }
        }
    }

    printf("Mayor en triángulo desde (%d, %d): %d\n", i, j, max);
}

void MayorMatrizCuadrada(int **mat, size_t filas, size_t columnas, int i, int j)
{
    int max = mat[i][j];

    for(int x = i; x < i + 3 && x < (int)filas; x++)
    {
        for(int y = j; y < j + 3 && y < (int)columnas; y++)
        {
            if(mat[x][y] > max)
                max = mat[x][y];
        }
    }

    printf("Mayor en bloque 3x3 desde (%d, %d): %d\n", i, j, max);
}

void MenorMatrizCuadrada(int **mat, size_t filas, size_t columnas, int i, int j)
{
    int min = mat[i][j];

    for(int x = i; x < i + 3 && x < (int)filas; x++)
    {
        for(int y = j; y < j + 3 && y < (int)columnas; y++)
        {
            if(mat[x][y] < min)
                min = mat[x][y];
        }
    }

    printf("Menor en bloque 3x3 desde (%d, %d): %d\n", i, j, min);
}

void DestruirMatriz(void **mat, size_t filas)
{
    if(!mat)
        return;
    for(size_t i=0;i<filas;i++)
        free(*(mat+i));
    free(mat);
}
