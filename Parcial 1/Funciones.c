#include "Declaracion.h"

int LargoReal(char *cad)
{
    char *ult=cad;
    while(*ult!='\0')
        ult++;
    while(ult>cad && *(ult-1)==' ')
            ult--;
    return (ult-cad);
}

void leotxt(FILE *pt,Cliente *clitxt)
{
    int len;
    char linea[LONGFILE];
    fgets(linea,LONGFILE,pt);
    char *act=strchr(linea,'\n');
    if(!act)
        act=strchr(linea,'\0');
    *act='\0';
    act-=26;//NombreFantasia[26]
    len=LargoReal(act);
    strncpy(clitxt->NombreFantasia,act,len);
    clitxt->NombreFantasia[len]='\0';
    *act='\0';
    act-=9;
    sscanf(act,"%f",&clitxt->Saldo);
    *act='\0';
    act-=30;
    len=LargoReal(act);
    strncpy(clitxt->ApellidoyNombre,act,len);
    clitxt->ApellidoyNombre[len]='\0';
    Normalizar(clitxt->ApellidoyNombre);
    *act='\0';
    act-=8;
    sscanf(act,"%d",&clitxt->CodCliente);
}

bool CargarArchivoBin(char *archbin)
{
    FILE *pf=fopen(archbin,"wb");
    if(!pf)
        return false;
    Cliente cl[5]=
    {
        {12345678,"cifuentes matias",550000.50,"chad"},
        {12345679,"apellido nombre",660000.67,"coach"},
        {12345681,"apellidoo nombree",770000.94,"mewing"},
        {12345683,"apellidooo nombreee",990000.78,"elturco"},
        {12345684,"apellidoooo nombreeee",100000.84,"chad"}
    };
    fwrite(cl,sizeof(Cliente),5,pf);
    fclose(pf);
    return true;
}

bool MostrarArchivoBin(const char*archbin)
{
    FILE *pf=fopen(archbin, "rb");
    if(!pf)
        return false;
    Cliente cl;
    fread(&cl,sizeof(Cliente),1,pf);
    while(!feof(pf))
    {
        printf("%d\t%-30s\t%08.2f\t%-26s\n",cl.CodCliente,cl.ApellidoyNombre,cl.Saldo,cl.NombreFantasia);
        fread(&cl,sizeof(Cliente),1,pf);
    }
    fclose(pf);
    return true;
}

bool ManejoError(const char*archerror, Cliente* clitxt)
{
    FILE *pf=fopen(archerror,"a");
    if(!pf)
        return false;
    fprintf(pf, "%8d%30s%8f%26s", clitxt->CodCliente, clitxt->ApellidoyNombre, clitxt->Saldo, clitxt->NombreFantasia);
    fclose(pf);
    return true;
}

void ManejoNuevo(Cliente *clitxt,FILE *pt,FILE *ptemp)
{
    Cliente clitemp;
    clitemp.CodCliente=clitxt->CodCliente;
    clitemp.Saldo=clitxt->Saldo;
    strcpy(clitemp.ApellidoyNombre,clitxt->ApellidoyNombre);
    strcpy(clitemp.NombreFantasia,clitxt->NombreFantasia);
    leotxt(pt,clitxt);
    while(!feof(pt) && clitemp.CodCliente==clitxt->CodCliente)
    {
        clitemp.Saldo+=clitxt->Saldo;
        leotxt(pt,clitxt);
    }
    fwrite(&clitemp,sizeof(Cliente),1,ptemp);
}

bool Merge(const char* archbin, const char* archtxt)
{
    Cliente clibin, clitxt;
    int cmp;
    FILE *pb=fopen(archbin,"rb");
    if(!pb)
    {
        puts("ERROR BINARIO");
        return false;
    }
    FILE *pt=fopen(archtxt,"r");
    if(!pt)
    {
        puts("ERROR TEXTO");
        fclose(pb);
        return false;
    }
    FILE *ptemp=fopen("clientesActualizado.bin","wb");
    if(!ptemp)
    {
        puts("ERROR TEMPORAL");
        fclose(pb);
        fclose(pt);
        return false;
    }
    fread(&clibin,sizeof(Cliente),1,pb);
    leotxt(pt,&clitxt);
    Normalizar(clibin.ApellidoyNombre);
    while(!feof(pb) && !feof(pt))
    {
        cmp=(clibin.CodCliente)-(clitxt.CodCliente);
        if(cmp==0)
        {
            if(strcmp(clibin.ApellidoyNombre,clitxt.ApellidoyNombre)==0)
            {
                if(strcmp(clibin.NombreFantasia,clitxt.NombreFantasia)!=0)
                    strcpy(clibin.NombreFantasia,clitxt.NombreFantasia);
                clibin.Saldo+=clitxt.Saldo;
            }
            else
            {
                ManejoError("errores.txt",&clitxt);
            }
            leotxt(pt,&clitxt);
        }
        if(cmp<0)//9-12
        {
            fwrite(&clibin,sizeof(Cliente),1,ptemp);
            fread(&clibin,sizeof(Cliente),1,pb);
            Normalizar(clibin.ApellidoyNombre);
        }
        if(cmp>0)//10-9
        {
            ManejoNuevo(&clitxt,pt,ptemp);
        }
    }
    while(!feof(pb))
    {
        fwrite(&clibin,sizeof(Cliente),1,ptemp);
        fread(&clibin,sizeof(Cliente),1,pb);
        Normalizar(clibin.ApellidoyNombre);
    }
    while(!feof(pt))
    {
        ManejoNuevo(&clitxt,pt,ptemp);
    }
    fclose(pb);
    fclose(pt);
    fclose(ptemp);
    remove(archbin);
    rename("clientesActualizado.bin",archbin);
    return true;
}

void **CrearMatriz(size_t fila, size_t columna, size_t tdato)
{
    void **mat=malloc(fila*sizeof(void*));
    if(!mat)
        return NULL;
    void **ult=mat+fila-1;
    for(void **i=mat;i<=ult;i++)
    {
        *i=malloc(columna*tdato);
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
void CargarMatriz(int **mat, size_t fila, size_t columna)
{
    int **ult=mat+fila;
    for(int **i=mat;i<ult;i++)
    {
        int *fc=*i+columna;
        for(int *j=*i;j<fc;j++)
        {
            puts("Ingrese elemento: ");
            scanf("%d", j);
        }
    }
}
int **ProductoMatriz(int **mat_1, size_t fila_1, size_t columna_1, int **mat_2, size_t fila_2, size_t columna_2)
{
    if(columna_1!=fila_2)
    {
        puts("No calculable.\n");
        return NULL;
    }
    int **resultado=(int**)CrearMatriz(fila_1, columna_2, sizeof(int));
    for(size_t i=0;i<fila_1;i++)
        for(size_t j=0;j<columna_2;j++)
        {
            resultado[i][j]=0;
            for(size_t a=0; a<columna_1;a++)
                resultado[i][j]+= mat_1[i][a]*mat_2[a][j];
        }
    return resultado;
}
void MostrarMatriz(int **matriz,size_t fila,size_t columna)
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

void Normalizar(char *cad)
{
    int palabra=0;
    char* fin=cad;
    char* inicio=cad;
    while(*fin!='\0')
    {
        *fin=tolower(*fin);
        fin++;
    }
    while(*inicio!='\0')
    {
        if(*inicio!=' ' && palabra==0)
        {
            *inicio=toupper(*inicio);
            palabra=1;
        }else if(*inicio==' ')
        {
            palabra=0;
        }
        inicio++;
    }
}
