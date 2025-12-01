#include "Desarrollo.h"

void eliminarComillas(char*linea)
{
    char *aux;
    while(*linea)
    {
        if(*linea == '"')
        {
            aux = linea;
            while(*aux)
            {
                *aux = *(aux+1);
                aux++;
            }
        }
        linea++;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 1

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void decodificarFecha(char *periodo)
{
    char *aux=periodo;//auxiliar con el contenido de las posiciones en "periodo"
    while(*aux!='\0'){
        switch(*aux){
            case '7': *aux='0'; break;
            case '4': *aux='1'; break;
            case '9': *aux='2'; break;
            case '8': *aux='3'; break;
            case '0': *aux='4'; break;
            case '6': *aux='5'; break;
            case '1': *aux='6'; break;
            case '3': *aux='7'; break;
            case '2': *aux='8'; break;
            case '5': *aux='9'; break;
            default: break;
        }
        aux++;
    }
}

int mi_atoi(char *cadena){
    int num = 0;
    while (*cadena) {
        if (*cadena >= '0' && *cadena <= '9') {
            num = num * 10 + (*cadena - '0');
        }
        cadena++;
    }
    return num;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 2

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int reescribirFecha(char *fechaNum)
{
    char *aux;
    int fecha = mi_atoi(fechaNum);
    int anio = fecha / 100;
    int mes = fecha % 100;
    int i = 0,j=0, auxi=1000;

    switch(mes)
    {
        case 1: aux = "Enero"; break;
        case 2: aux = "Febrero"; break;
        case 3: aux = "Marzo"; break;
        case 4: aux = "Abril"; break;
        case 5: aux = "Mayo"; break;
        case 6: aux = "Junio"; break;
        case 7: aux = "Julio"; break;
        case 8: aux = "Agosto"; break;
        case 9: aux = "Septiembre"; break;
        case 10: aux = "Octubre"; break;
        case 11: aux = "Noviembre"; break;
        case 12: aux = "Diciembre"; break;
        default: printf("Mes no valido\n"); return ERROR;
    }


    while (*(aux+j) != '\0')
    {
        *(fechaNum+i) = *(aux+j);
        i++;
        j++;
    }
    *(fechaNum+i) = ' ';
    *(fechaNum+i+1) = '-';
    *(fechaNum+i+2) = ' ';
    i += 3;

    for(int j=0;j<4;j++)
    {
        *(fechaNum+i++)=(anio/auxi)+ '0';
        anio-=(anio/auxi)*auxi;
        auxi=auxi/10;
    }
    *(fechaNum+i) = '\0';
    return OK;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 3

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void normalizarDescripcion(char *cadena)
{
    char *aux=cadena;
    int pri=0; //control primera letra
    while(*aux!='\0')
    {
        if(*aux>='A' && *aux<='Z' && pri!=0)
            *aux=*aux-'A'+'a';
        else if(pri==0 && *aux >= 'a' && *aux <= 'z')
            *aux=*aux-'a'+'A';
        aux++;
        pri=1;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 4             PUNTO 8

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void comaAPunto(char *cadena)
{
    char *aux = cadena;
    while(*aux != '\0')
    {
        if(*aux == ',')
            *aux = '.';
        aux++;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 5

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

double calcularMontoAjustado(Vector *vec)
{
    double monto, indiceDesde, indiceHasta, montoAjustado, variacion;
    int opcion;
    char region[10];
    char periodoDesde[20], periodoHasta[20];
    //pido monto al usuario
    printf("Ingrese el monto inicial(en pesos):");
    scanf("%lf", &monto);

    do
    {
        printf("\nSeleccione la region:\n 1. Nacional\n 2. GBA\n 3. Pampeana\n 4. Cuyo\n 5. Noroeste\n 6. Noreste\n 7. Patagonia\nOpcion:");
        scanf("%d", &opcion);
    }while(opcion<1 || opcion>7);

    switch (opcion)
    {
        case 1: strcpy(region, "Nacional"); break;
        case 2: strcpy(region, "GBA"); break;
        case 3: strcpy(region, "Pampeana"); break;
        case 4: strcpy(region, "Cuyo"); break;
        case 5: strcpy(region, "Noroeste"); break;
        case 6: strcpy(region, "Noreste"); break;
        case 7: strcpy(region, "Patagonia"); break;
    }
    printf("\nIngrese el periodo desde (formato AAAAMM): ");
    scanf("%6s", periodoDesde);
    if(reescribirFecha(periodoDesde)==ERROR)
        return ERROR;
    printf("Ingrese el periodo hasta (formato AAAAMM): ");
    scanf("%6s", periodoHasta);
    if(reescribirFecha(periodoHasta)==ERROR)
        return ERROR;

    //inicializo los indices para que no explote despues si no lo encuentra, además de tener una validacion de busqueda
    indiceDesde = -1;
    indiceHasta = -1;

    for(int i=0;i<vec->ce;i++)
    {
        Tdivisiones *dato=(Tdivisiones*)((char*)vec->vec+i*vec->tamElem);
        if(strcmp(dato->Descripcion,"Nivel general")==0 && strcmp(dato->region,region)==0)          //BUSCA NIVEL GENERAL EN LA REGION SELECCIONADA POR TECLADO
        {
            if(strcmp(dato->Periodo_codificado, periodoDesde)==0)
            {
                indiceDesde=dato->Indice_ipc;
            }
            else if(strcmp(dato->Periodo_codificado,periodoHasta)==0)
            {
                indiceHasta=dato->Indice_ipc;
            }
            if(indiceDesde != -1 && indiceHasta != -1)
                break; // ya encontramos ambos
        }
    }

    if(indiceDesde == -1 || indiceHasta == -1) {
        printf("No se encontraron los indices para los periodos ingresados.\n");
        return ERROR;
    }

    montoAjustado=monto*(indiceHasta/indiceDesde);
    variacion=((indiceHasta/indiceDesde)-1)*100;//PREGUNTAR SI EL PARENTESIS ESTA BIEN O ES (indiceHasta/indiceDesde-1) * 100

    printf("\n\n\n");
    puts("##################################\nAjuste por indice de precios (IPC)\n##################################");
    printf("\nRegion: %s", region);
    puts("\n----------------------------------");
    printf("\nPeriodo desde: %s", periodoDesde);
    printf("\nIndice desde: %.2lf", indiceDesde);
    puts("\n----------------------------------");
    printf("\nPeriodo hasta: %s", periodoHasta);
    printf("\nIndice hasta: %.2f", indiceHasta);
    puts("\n----------------------------------");
    printf("\nMonto inicial: $%.2lf", monto);
    printf("\nMonto ajustado: $%.2lf", montoAjustado);
    printf("\nVariacion(porcentual): %.2lf", variacion);
    puts("%");

    return montoAjustado;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 7

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int convertirFecha(char *Aniomes, int modo) // "202510" → "2025-10-01"
{
    if(modo==1)//bloque 1 de codigo
    {
        char *mes = Aniomes + 4;
        int numMes = (*mes - '0') * 10 + (*(mes + 1) - '0');
        if(numMes < 1 || numMes > 12)
            return ERROR;
        char *aux=Aniomes+6;
        *aux++='-';
        *aux++='0';
        *aux++='1';
        *aux='\0';
        char *fin = aux;
        mes=Aniomes+4;
        while(fin>=mes)
        {
            *(fin+1)=*fin;
            fin--;
        }
        *(mes)='-'; // pongo el '-' entre año y mes
    }else if(modo==2)//bloque 2 de codigo
    {
        // Modo 2: "Mayo - 2025" → "2025-05-01"
        char mes[15], anio[5];
        int numMes;
        // Extraer mes y año
        sscanf(Aniomes, "%s - %s", mes, anio);
        // Convertir nombre del mes a número
        if(strcmp(mes, "Enero") == 0) numMes = 1;
        else if(strcmp(mes, "Febrero") == 0) numMes = 2;
        else if(strcmp(mes, "Marzo") == 0) numMes = 3;
        else if(strcmp(mes, "Abril") == 0) numMes = 4;
        else if(strcmp(mes, "Mayo") == 0) numMes = 5;
        else if(strcmp(mes, "Junio") == 0) numMes = 6;
        else if(strcmp(mes, "Julio") == 0) numMes = 7;
        else if(strcmp(mes, "Agosto") == 0) numMes = 8;
        else if(strcmp(mes, "Septiembre") == 0) numMes = 9;
        else if(strcmp(mes, "Octubre") == 0) numMes = 10;
        else if(strcmp(mes, "Noviembre") == 0) numMes = 11;
        else if(strcmp(mes, "Diciembre") == 0) numMes = 12;
        else numMes = 1;
        // Formato: YYYY-MM-DD
        sprintf(Aniomes, "%s-%02d-01", anio, numMes);
    }
    if(modo == 3)
    {
        char mes[20], anio[10];
        char *p = Aniomes;   // <-- NO "fecha", es Aniomes
        char *m = mes;
        char *a = anio;
        while(*p && ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')))
            *m++ = *p++;
        *m = '\0';
        while(*p && !(*p >= '0' && *p <= '9'))
            p++;
        while(*p && (*p >= '0' && *p <= '9'))
            *a++ = *p++;
        *a = '\0';
        int numMes = 0;

        if(strcmp(mes,"Enero")==0) numMes=1;
        else if(strcmp(mes,"Febrero")==0) numMes=2;
        else if(strcmp(mes,"Marzo")==0) numMes=3;
        else if(strcmp(mes,"Abril")==0) numMes=4;
        else if(strcmp(mes,"Mayo")==0) numMes=5;
        else if(strcmp(mes,"Junio")==0) numMes=6;
        else if(strcmp(mes,"Julio")==0) numMes=7;
        else if(strcmp(mes,"Agosto")==0) numMes=8;
        else if(strcmp(mes,"Septiembre")==0) numMes=9;
        else if(strcmp(mes,"Octubre")==0) numMes=10;
        else if(strcmp(mes,"Noviembre")==0) numMes=11;
        else if(strcmp(mes,"Diciembre")==0) numMes=12;
        sprintf(Aniomes, "%s-%02d", anio, numMes);
    }
    return OK;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      LECTURA DIVISIONES Y BAJADA A VECTOR

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int leoTxtDivisiones(FILE *pt, Tdivisiones *divi)
{
    char temp[17];                // 16 caracteres + 1 para '\0'
    char linea[LONGFILE];
    char *aux;

    if(!fgets(linea, LONGFILE, pt))
        return ERROR;
    eliminarComillas(linea);                //SACA COMILLAS

    aux = strchr(linea, '\n');
    if(aux)
        *aux = '\0';

    aux = strrchr(linea, ';');
    if(!aux) return ERROR;
    strcpy(divi->Periodo_codificado, aux + 1);
    *aux = '\0';

    decodificarFecha(divi->Periodo_codificado);         //DECODIFICA

    reescribirFecha(divi->Periodo_codificado);          //REESCRIBE

    aux = strrchr(linea, ';');
    if(!aux) return ERROR;
    strcpy(divi->region, aux + 1);
    *aux = '\0';

    aux = strrchr(linea, ';');
    if(!aux) return ERROR;
    if(strcmp(aux + 1, "NA") == 0) {
        divi->v_i_a_IPC = 0.0;
    } else {
        sscanf(aux + 1, "%lf", &divi->v_i_a_IPC);
    }
    *aux = '\0';

    aux = strrchr(linea, ';');
    if(!aux) return ERROR;
    if(strcmp(aux + 1, "NA") == 0) {
        divi->v_m_ipc = 0.0;
    } else {
        sscanf(aux + 1, "%lf", &divi->v_m_ipc);
    }
    *aux = '\0';

    aux = strrchr(linea, ';');
    if(!aux) return ERROR;

    strncpy(temp, aux + 1, 16);   // copia máximo 16 caracteres
    temp[16] = '\0';              // aseguramos terminador nulo
    comaAPunto(temp);             // reemplaza ',' por '.'
    sscanf(temp, "%lf", &divi->Indice_ipc);

//    sscanf(aux + 1, "%lf", &divi->Indice_ipc);
    *aux = '\0';

    aux = strrchr(linea, ';');
    if(!aux) return ERROR;
    strcpy(divi->Clasificador, aux + 1);
    *aux = '\0';

    aux = strrchr(linea, ';');
    if(!aux) return ERROR;
    strcpy(divi->Descripcion, aux + 1);
    *aux = '\0';
    normalizarDescripcion(divi->Descripcion);  //NORMALIZA

    strcpy(divi->Codigo, linea);
    return OK;
}

int bajarArchivoAVector(char *nombre, Vector *vec, cmp Comparar)
{
    Tdivisiones reg;
    FILE *pf= fopen(nombre,"r");
    char linea[LONGFILE];
    if(!pf)
        return ERROR;

    if(!fgets(linea, LONGFILE, pf))//reviento la primera linea
        return ERROR;

    while(leoTxtDivisiones(pf,&reg)==OK)
    {
        insertarVecEnOrd(vec,&reg,Comparar);//COMO ES GENERICO NECESITAMOS UNA FUNCION DE COMPARACION
    }
//    printf("13104=%d\n",vec->ce); //CONTROL DE CARGAS DEL VECTOR (13104 ESPERADO)
    fclose(pf);
    return OK;
}

int cmpCod(const void*a, const void*b)
{
    Tdivisiones reg1=*(Tdivisiones*)a; //CASTEO A PUNTERO DE ESTRUCTURA Y REG1 LE PONGO EL CONTENIDO DE ESE PUNTERO
    Tdivisiones reg2=*(Tdivisiones*)b;
    int check=strcmp(reg1.Codigo,reg2.Codigo);
    if(check!=0)
        return check;
    return strcmp(reg1.Periodo_codificado,reg2.Periodo_codificado);
}

void recorrerVector(Vector *vec, Accion accion, void *datosAccion)
{
    void * ult = vec->vec + (vec->ce-1)*vec->tamElem;

    for(void * ini = vec->vec ; ini <=ult ; ini+=vec->tamElem)
        accion(ini,datosAccion);

}

int crearVector(Vector * vec, size_t tamElem , int cap)
{
    vec->vec = malloc(cap*tamElem);

    if(!vec->vec)
        return ERROR;

    vec->cap = cap;
    vec->ce  = 0;
    vec->tamElem = tamElem;

    return OK;
}

int  insertarVecEnOrd(Vector *vec , const void *elem ,cmp cmp)
{
    //SI ESTA LLENO RE ASIGNA MEMORIA
    if(vec->cap == vec->ce)
    {
        void *aux;
        int ncap=vec->cap*2;
        aux = realloc(vec->vec, vec->tamElem * ncap);
        if(!aux)
            return ERROR;
        vec->vec=aux;
        vec->cap=ncap;
    }
   void *ult = vec->vec + (vec->ce - 1)* vec->tamElem;
   void *act = vec->vec;
   int comparo;

   while(act<=ult && (comparo=cmp(act,elem))<0) //funcion de comparacion para el generico
        act += vec->tamElem;

//con estas lineas pierdo la carga.... (para archivos sin codigo repetido)
//    if(act<=ult && comparo==0)
//        return ERROR;

   /// Puede que salga del while porque llego al ultimo o
   memmove(act+vec->tamElem , act , ult - act + vec->tamElem);
   memcpy(act,elem,vec->tamElem);

   vec->ce=vec->ce+1;
   return OK;
}

void destruirVector(Vector *vec)
{
    free(vec->vec);
    vec->ce=0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      MOSTRAR Y ACTUALIZAR DIVISIONES

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void mostrarDivisiones(const void *elem, const void *datosAccion)
{
    Tdivisiones *dato = (Tdivisiones*)elem;

    printf("Codigo: %s\n", dato->Codigo);
    printf("Descripcion: %s\n", dato->Descripcion);
    printf("Clasificador: %s\n", dato->Clasificador);
    printf("Region: %s\n", dato->region);
    printf("Periodo: %s\n", dato->Periodo_codificado);
    printf("Indice IPC: %.2lf\n", dato->Indice_ipc);
    printf("Variacion Mensual: %.2lf\n", dato->v_m_ipc);
    printf("Variacion Interanual: %.2lf\n", dato->v_i_a_IPC);
    printf("================================================\n\n");
}

void escribirDivisionesCSV(const void *elem, const void *datosAccion)
{
    Tdivisiones*dato=(Tdivisiones*)elem;
    FILE*pf=(FILE*)datosAccion;

    // Escribir en formato CSV con los datos YA procesados
    fprintf(pf, "%s;%s;%s;%.2lf;%.2lf;%.2lf;%s;%s\n",
            dato->Codigo,
            dato->Descripcion,
            dato->Clasificador,
            dato->Indice_ipc,
            dato->v_m_ipc,
            dato->v_i_a_IPC,
            dato->region,
            dato->Periodo_codificado);
}

int crearNuevoCSVDivisiones(char *nombreArchivo, Vector *vec)
{
    FILE *pf;

    //por las dudas reviento el nombre
    remove(nombreArchivo);

    // Creo el nuevo archivo
    pf=fopen(nombreArchivo,"w");
    if(!pf)
        return ERROR;

    // Escribir primera linea
    fprintf(pf, "Codigo;Descripcion;Clasificador;Indice_ipc;v_m_ipc;v_i_a_IPC;region;Periodo\n");

    // Escribir todos los registros usando recorrerVector((((punterito a funcion))))
    recorrerVector(vec, escribirDivisionesCSV, pf);

    fclose(pf);
    return OK;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 6

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void clasificarGrupo(const Tdivisiones *divisiones, Tanalisis_IPC *analisis)        //      FILTRADO A BIEN O SERVICIO
{
    if(strcmp(divisiones->region,"Nacional")==0)
    {
        if (strcmp(divisiones->Descripcion,"Alimentos y bebidas no alcohólicas")==0 || strcmp(divisiones->Descripcion,"Bebidas alcohólicas y tabaco")==0 || strcmp(divisiones->Descripcion,"Prendas de vestir y calzado")==0 || strcmp(divisiones->Descripcion,"Bienes y servicios varios")==0 || strcmp(divisiones->Descripcion,"Equipamiento y mantenimiento del hogar")==0)
        {
            strcpy(analisis->Grupo, "Bienes");
        }
        else if (strcmp(divisiones->Descripcion,"Recreación y cultura")==0 || strcmp(divisiones->Descripcion,"Restaurantes y hoteles")==0 || strcmp(divisiones->Descripcion,"Salud")==0 || strcmp(divisiones->Descripcion,"Transporte")==0 || strcmp(divisiones->Descripcion,"Educación")==0 || strcmp(divisiones->Descripcion,"Comunicación")==0 || strcmp(divisiones->Descripcion, "Vivienda, agua, electricidad, gas y otros combustibles")==0)
        {
            strcpy(analisis->Grupo, "Servicios");
        }
        else
        {
            strcpy(analisis->Grupo, "Otro");
        }
        strcpy(analisis->Descripcion, divisiones->Descripcion);
        strcpy(analisis->Region, divisiones->region);
        strcpy(analisis->Periodo, divisiones->Periodo_codificado);
        analisis->Indice_IPC = divisiones->Indice_ipc;
    }
}

int periodoANumero(const char *periodo)
{
    char mes[15], anio[5];
    int numMes, numAnio;
    sscanf(periodo, "%s - %s", mes, anio);
    numAnio = atoi(anio);
    if(strcmp(mes, "Enero")==0)//esto para hacerlo con un switch hay que hacerlo con un [0] y NO SE PUEDEN USAR SUBINDICES
        numMes=1;
    else if(strcmp(mes, "Febrero")==0)
        numMes=2;
    else if(strcmp(mes, "Marzo")==0)
        numMes=3;
    else if(strcmp(mes, "Abril")==0)
        numMes=4;
    else if(strcmp(mes, "Mayo")==0)
        numMes=5;
    else if(strcmp(mes, "Junio")==0)
        numMes=6;
    else if(strcmp(mes, "Julio")==0)
        numMes=7;
    else if(strcmp(mes, "Agosto")==0)
        numMes=8;
    else if(strcmp(mes, "Septiembre")==0)
        numMes=9;
    else if(strcmp(mes, "Octubre")==0)
        numMes=10;
    else if(strcmp(mes, "Noviembre")==0)
        numMes=11;
    else if(strcmp(mes, "Diciembre")==0)
        numMes=12;
    else numMes=0;

    return numAnio*100+numMes; //"Mayo - 2017" -> 201705
}

int cmpPromedio(const void *a, const void *b)
{
    TPromedio *p1 = (TPromedio*)a;
    TPromedio *p2 = (TPromedio*)b;
    int fecha1 = periodoANumero(p1->Periodo);       //CAMBIO DE FECHA
    int fecha2 = periodoANumero(p2->Periodo);
    if(fecha1 != fecha2)
        return fecha1 - fecha2;
    return strcmp(p1->Grupo, p2->Grupo);
}

int agregarAlFinal(Vector *vec, const void *elem)
{
    // Si está lleno, redimensionar
    if(vec->cap == vec->ce)
    {
        void *aux;
        int ncap = vec->cap * 2;
        aux = realloc(vec->vec, vec->tamElem * ncap);
        if(!aux)
            return ERROR;
        vec->vec = aux;
        vec->cap = ncap;
    }

    // Copiar elemento al final
    memcpy((char*)vec->vec + vec->ce * vec->tamElem, elem, vec->tamElem);
    vec->ce++;

    return OK;
}

void* buscarEnVector(Vector *vec, const void *elem, cmp comparar)
{
    for(int i=0;i<vec->ce;i++)
    {
        void *actual=(char*)vec->vec + i * vec->tamElem;
        if(comparar(actual, elem)==0)
            return actual;
    }
    return NULL;
}

void analisisIPC(Vector *vecDivisiones)
{
    Tanalisis_IPC analisis;
    Vector vecRegistros;
    crearVector(&vecRegistros, sizeof(Tanalisis_IPC), 100);
    for(int i=0;i<vecDivisiones->ce;i++)
    {
        Tdivisiones *div=(Tdivisiones*)((char*)vecDivisiones->vec + i * vecDivisiones->tamElem);
        if(strcmp(div->Descripcion, "Nivel general")!=0)
        {
            clasificarGrupo(div, &analisis);
            if(strcmp(analisis.Region, "Nacional")==0 && (strcmp(analisis.Grupo, "Bienes")==0 || strcmp(analisis.Grupo, "Servicios")==0))
            {
                if(agregarAlFinal(&vecRegistros, &analisis) == ERROR)           //COMPARACION BIONES Y SERVICIOS        SOLO NACIONALES POR ENUNCIADO
                {
                    printf("Error al agregar registro\n");
                    destruirVector(&vecRegistros);
                    return;
                }
            }
        }
    }
    printf("Registros clasificados (Nacional): %d\n", vecRegistros.ce);//control de datos
                                                                                                    // Calcular promiedos
    Vector vecPromedios;
    crearVector(&vecPromedios, sizeof(TPromedio), 50);
    for(int i=0;i<vecRegistros.ce;i++)
    {
        Tanalisis_IPC *reg = (Tanalisis_IPC*)((char*)vecRegistros.vec + i * vecRegistros.tamElem);
                                                                                                    //estructura temporal para buscar
        TPromedio temp;
        strcpy(temp.Periodo, reg->Periodo);
        strcpy(temp.Grupo, reg->Grupo);
        temp.sumaIndices=reg->Indice_IPC;
        temp.cantidad=1;
        //buscar si ya existe este en el orden dado periodo-grupo
        TPromedio *encontrado = (TPromedio*)buscarEnVector(&vecPromedios, &temp, cmpPromedio);
        if(encontrado)
        {
            //actualizar existente
            encontrado->sumaIndices+=reg->Indice_IPC;
            encontrado->cantidad++;
        }
        else
        {
            ////nuevo reg
            if(insertarVecEnOrd(&vecPromedios, &temp, cmpPromedio)==ERROR)
            {
                printf("Error al agregar promedio\n");
                destruirVector(&vecRegistros);
                destruirVector(&vecPromedios);
                return;
            }
        }
    }
    //esto se lo pedi a gpt xq me parecia lindo que haya un formato de presentacion de esto
    printf("\nEVOLUCION DEL IPC - REGION NACIONAL\n");
    printf("====================================\n\n");
    printf("%-12s %-10s %15s %15s\n", "Fecha", "Region", "Bienes", "Servicios");
    printf("%-12s %-10s %15s %15s\n", "------------", "----------", "---------------", "---------------");
    //al existir un return arriba, estas variables deben ser declaradas en este punto, de lo contrario pueden ser no utilizadas y por ende, redundantes.
    char fechaISO[20];
    int i=0;
    while(i<vecPromedios.ce)
    {
        TPromedio *prom=(TPromedio*)((char*)vecPromedios.vec + i * vecPromedios.tamElem);
        double bienes=0.0,servicios=0.0;

        // cnvertir fecha usando la función del punto 7
        strcpy(fechaISO, prom->Periodo);
        convertirFecha(fechaISO, 2); // Modo 2: "Mes - Año" -> "YYYY-MM-DD"
        for(int j=i;j<vecPromedios.ce;j++)
        {
            TPromedio *temp=(TPromedio*)((char*)vecPromedios.vec + j * vecPromedios.tamElem);
            if(strcmp(temp->Periodo, prom->Periodo) != 0)
                break;
            double promedio = temp->sumaIndices / temp->cantidad;
            if(strcmp(temp->Grupo, "Bienes") == 0)
                bienes=promedio;
            else if(strcmp(temp->Grupo, "Servicios") == 0)
                servicios=promedio;
            i++;
        }
        printf("%-12s %-10s %15.4lf %15.4lf\n", fechaISO, "Nacional", bienes, servicios);
    }

    // Crear archivo CSV
    FILE *pf = fopen("analisis_ipc_grupos.csv", "w");
    if(pf)
    {
        fprintf(pf, "Fecha;Region;Bienes;Servicios\n");//header del file
        i=0;
        while(i<vecPromedios.ce)
        {
            TPromedio *prom=(TPromedio*)((char*)vecPromedios.vec + i * vecPromedios.tamElem);
            double bienes=0.0, servicios=0.0;

            //usando lap función del punto 7 con modo 2
            strcpy(fechaISO, prom->Periodo);
            convertirFecha(fechaISO, 2); //mando con la segunda condicion para cambiar akl fomrato pedido
            for(int j=i;j<vecPromedios.ce;j++)
            {
                TPromedio *temp = (TPromedio*)((char*)vecPromedios.vec + j * vecPromedios.tamElem);
                if(strcmp(temp->Periodo, prom->Periodo)!=0)
                    break;
                double promedio = temp->sumaIndices / temp->cantidad;
                if(strcmp(temp->Grupo, "Bienes") == 0)
                    bienes=promedio;
                else if(strcmp(temp->Grupo, "Servicios") == 0)
                    servicios=promedio;
                i++;
            }

            fprintf(pf, "%s;Nacional;%.4lf;%.4lf\n", fechaISO, bienes, servicios);
        }
        fclose(pf);
        printf("\nArchivo creado.\n");
    }
    else
    {
        printf("\nError al crear archivo CSV.\n");
    }
    destruirVector(&vecRegistros);//antes de salir reviento vectores total ya los use
    destruirVector(&vecPromedios);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      LECTURA ARCHIVO APERTURA

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int cmpCodAperturas(const void*a, const void*b)
{
    Taperturas reg1=*(Taperturas*)a; //CASTEO A PUNTERO DE ESTRUCTURA Y REG1 LE PONGO EL CONTENIDO DE ESE PUNTERO
    Taperturas reg2=*(Taperturas*)b;
    int check=strcmp(reg1.Codigo,reg2.Codigo);
    if(check!=0)
        return check;
    return strcmp(reg1.Periodo,reg2.Periodo);
}

int bajarArchivoAVectorAperturas(char *nombre, Vector *vec, cmp Comparar)
{
    Taperturas reg;
    FILE *pf= fopen(nombre,"r");
    char linea[LONGFILE];
    if(!pf)
        return ERROR;

    if(!fgets(linea, LONGFILE, pf))//reviento la primera linea
        return ERROR;

    while(leoTxtAperturas(pf,&reg)==OK)
    {
        insertarVecEnOrd(vec,&reg,Comparar);//COMO ES GENERICO NECESITAMOS UNA FUNCION DE COMPARACION
    }
//    printf("13104=%d\n",vec->ce); //CONTROL DE CARGAS DEL VECTOR (13104 ESPERADO)
    fclose(pf);
    return OK;
}

int leoTxtAperturas(FILE *pt, Taperturas *reg) //Codigo;Descripcion_aperturas;Clasificador;Periodo;Indice_IPC;v_m_IPC;v_i_a_IPC;Region
{
    char temp[17];
    char linea[LONGFILE];
    char *aux;

    if(!fgets(linea, LONGFILE, pt))
        return ERROR;

//    eliminarComillas(linea);//esto esta para sacarle comillas, pero este archivo no tiene asi que lo comentamos
    aux = strchr(linea, '\n');
    if(aux)
        *aux = '\0';

    aux = strrchr(linea, ';');//region
    if(!aux) return ERROR;
    strcpy(reg->region, aux+1);
    *aux = '\0';

    aux = strrchr(linea, ';');//v_i_a_IPC
    if(!aux) return ERROR;
    if(strcmp(aux + 1, "NA") == 0) {
        reg->v_i_a_IPC= 0.0;
    } else {
        sscanf(aux+1,"%lf",&reg->v_i_a_IPC);
    }
    *aux='\0';

    aux = strrchr(linea, ';');//v_m_ipc
    if(!aux) return ERROR;
    if(strcmp(aux + 1, "NA") == 0) {
        reg->v_m_ipc= 0.0;
    } else {
        sscanf(aux + 1, "%lf", &reg->v_m_ipc);
    }
    *aux='\0';

    aux = strrchr(linea, ';');//Indice_ipc
    if(!aux) return ERROR;

    strncpy(temp, aux + 1, 16);
    temp[16] = '\0';
    comaAPunto(temp);
    sscanf(temp, "%lf", &reg->Indice_ipc);
    *aux='\0';

    aux = strrchr(linea, ';');//Periodo
    if(!aux) return ERROR;
    strcpy(reg->Periodo, aux + 1);
    convertirFecha(reg->Periodo,1);
    *aux='\0';

    aux=strrchr(linea, ';');//Clasificador
    if(!aux) return ERROR;
    strcpy(reg->Clasificador, aux + 1);
    *aux='\0';

    aux = strrchr(linea, ';');//Descripcion_aperturas
    if(!aux) return ERROR;
    strcpy(reg->Descripcion_aperturas, aux + 1);
    *aux='\0';

    strcpy(reg->Codigo, linea);//Codigo

    return OK;
}

void mostrarAperturas(const void *elem, const void *datosAccion)
{
    Taperturas *dato=(Taperturas*)elem;
    printf("Codigo: %s\n", dato->Codigo);
    printf("Descripcion: %s\n", dato->Descripcion_aperturas);
    printf("Clasificador: %s\n", dato->Clasificador);
    printf("Region: %s\n", dato->region);
    printf("Periodo: %s\n", dato->Periodo);
    printf("Indice IPC: %.4lf\n", dato->Indice_ipc);
    printf("Variacion Mensual: %.4lf\n", dato->v_m_ipc);
    printf("Variacion Interanual: %.4lf\n", dato->v_i_a_IPC);
    printf("================================================\n\n");
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      PUNTO 9

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void calcularAlquilerAjustado(Vector *vec, cmp Comparar)
{
    double monto, indiceDesde = -1, indiceHasta = -1, variacion = 0, montoAjustado = 0;
    int opcion;
    char region[20];
    char periodoInicio[20];

    Vector vectabla;
    crearVector(&vectabla, sizeof(Ttabla) , 50);

                                                                                        //pido monto al usuario
    printf("Ingrese el monto inicial(en pesos):");
    scanf("%lf", &monto);

    do
    {
        printf("\nSeleccione la region:\n 1. GBA\n 2. Pampeana\n 3. Cuyo\n 4. Noroeste\n 5. Noreste\n 6. Patagonia\nOpcion:");
        scanf("%d", &opcion);
    }while(opcion<1 || opcion>6);

    switch (opcion)
    {
        case 1: strcpy(region, "GBA");
            break;
        case 2: strcpy(region, "Pampeana");
            break;
        case 3: strcpy(region, "Cuyo");
            break;
        case 4: strcpy(region, "Noroeste");
            break;
        case 5: strcpy(region, "Noreste");
            break;
        case 6: strcpy(region, "Patagonia");
            break;
    }
    printf("Ingrese periodo de inicio de contrato (AAAAMM): ");
    scanf("%6s",periodoInicio);
    if(convertirFecha(periodoInicio, 1)==ERROR)
    {
        printf("\nFecha Invalida.\n");
        return;
    }

    for(int i=0;i<vec->ce;i++)
    {

        Taperturas *dato=(Taperturas*)((char*)vec->vec+(i*vec->tamElem));
        if(strcmp(dato->Descripcion_aperturas,"Alquiler de la vivienda")==0 && strcmp(dato->region,region)==0 )     //SOLO ALQUILER DE LA VIVIENDA DE LA REGION INGRESADA POR ENUNCIADO
        {

            if(strcmp(dato->Periodo,periodoInicio)==0)
                {
                    indiceDesde=dato->Indice_ipc;
                }

            if(strcmp(dato->Periodo, periodoInicio) >= 0)   // >= al inicio CALCULA HASRA EL ULTIMO REGISTRO DEL ARCHIVO
            {
                //cargar estructura binaria
                Ttabla tabla;
                strcpy(tabla.periodo,dato->Periodo);
                tabla.Indice_ipc=dato->Indice_ipc;
                tabla.variacumulado=((dato->Indice_ipc / indiceDesde) - 1) * 100;
                tabla.montomes=monto * (dato->Indice_ipc / indiceDesde);
                insertarVecEnOrd(&vectabla, &tabla, Comparar);


                if(indiceHasta==-1 || dato->Indice_ipc>indiceHasta)
                    indiceHasta=dato->Indice_ipc;
            }

        }
    }

    if (indiceDesde == -1 || indiceHasta == -1)
    {
        printf("\nNo se encontraron datos suficientes para calcular el ajuste.\n");
        return;
    }

    variacion = ((indiceHasta / indiceDesde) - 1) * 100;
    montoAjustado = monto * (indiceHasta / indiceDesde);

    printf("\n--- RESULTADO DEL AJUSTE DE ALQUILER ---\n");
    printf("Region: %s\n", region);
    printf("Periodo desde: %s\n", periodoInicio);
    printf("Indice desde: %.2lf\n", indiceDesde);
    printf("Indice hasta: %.2lf\n", indiceHasta);
    printf("Variacion porcentual: %.1lf%%\n", variacion);
    printf("Monto ajustado: $%.2lf\n", montoAjustado);

    crearbinariotabla(&vectabla);
    destruirVector(&vectabla);
}

int cmptabla(const void*a, const void*b)
{
    Ttabla reg1=*(Ttabla*)a;
    Ttabla reg2=*(Ttabla*)b;
        int check=strcmp(reg1.periodo,reg2.periodo);
    if(check!=0)
        return check;
    return (reg1.Indice_ipc-reg2.Indice_ipc);
}

void crearbinariotabla(Vector *vectabla)
{
    FILE *pf=fopen("Archivobinariotablas.bin","wb");
    if(!pf)
        return ;

    for(int i=0;i<vectabla->ce;i++)
    {
        Ttabla *tabla=(Ttabla*)((char*)vectabla->vec + i * vectabla->tamElem);
        fwrite(tabla,sizeof(Ttabla),1,pf);
    }
    fclose(pf);
    mostrararchivobintabla("Archivobinariotablas.bin");
}

void  mostrararchivobintabla(const char*archbin)
{
    Ttabla tabla;
    FILE *pf=fopen(archbin,"rb");
    if(!pf)
        return ;
    fread(&tabla,sizeof(Ttabla),1,pf);
    puts("\n MOSTRAR BINARIO \n");
    printf("Periodo\t\tIndice IPC\tVariacion acumulada\tMonto mes\n");
    while(!feof(pf))
    {
        printf("%s\t%.4lf\t\t%.1lf\t\t%.2lf\n", tabla.periodo, tabla.Indice_ipc, tabla.variacumulado, tabla.montomes);
        fread(&tabla,sizeof(Ttabla),1,pf);
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                      REESCRITURA APERTURA

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void escribirAperturasCSV(const void *elem, const void *datosAccion)
{
    Taperturas *dato=(Taperturas*)elem;
    FILE*pf=(FILE*)datosAccion;

    // Orden correcto según el archivo original
    fprintf(pf, "%s;%s;%s;%s;%.4lf;%.4lf;%.4lf;%s\n", //Codigo;Descripcion_aperturas;Clasificador;Periodo;Indice_IPC;v_m_IPC;v_i_a_IPC;Region
            dato->Codigo,
            dato->Descripcion_aperturas,
            dato->Clasificador,
            dato->Periodo,           // Periodo va ANTES de los índices
            dato->Indice_ipc,
            dato->v_m_ipc,
            dato->v_i_a_IPC,
            dato->region);
}

int crearNuevoCSVAperturas(char *nombreArchivo, Vector *vec)
{
    FILE *pf;

    remove(nombreArchivo);

    pf=fopen(nombreArchivo,"w");
    if(!pf)
        return ERROR;

    // Header exacto del archivo original
    fprintf(pf, "Codigo;Descripcion_aperturas;Clasificador;Periodo;Indice_IPC;v_m_IPC;v_i_a_IPC;Region\n");

    // Función correcta
    recorrerVector(vec, escribirAperturasCSV, pf);

    fclose(pf);
    return OK;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//                                                                  DEFENSA

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void menuTP()
{
    Vector vec;
    Vector vectorPondera;
    int opcion;
    do
    {
        printf("\nIngrese opcion\nOpcion (0) = Cerrar Programa\n-----------------------TP-----------------------\nOpcion (1) = Punto 5\nOpcion (2) = Punto 6\nOpcion (3) = Punto 9\n---------------------DEFENSA--------------------\nOpcion (4) = Defensa 1\nOpcion (5) = Defensa 2\nOpcion (6) = Defensa 3\n\n");
        printf("Opcion = ");
        scanf("%d", &opcion);
    }while(opcion<0 || opcion>6);

    switch (opcion)
    {
        case 0: break;
        case 1:
            crearVector(&vec,sizeof(Tdivisiones),50);
            bajarArchivoAVector("serie_ipc_divisiones.csv",&vec,cmpCod);                            //puntos 1,2,3,4
            calcularMontoAjustado(&vec);                                                            //punto 5
//          recorrerVector(&vec,mostrarDivisiones,NULL);                                            //mostrar vector entero0
            printf("Cantidad de elementos leidos: %d\n",vec.ce);
//            if(crearNuevoCSVDivisiones("serie_ipc_divisiones.csv", &vec) == OK)
//                printf("Archivo 'serie_ipc_diviones.csv' creado exitosamente.\n");
//            else
//                printf("Error al crear el archivo.\n");
            destruirVector(&vec);
            break;
        case 2:
            crearVector(&vec,sizeof(Tdivisiones),50);
            bajarArchivoAVector("serie_ipc_divisiones.csv",&vec,cmpCod);
            analisisIPC(&vec);
//          recorrerVector(&vec,mostrarDivisiones,NULL);
            printf("Cantidad de elementos leidos: %d\n",vec.ce);
//            if(crearNuevoCSVDivisiones("serie_ipc_divisiones.csv", &vec) == OK)
//                printf("Archivo 'serie_ipc_diviones.csv' creado exitosamente.\n");
//            else
//                printf("Error al crear el archivo.\n");
            destruirVector(&vec);
            break;
        case 3:
            crearVector(&vec,sizeof(Taperturas),50);
            bajarArchivoAVectorAperturas("serie_ipc_aperturas.csv",&vec,cmpCodAperturas);              //PUNTOS 5 6 7 8
            calcularAlquilerAjustado(&vec,cmptabla);                                                //PUNTO 9
//            if(crearNuevoCSVAperturas("serie_ipc_aperturas.csv", &vec) == OK)
//                printf("Archivo 'serie_ipc_aperturas.csv' creado exitosamente.\n");
//            else
//                printf("Error al crear el archivo.\n");
////          recorrerVector(&vec,mostrarAperturas,NULL);                                             //mostrar vector entero
            printf("Cantidad de elementos leidos: %d\n",vec.ce);
            destruirVector(&vec);
            break;
        case 4:
            crearVector(&vec, sizeof(Tdivisiones), 50);
            bajarArchivoAVector("serie_ipc_divisiones.csv", &vec, cmpCodigoYFechaNumerica);
            calcularVariacionesMensuales(&vec);
            printf("Cantidad de elementos leidos: %d\n",vec.ce);
            destruirVector(&vec);
            break;
        case 5:
            crearVector(&vec,sizeof(Tdivisiones),50);
            bajarArchivoAVector("serie_ipc_divisiones.csv",&vec,cmpCod);
            calcularIndicePromedioCategorias(&vec);
            printf("Cantidad de elementos leidos: %d\n",vec.ce);
            destruirVector(&vec);
            break;
        case 6:
            crearVector(&vec, sizeof(Tdivisiones), 50);
            bajarArchivoAVector("serie_ipc_divisiones.csv", &vec, cmpCod);

            crearVector(&vectorPondera, sizeof(TPondera), 50);
            bajarPonderaAVector("pondera_gba.txt", &vectorPondera, cmpPondera);

            calcularIncidenciaDivisiones(&vec, &vectorPondera, "Junio - 2025");
            printf("Cantidad de elementos leidos: %d + %d = %d\n", vec.ce, vectorPondera.ce, (vec.ce+vectorPondera.ce));
            destruirVector(&vec);
            destruirVector(&vectorPondera);
            break;
    }
}

//PUNTO 1 DEFENSA

int cmpCodigoYFechaNumerica(const void*a, const void*b)
{
    Tdivisiones reg1 = *(Tdivisiones*)a;
    Tdivisiones reg2 = *(Tdivisiones*)b;
    int cmpCodigo = strcmp(reg1.Codigo, reg2.Codigo);
    if(cmpCodigo != 0)
        return cmpCodigo;
    int fecha1 = periodoANumero(reg1.Periodo_codificado);
    int fecha2 = periodoANumero(reg2.Periodo_codificado);
    return fecha1 - fecha2;
}

void calcularVariacionesMensuales(Vector *vec)
{
    Ttemporal *vecTemp=(Ttemporal*)malloc(vec->ce*sizeof(Ttemporal));
    if(!vecTemp)
    {
        printf("Error al asignar memoria para vector temporal\n");
        return;
    }
    FILE *pf = fopen("variaciones_mensuales.txt", "w");
    if (!pf) {
        printf("Error al crear el archivo variaciones_mensuales.txt\n");
        return;
    }
    fprintf(pf, "Fecha\t\tCodigo\t\tVariacion Mensual\n");
    double indice_mes_anterior = 0.0;
    char codigo_anterior[21] = "";
    int registros_escritos = 0;
    char fecha_temp[21];
    for(int i=0; i<vec->ce; i++)
    {
        Tdivisiones *dato = (Tdivisiones*)((char*)vec->vec+i * vec->tamElem);
        if(strcmp(dato->Clasificador, "Categorias")==0 && strcmp(dato->region, "Nacional")==0)
        {
            if(strcmp(dato->Codigo, codigo_anterior)!=0)//reseteo para no acumular de mas
            {
                indice_mes_anterior = 0.0;
                strcpy(codigo_anterior, dato->Codigo);
            }
            if(indice_mes_anterior>0.0)//aca entra a calcular la variacion solo si el indice anterior es vcalido
            {
                double variacion_mensual = ((dato->Indice_ipc/indice_mes_anterior)-1.0)*100.0;
                strcpy(fecha_temp, dato->Periodo_codificado);
                convertirFecha(fecha_temp, 3);
//                fprintf(pf, "%s\t\t%s\t\t%.1lf\n", fecha_temp, dato->Codigo, variacion_mensual); //lo arregle
                strcpy((vecTemp+registros_escritos)->Codigo, dato->Codigo);
                strcpy((vecTemp+registros_escritos)->Periodo, fecha_temp);
                (vecTemp+registros_escritos)->dato=variacion_mensual;
                registros_escritos++;
            }
            indice_mes_anterior = dato->Indice_ipc;//act indice
        }
    }
    qsort(vecTemp, registros_escritos, sizeof(Ttemporal), cmpTemporal);
    imprimirVariaciones(vecTemp,registros_escritos,pf);
    printf("Registros escritos: %d\n", registros_escritos);
    fclose(pf);
    free(vecTemp);
}

int cmpTemporal(const void*a, const void*b)
{
    Ttemporal *temp1 = (Ttemporal*)a;
    Ttemporal *temp2 = (Ttemporal*)b;
    int cmpFecha = strcmp(temp1->Periodo, temp2->Periodo);
    if(cmpFecha != 0)
        return cmpFecha;
    return strcmp(temp1->Codigo, temp2->Codigo);
}

void imprimirVariaciones(Ttemporal *vecTemp, int ce, FILE *pf)
{
    Ttemporal *aux=vecTemp;
    Ttemporal *auxFin=(vecTemp+ce);

    while(aux<auxFin)
    {
        fprintf(pf, "%7s\t\t%s\t\t%.1lf\n", aux->Periodo, aux->Codigo, aux->dato);
        aux++;
    }
}

//PUNTO 2 EDFENSA

void calcularIndicePromedioCategorias(Vector *vec)
{
    Ttemporal *vecTemp=(Ttemporal*)malloc(vec->ce*sizeof(Ttemporal));
    if(!vecTemp)
    {
        printf("Error al asignar memoria para vector temporal\n");
        return;
    }
    int registros_procesados=0;
    char fecha_temp[21];
    for(int i=0; i<vec->ce; i++)
    {
        Tdivisiones *dato = (Tdivisiones*)((char*)vec->vec + i * vec->tamElem);
        if(strcmp(dato->Clasificador, "Categorias")==0 && strcmp(dato->region, "Cuyo")==0)
        {
            strcpy(fecha_temp, dato->Periodo_codificado);
            convertirFecha(fecha_temp, 3);
            int encontrado = 0;
            for(int j=0; j<registros_procesados; j++)
            {
                if(strcmp((vecTemp + j)->Periodo, fecha_temp)==0 && strcmp((vecTemp + j)->Codigo, dato->Codigo)==0)
                {
                    (vecTemp+j)->dato+=dato->Indice_ipc;
                    encontrado=(j+1);
                    break;
                }
            }
            if(!encontrado)
            {
                strcpy((vecTemp+registros_procesados)->Codigo, dato->Codigo);
                strcpy((vecTemp+registros_procesados)->Periodo, fecha_temp);
                (vecTemp+registros_procesados)->dato=dato->Indice_ipc;
                registros_procesados++;
            }
        }
    }
    for(int i=0; i<registros_procesados; i++)
    {
        int contador=0;
        double suma=0.0;
        for(int j=0; j<vec->ce; j++)
        {
            Tdivisiones *dato=(Tdivisiones*)((char*)vec->vec+j*vec->tamElem);
            char temp_fecha[21];
            if(strcmp(dato->Clasificador, "Categorias")==0 && strcmp(dato->region, "Cuyo")==0)
            {
                strcpy(temp_fecha, dato->Periodo_codificado);
                convertirFecha(temp_fecha, 3);
                if(strcmp((vecTemp + i)->Periodo, temp_fecha)==0 && strcmp((vecTemp + i)->Codigo, dato->Codigo)==0)
                {
                    suma+=dato->Indice_ipc;
                    contador++;
                }
            }
        }
        if(contador>0)
            (vecTemp+i)->dato=(suma/contador);
    }
    qsort(vecTemp, registros_procesados, sizeof(Ttemporal), cmpTemporal);
    printf("\n--- INDICE PROMEDIO POR CATEGORIAS - REGION CUYO ---\n");
    printf("%-12s\t%-20s\t%s\n", "Fecha", "Codigo", "Indice Promedio");
    printf("----------------------------------------------------------------\n");

    for(int i=0; i<registros_procesados; i++)
        printf("%s\t\t%s\t\t%.4lf\n", (vecTemp+i)->Periodo, (vecTemp+i)->Codigo, (vecTemp+i)->dato);
    printf("\nTotal de registros mostrados: %d\n", registros_procesados);
    free(vecTemp);
}

//punto 3 defensa

int leoTxtPondera(FILE *pt, TPondera *pond)
{
    char linea[LONGFILE];
    char *aux;
    if(!fgets(linea, LONGFILE, pt))
        return ERROR;
    aux=strchr(linea, '\n');
    if(aux)
        *aux = '\0';
    //primer dato (Ponderador)
    aux = strrchr(linea, ';');
    if(!aux) return ERROR;
    comaAPunto(aux + 1);
    sscanf(aux + 1, "%lf", &pond->Ponderador);
    *aux = '\0';
    //segundo dato
    aux=strrchr(linea, ';');
    if(!aux) return ERROR;
    strcpy(pond->Region, aux+1);
    *aux='\0';
    //tercer dato
    strcpy(pond->Descripcion, linea);
    return OK;
}

int bajarPonderaAVector(char *nombre, Vector *vec, cmp Comparar)
{
    TPondera reg;
    FILE *pf= fopen(nombre,"r");
    char linea[LONGFILE];
    if(!pf)
        return ERROR;

    if(!fgets(linea, LONGFILE, pf))
        return ERROR;

    while(leoTxtPondera(pf,&reg)==OK)
    {
        insertarVecEnOrd(vec,&reg,Comparar);//COMO ES GENERICO NECESITAMOS UNA FUNCION DE COMPARACION
    }
//    printf("13104=%d\n",vec->ce); //CONTROL DE CARGAS DEL VECTOR (13104 ESPERADO)
    fclose(pf);
    return OK;
}

int cmpPondera(const void*a, const void*b)
{
    TPondera reg1=*(TPondera*)a;
    TPondera reg2=*(TPondera*)b;
        int check=strcmp(reg1.Descripcion,reg2.Descripcion);
    if(check!=0)
        return check;
    return (reg1.Ponderador-reg2.Ponderador);
}

void calcularIncidenciaDivisiones(Vector *vec, Vector *vectorPondera, const char *periodoDeterminado)
{
    double indiceNivelGeneral=-1;
    int numPeriodo, mes, anio, numPeriodoAnterior;
    char periodoAnterior[21];
    TIncidencia *vecIncidencias;
    int registros=0;
    for(int i=0; i<vec->ce; i++)//filtro por nivel genereal
    {
        Tdivisiones *dato=(Tdivisiones*)((char*)vec->vec+i*vec->tamElem);
        if(strcmp(dato->Periodo_codificado, periodoDeterminado)==0 && strcmp(dato->Descripcion, "Nivel general")==0 && strcmp(dato->region, "GBA")==0)
        {
            indiceNivelGeneral=dato->Indice_ipc;
            break;
        }
    }
    if(indiceNivelGeneral==-1)//corte por si no esta
    {
        printf("No se encontró el Nivel General para el período %s en GBA\n", periodoDeterminado);
        return;
    }
    numPeriodo=periodoANumero(periodoDeterminado);
    mes=numPeriodo % 100;
    anio=numPeriodo / 100;
    if(mes==1)
    {
        mes=12;
        anio--;
    }else{
        mes--;
    }
    numPeriodoAnterior=(anio*100)+mes;
    sprintf(periodoAnterior, "%d", numPeriodoAnterior);
    if(reescribirFecha(periodoAnterior)==ERROR)
    {
        printf("Error al convertir el período anterior\n");
        return;
    }
    vecIncidencias=(TIncidencia*)malloc(vec->ce*sizeof(TIncidencia));//vec temporal
    if(!vecIncidencias)
    {
        printf("Error al asignar memoria para incidencias\n");
        return;
    }
    for(int i=0; i<vec->ce; i++)
    {
        Tdivisiones *dato=(Tdivisiones*)((char*)vec->vec+i*vec->tamElem);
        double indiceAnterior=-1;
        double ponderador=-1;
        double incidencia;
    //filtro pedido
        if(strcmp(dato->Clasificador, "Nivel general y divisiones COICOP")==0 && strcmp(dato->region, "GBA")==0 && strcmp(dato->Periodo_codificado, periodoDeterminado)==0 && strcmp(dato->Descripcion, "Nivel general")!=0)
        {
            for(int j=0; j<vec->ce; j++)
            {
                Tdivisiones *datoAnterior = (Tdivisiones*)((char*)vec->vec + j * vec->tamElem);
                if(strcmp(datoAnterior->Codigo, dato->Codigo)==0 && strcmp(datoAnterior->Periodo_codificado, periodoAnterior)==0 && strcmp(datoAnterior->region, "GBA")==0)
                {
                    indiceAnterior = datoAnterior->Indice_ipc;
                    break;
                }
            }
            if(indiceAnterior==-1)
            {
                printf("No se encontró índice anterior para %s\n", dato->Descripcion);
                continue;
            }
            for(int k=0; k<vectorPondera->ce; k++)
            {
                TPondera *pond = (TPondera*)((char*)vectorPondera->vec + k * vectorPondera->tamElem);
                if(strcmp(pond->Descripcion, dato->Descripcion)==0 && strcmp(pond->Region, "GBA")==0)
                {
                    ponderador = pond->Ponderador;
                    break;
                }
            }
            if(ponderador==-1)
            {
                printf("Error: No se encontró ponderador para %s en GBA\n", dato->Descripcion);
                free(vecIncidencias);
                return;
            }
            incidencia=((dato->Indice_ipc/indiceAnterior)-1.0)*ponderador*100;
            strcpy((vecIncidencias+registros)->Codigo, dato->Codigo);
            strcpy((vecIncidencias+registros)->Descripcion, dato->Descripcion);
            strcpy((vecIncidencias+registros)->Periodo, dato->Periodo_codificado);
            (vecIncidencias+registros)->Indice_IPC=dato->Indice_ipc;
            (vecIncidencias+registros)->Indice_IPC_anterior=indiceAnterior;
            (vecIncidencias+registros)->Ponderador=ponderador;
            (vecIncidencias+registros)->Incidencia=incidencia;
            registros++;
        }
    }
    printf("\n--- INCIDENCIA DE DIVISIONES DEL IPC ---\n");
    printf("Region: GBA\n");
    printf("Periodo: %s\n", periodoDeterminado);
    printf("Indice Nivel General: %.4lf\n\n", indiceNivelGeneral);

    printf("Codigo\t   Descripcion\t\t\t\t\t\t\tIndice IPC\tPeriodo\t   Ponderador\tIncidencia\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    for(int i=0; i<registros; i++)
    {
        convertirFecha((vecIncidencias+i)->Periodo,2);
        printf("%-10s %-60s %-12.3lf    %-12s %-12.3lf %-12.2lf\n", (vecIncidencias+i)->Codigo, (vecIncidencias+i)->Descripcion, (vecIncidencias+i)->Indice_IPC, (vecIncidencias+i)->Periodo, (vecIncidencias+i)->Ponderador, (vecIncidencias+i)->Incidencia);
    }
//    printf("\nTotal de divisiones procesadas: %d\n", registros);
    free(vecIncidencias);
}
