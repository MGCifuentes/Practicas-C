#include "puntoh.h"

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

char *mi_strcpy(char *s1, const char *s2) //cadenas igual tamaño
{
    char *aux=s1;
    while(*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1='\0';
    return aux;
}

char *mi_strcat(char *s1, const char *s2)
{
    char * aux = s1;
    while(*s1!='\0')
    {
        s1++;
    }
    while(*s2!='\0')
    {
        *s1 = *s2;
        s2++;
        s1++;
    }
    *s1 = '\0';
    return aux;
}

char *mi_strstr(const char *s1, const char *s2)
{
    char *aux;
    char *aguja;
    if(*s2=='\0')
        return (char *)s1;
    while(*s1!='\0')
    {
        if(*s1==*s2)
        {
            aux=(char *)s1;
            aguja=(char *)s2;
            while (*aux!='\0' && *aguja!='\0' && *aux==*aguja)
            {
                aux++;
                aguja++;
            }
            if(*aguja=='\0')
                return (char *)s1;
        }
        s1++;
    }
    return NULL;
}

char *mi_strrchr(char *s, int c)
{
    char *aux=NULL;
    while(*s!='\0')
    {
        if(*s==(char)c)
        {
            aux=s;
        }
        s++;
    }
    if(c=='\0')
        return s;
    return aux;
}

int mi_strcmpi(const char *s1,  const char *s2)
{
    while(*s1!='\0' && *s2!='\0')
    {
        char c1 = tolower((unsigned char)*s1);
        char c2 = tolower((unsigned char)*s2);
        if(c1!=c2)
            return c1-c2;
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

char *mi_strchr(char *s, int c)
{
    char *aux=NULL;
    while(*s!='\0')
    {
        if(*s==(char)c)
        {
            aux=s;
            return aux;
        }
        s++;
    }
    if(c=='\0')
        return s;
    return aux;
}

void EliminarBlancoP(char *s)
{
    char *inicio=s;
    while(*inicio==' ')
        inicio++;
    char *fin=s;
    while(*inicio!='\0')
    {
        *fin=*inicio;
        fin++;
        inicio++;
    }
    *fin='\0';
}

void EliminarBlancoI(char *s)
{
    char *fin=s;
    while(*s==' ')
    {
        *fin=*s;
        fin++;
        s++;
    }
    char *ultimo=s;
    while(*ultimo!='\0')
        ultimo++;
    ultimo--;
    while(ultimo>=s && *ultimo==' ')
        ultimo--;
    while(s<=ultimo)
    {
        if(*s!=' ')
        {
            *fin=*s;
            fin++;
        }
        s++;
    }
    while(*s!='\0')
    {
        *fin=*s;
        fin++;
        s++;
    }
    *fin='\0';
}

void EliminarBlancoF(char *s)
{
    char *fin=s;
    char *ultimo=s;
    while(*ultimo!='\0')
        ultimo++;
    ultimo--;
    while(ultimo>=s && *ultimo==' ')
        ultimo--;
    while(s<=ultimo)
    {
        *fin=*s;
        fin++;
        s++;
    }
    *fin='\0';
}

void EliminarBlanco(char *s)
{
    char *inicio=s;
    char *fin=s;
    while(*inicio!='\0')
    {
        if(*inicio!=' ')
        {
            *fin=*inicio;
            fin++;
        }
        inicio++;
    }
    *fin='\0';
}

void Capitalizar(char *s)
{
    int flag=0;
    while(*s!='\0')
    {
        if(*s==' ')
        {
            flag=0;//siguiente es palabra
        }else if(flag==0){
            *s=toupper(*s);
            flag=1;
        }
        s++;
    }
}

int CuentaVocal(const char *s)
{
    int cont=0;
    while(*s!='\0')
    {
        if(*s=='a' || *s=='A' || *s=='e' || *s=='E' || *s=='i' || *s=='I' || *s=='o' || *s=='O' || *s=='u' || *s=='U')
            cont++;
        s++;
    }
    return cont;
}

void VocalesMayus(char *s)
{
    while(*s!='\0')
    {
        if(*s=='a' || *s=='A' || *s=='e' || *s=='E' || *s=='i' || *s=='I' || *s=='o' || *s=='O' || *s=='u' || *s=='U')
            *s=toupper(*s);
        s++;
    }
}

int Palindromo(char *s)
{
    char *inicio=s;
    aMinuscula(s);
    while(*s!='\0')
        s++;
    char *fin=s-1;
    while(inicio<fin)
    {
        if(*inicio!=*fin)
            return 0;
        inicio++;
        fin--;
    }
    return 1;
}

void aMinuscula(char *s)
{
    while(*s!='\0')
    {
        *s=tolower(*s);
        s++;
    }
}

char *ReemplazarCadena(char *s1, char *s2)//cadena 2(s1) ahora tiene cadena(s2)
{
    char *inicio=s1;
    while(*s2!='\0')
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1='\0';
    return inicio;
}

char *InvertirCadena(char *s)
{
    char *inicio=s;
    char *fin=s;
    char aux;
    while(*fin!='\0')
        fin++;
    fin--;
    while(inicio<fin)
    {
        aux=*inicio;
        *inicio=*fin;
        *fin=aux;
        inicio++;
        fin--;
    }
    return s;
}

void CorrimientoTexto(char *s, int a)
{
    int aux=mi_strlen(s);
    char *inicio=s+a;
    char *fin=s;
    while(*fin!='\0')
        fin++;
    fin-=a-1;
    for(int i=0;i<a;i++)

}
