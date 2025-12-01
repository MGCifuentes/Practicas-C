#include "Declaraciones.h"

void leoTxt(FILE *pt, TPedido *pedido)
{
    char linea[LONGFILE];
    fgets(linea,LONGFILE,pt);
    char *act=strchr(linea,'\n');
    if(!act)
        act=strchr(linea,'\0');
    *act='\0';
    act-=3;
    sscanf(act,"%d",&pedido->cantidad);
    *act='\0';
    act-=4;
    sscanf(act,"%d",&pedido->cod_producto);
    *act='\0';
    act-=25;
    strncpy(pedido->nombre_empresa,act,26);
    pedido->nombre_empresa[26] = '\0';
}

int mergeArchivos(char*bin, char*txt)
{
    FILE *prod, *ped;
    TProducto producto;
    TPedido pedido;
    float totalFactura=0;
    prod=fopen(bin,"r+b");
    if(prod==NULL)
    {
        printf("Apertura Fallida");
        return ERROR;
    }
    ped=fopen(txt,"r");
    if(ped==NULL)
    {
        printf("Apertura Fallida");
        fclose(prod);
        return ERROR;
    }
    FILE *pt=fopen("pedidos_realizados.txt","a");
    if(pt==NULL)
    {
        printf("Error de Apertura");
        fclose(prod);
        fclose(ped);
        return ERROR;
    }
    FILE *pf=fopen("pedidos_faltantes.txt","a");
    if(pf==NULL)
    {
        printf("Error de Apertura");
        fclose(prod);
        fclose(ped);
        fclose(pt);
        return ERROR;
    }
    leoTxt(ped,&pedido);
    while(!feof(ped))
    {
        rewind(prod);
        fseek(prod,(pedido.cod_producto-1)*sizeof(TProducto),0);
        fread(&producto,sizeof(TProducto),1,prod);
        if((producto.stock)>=(pedido.cantidad))
        {
            totalFactura+=pedidosRealizados(&producto,&pedido, pt);
            fseek(prod,-(long)sizeof(TProducto),1);
            producto.stock-=pedido.cantidad;
            fwrite(&producto,sizeof(TProducto),1,prod);
        }else{
            pedidosFaltantes(&producto,&pedido, pf);
        }
        leoTxt(ped,&pedido);
    }
    printf("Total Facturado: %.2f\n", totalFactura);
    fclose(prod);
    fclose(ped);
    fclose(pt);
    fclose(pf);
    return OK;
}

void mostrarTxt(TPedido *pedido)
{
    printf("%s %d %d", pedido->nombre_empresa,pedido->cod_producto,pedido->cantidad);
}

float pedidosRealizados(TProducto *producto,TPedido *pedido, FILE *pf)
{
    float ttl=(float)(pedido->cantidad)*(producto->precio);
    fprintf(pf,"%25s%8.2f\n",pedido->nombre_empresa,ttl);
    return ttl;
}

int pedidosFaltantes(TProducto *producto,TPedido *pedido, FILE *pf)
{
    fprintf(pf,"%25s%25s%3d\n",pedido->nombre_empresa,producto->nombre_producto,pedido->cantidad);
    return OK;
}

int cargarBinario(char *bin)
{
    FILE *pf=fopen(bin,"wb");
    if(pf==NULL)
    {
        printf("Error de Apertura");
        return ERROR;
    }
    TProducto producto[5]=
    {
        {"joseojoseojoseojoseojoseo",500,203.5},
        {"amaraamaraamaraamaraamara",100,105.9},
        {"patopatopatopatopatopatoo",200,100.7},
        {"tomitomitomitomitomitomii",300,302.3},
        {"matimatimatimatimatimatii",400,123.6},
    };
    fwrite(producto,sizeof(TProducto),5,pf);
    fclose(pf);
    return OK;
}

int mostrarBinario(char *bin)
{
    FILE *pf=fopen(bin,"rb");
    TProducto producto;
    if(pf==NULL)
    {
        printf("Error de Apertura");
        return ERROR;
    }
    fread(&producto,sizeof(TProducto),1,pf);
    while(!feof(pf))
    {
        printf("%s %d %f\n",producto.nombre_producto,producto.stock,producto.precio);
        fread(&producto,sizeof(TProducto),1,pf);
    }
    fclose(pf);
    return OK;
}

void funcionString(char *cad1)//"¡AloH! muNDO, leUrc@ y #OñartxE!!"
{
    char *aux=cad1;
    char *fin=cad1;
    while(*aux==' ')
        aux++;
    while(*aux!='\0')
    {
        if((*aux>='A' && *aux<='Z') || (*aux>='a' && *aux<='z') || (*aux==' ') || (*aux=='ñ'))
        {
            if((*aux>='A' && *aux<='Z') || (*aux=='Ñ'))
            {
                *fin=*aux+('a'-'A');
            }else
            {
                *fin=*aux;
            }
            fin++;
        }
        aux++;
    }
    *fin='\0';
    invertirCadenaImpares(cad1);
}

void invertirCadenaImpares(char *cad)
{
    int pos=0;
    char *fin=cad;
    char *inicio=cad;
    while(*inicio!='\0')
    {
        while(*inicio==' ')
            inicio++;
        fin=inicio;
        while(*fin!=' ' && *fin!='\0')//me muevo entre palabras
            fin++;
        if((pos%2)==0)
            invertirPalabra(inicio,(fin-1));
        inicio=fin;
        pos++;
    }
}

void invertirPalabra(char *inicio, char *fin)
{
    char aux;
    while(inicio<fin)
    {
        aux=*inicio;
        *inicio=*fin;
        *fin=aux;
        inicio++;
        fin--;
    }
}
