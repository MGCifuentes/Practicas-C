#include "Declaraciones.h"

//

//              PUNTO 4

//

int suma_hasta(int n) //trae 6, como 6!=1 llama de nuevo con 6+5, como 5 es distinto de 1....
{
    if(n==1)
        return 1;
    return n+suma_hasta(n-1);
}
//

//              PUNTO 3

//
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

void CargarMatriz(double **mat, size_t fil, size_t col)
{
    double **ult=mat+fil;
    for(double **i=mat;i<ult;i++)
    {
        double *fc=*i+col;
        for(double *j=*i;j<fc;j++)
        {
            puts("Ingrese elemento: ");
            scanf("%lf", j);
        }
    }
}

void MostrarMatrizDouble(double **matriz, size_t fila, size_t columna)
{
    for(size_t i=0;i<fila;i++)
    {
        for(size_t j=0;j<columna;j++)
        {
            printf("%.2lf\t", matriz[i][j]);
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


int esMatrizSimetrica(double **mat, size_t n)
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

double **ProductoMatriz(double ** mat1, size_t fila1, size_t columna1, double ** mat2, size_t fila2, size_t columna2)
{
    if(columna1!=fila2)
    {
        puts("No calculable.\n");
        return NULL;
    }
    double **resultado=(double**)CrearMatriz(fila1, columna2, sizeof(double));
    for(size_t i=0;i<fila1;i++)
        for(size_t j=0;j<columna2;j++)
        {
            resultado[i][j]=0;
            for(size_t a=0; a<columna1;a++)
                resultado[i][j]+= mat1[i][a]*mat2[a][j];
        }
    return resultado;
}


void DestruirMatriz(void **mat, size_t filas)
{
    if(!mat)
        return;
    for(size_t i=0;i<filas;i++)
        free(*(mat+i));
    free(mat);
}

void funcionMatriz()
{
    int tamanio;
    do
    {
        printf("ingrese el tamanio N de la matriz: ");
        scanf("%d", &tamanio);
        if(tamanio>200)
            printf("\nIngrese un valor acorde\n");
    }while(tamanio>200);
    double **matriz=(double **)CrearMatriz(tamanio, tamanio, sizeof(double));
    CargarMatriz(matriz, tamanio, tamanio);
    printf("MATRIZ ORIGINAL:\n");
    MostrarMatrizDouble((double**)matriz,tamanio,tamanio);
    void **trans=Transponer((void **)matriz,tamanio,tamanio, sizeof(double));
    printf("MATRIZ TRANSPUESTA:\n");
    MostrarMatrizDouble((double**)trans,tamanio,tamanio);
    if(esMatrizSimetrica(matriz,tamanio)==1)
    {
        double **resultado=ProductoMatriz(matriz,tamanio,tamanio,matriz,tamanio,tamanio);
        printf("MATRIZ A*A:\n");
        MostrarMatrizDouble(resultado,tamanio,tamanio);
        DestruirMatriz((void**)resultado,tamanio);
    }
    DestruirMatriz((void**)matriz,tamanio);
    DestruirMatriz(trans,tamanio);
}
//

//              PUNTO 2

//
size_t mi_strlen(const char *s)
{
    size_t cont=0;
    while(*s!='\0')
    {
        cont++;
        s++;
    }
    return cont;
}

int mi_strcmp(const char *s1,  const char *s2)
{
    while(*s1!='\0' && *s2!='\0')
    {
        if(*s1==*s2)
        {
            s1++;
            s2++;
        }
        else return *s1-*s2;
    }
    return *s1-*s2;
}

void aMinuscula(char *v)
{
    while(*v!='\0')
    {
        if(*v>='A' && *v<='Z')
            *v=*v-'A'+'a';
        v++;
    }
}

int comprobar_anagramas(char *p1, char *p2)
{
    if(mi_strlen(p1)!=mi_strlen(p2))
        return 0;
    if(mi_strcmp(p1,p2)==0)
        return 0;
    aMinuscula(p1);
    aMinuscula(p2);
    char *c1=p1;
    while(*c1)
    {
        char *c2=p2;
        int encontrada=0;
        while(*c2)
        {
            if(*c1==*c2)
            {
                *c2=1;   // Marcamos como usada
                encontrada=1;
                break;     // SALIMOS del while!!!
            }
            c2++;
        }
        if(!encontrada)
            return 0;
        c1++;
    }
    return 1;
}



void son_anagramas_res()
{
    FILE *pt;
    char palabra1[100];
    char palabra2[100];


    pt = fopen("ArchivosDeTexto/Anagramas.txt", "r");
    if(pt == NULL)
    {
        printf("Error");
        return;
    }

    leoTxtS(pt, palabra1, palabra2);
    while(!feof(pt))
    {
        if(comprobar_anagramas(palabra1, palabra2)==1)
            printf("'%s' \t '%s' \t anagramas\n", palabra1, palabra2);
        else
            printf("'%s' \t '%s' \t NO anagramas\n", palabra1, palabra2);

        leoTxtS(pt, palabra1, palabra2);
    }
    fclose(pt);
}

int leoTxtS(FILE *pt, char * pal1,char *pal2)
{
    char linea[LONGFILE];
    char *aux;

    if(!fgets(linea, LONGFILE, pt))
        return 1;

    aux = strchr(linea, '\n');
    if(aux)
        *aux = '\0';

    aux = strrchr(linea, '-');
    strcpy(pal1, aux + 1);
    pal1[20] = '\0';

    strcpy(pal2, aux + 1);
    pal2[20] = '\0';

    return 0;
}

//

//              PUNTO 1

//


int leoTxt(FILE *pt, Testudiante *estu, int numLinea)
{
    char linea[LONGFILE];
    char *aux;

    if(!fgets(linea, LONGFILE, pt))
        return 1;

    aux = strchr(linea, '\n');
    if(aux)
        *aux = '\0';

    aux = strrchr(linea, ',');
    if(!aux)
    {
        printf("linea %d malformada \n", numLinea);
        return 2;
    }

    if(sscanf(aux + 1, "%f", &estu->nota) != 1)
    {
        printf("linea %d malformada \n", numLinea);
        return 2;
    }
    *aux = '\0';

    aux = strrchr(linea, ',');
    if(!aux)
    {
        printf("linea %d malformada \n", numLinea);
        return 2;
    }
    strcpy(estu->nombre, aux + 1);
    estu->nombre[20] = '\0';


    if(sscanf(linea, "%d", &estu->id) != 1)
    {
        printf("linea %d malformada \n", numLinea);
        return 2;
    }

    return 0;
}

int cargarTextoAVector(char *archivoTxt, Vector *vecTxt)
{
    FILE *pt = fopen(archivoTxt, "r");
    if(!pt)
    {
        printf("error\n");
        return 1;
    }

    Testudiante estu;
    int linea = 1;
    int resultado;

    while((resultado = leoTxt(pt, &estu, linea)) != 1)
    {
        if(resultado == 0)
        {
            insertarVecEnOrd(vecTxt, &estu, cmpPorId);
        }
        linea++;
    }

    fclose(pt);
    return 0;
}

int cargarBinario(char *bin)
{
    FILE *pb = fopen(bin, "wb");
    if(pb == NULL)
    {
        printf("Error \n");
        return 1;
    }
    Testudiante estu[6] =
    {
        {1234, "Matias Mendoza", 8.5},
        {2001, "Carlos Lopez", 7.25},
        {1232, "Matias Sapeeee", 4.5},
        {1999, "Carlos Jara", 1.25},
        {1235, "Papu man", 6.5},
        {2002, "Emiliano Lopez", 7.25}
    };
    fwrite(estu, sizeof(Testudiante), 6, pb);
    fclose(pb);
    return 0;
}


int cmpPorId(const void *a, const void *b)
{
    Testudiante reg1 = *(Testudiante*)a;
    Testudiante reg2 = *(Testudiante*)b;

    if(reg1.id != reg2.id)
        return reg1.id - reg2.id;

    return strcmp(reg1.nombre, reg2.nombre);
}

int cmpPorNotaNombre(const void *a, const void *b)
{
    Testudiante reg1 = *(Testudiante*)a;
    Testudiante reg2 = *(Testudiante*)b;

    if(reg1.nota < reg2.nota)
        return 1;
    if(reg1.nota > reg2.nota)
        return -1;

    return strcmp(reg1.nombre, reg2.nombre);
}

int cargarBinarioAVector(char *archivoBin, Vector *vecBin)
{
    FILE *pb = fopen(archivoBin, "rb");
    if(!pb)
    {
        printf("error \n");
        return 1;
    }

    Testudiante estu;
    while(fread(&estu, sizeof(Testudiante), 1, pb) == 1)
    {
        insertarVecEnOrd(vecBin, &estu, cmpPorId);
    }

    fclose(pb);

    return 0;
}


int mergeArchivos(char *archivoTxt, char *archivoBin)
{

    int i=0, j=0, actualizaciones = 0, aniadidos = 0;
    Vector vecBin, vecTxt, vecFusion;

    crearVector(&vecBin, sizeof(Testudiante), 10);
    crearVector(&vecTxt, sizeof(Testudiante), 10);
    crearVector(&vecFusion, sizeof(Testudiante), 20);

    if(cargarBinarioAVector(archivoBin, &vecBin) != 0)
    {
        free(vecBin.vec);
        return 1;
    }

    if(cargarTextoAVector(archivoTxt, &vecTxt) != 0)
    {
        free(vecBin.vec);
        free(vecTxt.vec);
        return 1;
    }
    while(i < vecTxt.ce)
    {
        Testudiante *estuTxt = (Testudiante*)((char*)vecTxt.vec + i * vecTxt.tamElem);
        if(j >= vecBin.ce)
        {
            insertarVecEnOrd(&vecFusion, estuTxt, cmpPorNotaNombre);
            aniadidos++;
            i++;
            continue;
        }

        Testudiante *estuBin = (Testudiante*)((char*)vecBin.vec + j * vecBin.tamElem);

        if(estuTxt->id == estuBin->id)
        {
            strcpy(estuBin->nombre, estuTxt->nombre);
            estuBin->nota = estuTxt->nota;

            insertarVecEnOrd(&vecFusion, estuBin, cmpPorNotaNombre);
            actualizaciones++;

            i++;
            j++;
        }
        else if(estuTxt->id < estuBin->id)
        {
            insertarVecEnOrd(&vecFusion, estuTxt, cmpPorNotaNombre);
            aniadidos++;
            i++;
        }
        else
        {
            insertarVecEnOrd(&vecFusion, estuBin, cmpPorNotaNombre);
            j++;
        }
    }
    while(j < vecBin.ce)
    {
        Testudiante *estuBin = (Testudiante*)((char*)vecBin.vec + j * vecBin.tamElem);
        insertarVecEnOrd(&vecFusion, estuBin, cmpPorNotaNombre);
        j++;
    }
    creararchivos(&vecFusion);

    printf("originales binario: %d\n", vecBin.ce);
    printf("originales texto: %d\n", vecTxt.ce);
    printf("actualizaciones: %d\n", actualizaciones);
    printf("aniadidos: %d\n", aniadidos);

    free(vecBin.vec);
    free(vecTxt.vec);
    free(vecFusion.vec);

    return 0;
}

int insertarVecEnOrd(Vector *vec, const void *elem, cmp cmp)
{
    if(vec->cap == vec->ce)
    {
        void *aux;
        int ncap = vec->cap * 2;
        aux = realloc(vec->vec, vec->tamElem * ncap);
        if(!aux)
            return 1;
        vec->vec = aux;
        vec->cap = ncap;
    }

    if(vec->ce == 0)
    {
        memcpy(vec->vec, elem, vec->tamElem);
        vec->ce = 1;
        return 0;
    }

    void *ult = vec->vec + (vec->ce - 1) * vec->tamElem;
    void *act = vec->vec;
    int comparo;


    while(act <= ult && (comparo = cmp(act, elem)) < 0)
        act += vec->tamElem;

    if(act <= ult)
        memmove(act + vec->tamElem, act, (char*)ult - (char*)act + vec->tamElem);

    memcpy(act, elem, vec->tamElem);

    vec->ce = vec->ce + 1;
    return 0;
}

int crearVector(Vector *vec, size_t tamElem, int cap)
{
    vec->vec = malloc(cap * tamElem);
    if(!vec->vec)
        return 1;

    vec->cap = cap;
    vec->ce = 0;
    vec->tamElem = tamElem;

    return 0;
}

int creararchivos(Vector *vec)
{
    FILE *pb = fopen("fusionado.bin", "wb");
    if(!pb)
    {
        printf("Error");
        return 1;
    }
    FILE *pt = fopen("fusionado.txt", "w");
    if(!pt)
    {
        printf("Error");
        fclose(pb);
        return 1;
    }
    printf("\nTop 10\n");
    printf("Pos\tID\tNombre\tNota\n");

    for(int i = 0; i < vec->ce; i++)
    {
        Testudiante *estu = (Testudiante*)((char*)vec->vec + i * vec->tamElem);

        fprintf(pt, "%d,%s,%.2f\n", estu->id, estu->nombre, estu->nota);
        fwrite(estu, sizeof(Testudiante), 1, pb);

        if(i < 10)
        {
            printf("%d\t%d\t%s\t%.2f\n", i + 1, estu->id, estu->nombre, estu->nota);
        }
    }

    fclose(pt);
    fclose(pb);
    printf("\narchivos creados\n");
    return 0;
}
