#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#define cant 1000


int main()
{
    int opcion, i, flag;
    eEmpleado empleado[cant];

    init(empleado, cant);


    do
    {

        opcion = menuOpcion_getNumero(opcion, "\n\n Opcion Seleccionada: ", "\n Error! *-* No es un dato valido.");

        switch(opcion)
        {
        case 1:
            alta(empleado, cant);
            break;
        case 2:
            break;
        case 3:
            baja(empleado, cant);
            break;
        case 4:
            break;
        case 5:
            printf("Adios! n_n");
            break;
        }

    }while(opcion != 5);

    return 0;
}
