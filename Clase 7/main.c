#include "Cabecera.h"

int main()
{
    Vector v;
    crearVector(&v);
    printf("%d", InsertarOrden(&v, 1));
    printf("%d", InsertarFinal(&v, 2));
    Mostrar(&v);
    return 0;
}
