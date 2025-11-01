#include "Desarrollo.h"

int CargarArchivoBin(char*archbin)
{
    FILE *pf=fopen(archbin,"wb");
    if(!pf)
        return ERROR_APERTURA;
    TProductos p[5]=
    {
        {"Jabon",100,50.5},
        {"Arroz",50,15.25},
        {"Aceite",75,33.3},
        {"Cloro",125,45.6},
        {"Escoba",150,75.3}
    };
    fwrite(p,sizeof(TProductos),5,pf);
    fclose(pf);
    return OK;
}

void LeerTxt(TPedidos *p,FILE *pf)
{
    char linea[LONGFILE];
    fgets(linea,LONGFILE,pf);
    char *act=strchr(linea,'\n');
    if(!act)
        act=strchr(linea,'\0');
    *act='\0';
    act-=3;//si es var strrchr hasta |
    sscanf(act,"%d",&p->cantidad);
    *act='\0';
    act-=6;//si es var strrchr hasta |
    sscanf(act,"%d",&p->cod_prod);
}

int Merge(char *archbin,char *archtxt)
{
    float guita=0, total=0;
    FILE *pb=fopen(archbin,"r+b");
    if(!pb)
        return ERROR_APERTURA;
    FILE *pt=fopen(archtxt,"r");
    if(!pt)
    {
        fclose(pb);
        return ERROR_APERTURA;
    }
    TProductos prod;
    TPedidos ped;
    while(!feof(pt))
    {
        LeerTxt(&ped,pt);
        fseek(pb,(long int)sizeof(TProductos)*(ped.cod_prod-1),0);
        fread(&prod,sizeof(TProductos),1,pb);
        if(ped.cantidad<=prod.stock)
        {
            prod.stock-=ped.cantidad;
            fseek(pb,-(long)sizeof(TProductos),1);
            fwrite(&prod,sizeof(TProductos),1,pb);
            guita=(prod.precio)*(ped.cantidad);
            total+=guita;
            if(!Realizado(guita,ped))
                puts("Error Realizado.txt");
        }else{
            if(!Faltantes(ped))
                puts("Error Pedidos");
        }
    }
    fclose(pb);
    fclose(pt);
    printf("TOTAL=%.2f", total);
    return OK;
}

bool Realizado(float dato,TPedidos p)
{
    FILE *pf=fopen("pedidos_realizados.txt","a");
    if(!pf)
        return false;
    fprintf(pf,"%d %d %.2f\n",p.cod_prod,p.cantidad,dato);
    fclose(pf);
    return true;
}
bool Faltantes(TPedidos p)
{
    FILE *pf=fopen("pedidos_faltantes.txt","a");
    if(!pf)
        return false;
    fprintf(pf,"%d %d\n",p.cod_prod,p.cantidad);
    fclose(pf);
    return true;
}

void mi_strcat(char*s1, char *s2) //s2=hola s1=mundo!
{
    char *fins1=s1;
    int largos2=mi_strlen(s2);
    while(*fins1!='\0')
        fins1++;
    char *origen=fins1;
    char *destino=fins1+largos2;
    while(origen>=s1)//!odnum olah
    {
        *destino=*origen;
        destino--;
        origen--;
    }
    char *p=s1;
    char *q=s2;
    while(*q!='\0')
    {
        *p=*q;
        p++;
        q++;
    }
}
int mi_strlen(const char*cad)
{
    int len=0;
    while(*cad++!='\0')
        len++;
    return len;
}
