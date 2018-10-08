#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#define cant 1000

int menuOpcion_getNumero(int opcion, char* mensaje, char* mensajeErrorUno)
{
    system("cls");
    printf("Bienvenido al Menu, que desea realizar?");
    printf("\n\n 1. Dar Alta Empleado.");
    printf("\n 2. Modificar legajo.");
    printf("\n 3. Dar Baja Empleado.");
    printf("\n 4. Informes.");
    printf("\n 5. Salir.");
    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion > 5 || opcion < 1)
    {
        printf(mensajeErrorUno);
        printf("\n\n Por favor ingrese otro numero: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

void init(eEmpleado empleado[], int cantidad)
{
    int i;

    for(i = 0; i < cantidad; i++)
    {
        empleado[i].isEmpty = 1;
    }
}

int obtenerEspacioLibre(eEmpleado empleado[], int cantidad)
{
    int i, retorno = -1;

    for(i = 0; i < cantidad; i++)
    {
        if(empleado[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

void alta(eEmpleado empleado[], int cantidad)
{
    int index;

    index = obtenerEspacioLibre(empleado, cantidad);

    if(index != -1)
    {
        empleado[index].id = cargaId();
        system("cls");

        printf("Ingrese el Apellido: ");
        fflush(stdin);

        fgets(empleado[index].apellido, sizeof(empleado[index].apellido)-2, stdin);
        cantidad = strlen(empleado[index].apellido);
        empleado[index].apellido[cantidad-1] = '\0';
        empleado[index].apellido[0] = toupper(empleado[index].apellido[0]);

        printf("\nIngrese el Nombre: ");

        fgets(empleado[index].nombre, sizeof(empleado[index].nombre)-2, stdin);
        cantidad = strlen(empleado[index].nombre);
        empleado[index].nombre[cantidad-1] = '\0';
        empleado[index].nombre[0] = toupper(empleado[index].nombre[0]);

        printf("\nSectores ");
        printf("\n1.RRHH");
        printf("\n2.Administracion");
        printf("\n3.Fabrica");
        printf("\n4.Ventas");
        printf("\n5.Tesoreria");
        printf("\n\nIndique el Sector: ");
        scanf("%d", &empleado[index].sector);

        printf("\nIngrese el Salario: ");
        scanf("%f", &empleado[index].salario);


        empleado[index].isEmpty = 0;
    }

}


void baja(eEmpleado empleado[], int cantidad)
{
    int i;
    int idAux;
    char respuesta;
    int flag = 0;

    system("cls");
    printf("Ingrese el ID del empleado: ");
    fflush(stdin);
    scanf("%d", &idAux);

    for(i = 0; i < cantidad; i++)
    {
        if(idAux == empleado[i].id)
        {
            flag = 1;
            printf("Apellido: %s \t Nombre: %s \t Sector: %d", empleado[i].apellido, empleado[i].nombre, empleado[i].sector);
            printf("\n\n Desea eliminar el registro? S/N: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            while(respuesta != 's' && respuesta != 'n')
            {
                printf("Error ingrese S o N");
                scanf("%c", &respuesta);
            }

            if(respuesta == 's')
            {
                empleado[i].isEmpty = 1;
                printf("El registro fue eliminado.");
                system("pause");
                break;
            }
            else
            {
                printf("El registro no fue eliminado.");
                system("pause");
                break;
            }
        }

    }

    if(flag == 0)
    {
        printf("Dato inexistente...");
        system("pause");
    }
}


void orden(int cantidad)
{
    eEmpleado empleado[cantidad], empAux;
    int i, j;

    for(i = 0; i < cantidad; i++){
        for(j = i+1; j < cantidad; j++)
        {
            if(strcmp(empleado[i].apellido, empleado[j].apellido) > 0)
            {
                empAux = empleado[i];
                empleado[i] = empleado[j];
                empleado[j] = empAux;
            }
            else if(strcmp(empleado[i].apellido, empleado[j].apellido) == 0 && strcmp(empleado[i].nombre, empleado[j].nombre) > 0)
            {
                empAux = empleado[i];
                empleado[i] = empleado[j];
                empleado[j] = empAux;
            }
        }
    }
}

static int cargaId(void)
{
    static int carga = 0;
    return carga++;
}
