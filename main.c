#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;
    int i = 0;
    float acumulador;
    float promedio = 0;
    int continuar;


    do
    {
        printf("Ingrese la edad: ");
        scanf("%d", &edad);
        printf("Su edad es: %d\n", edad);
        acumulador = acumulador + edad;
        i++;
        promedio++;
        printf("Desea continuar? 0=no 1=si");
        scanf("%d", &continuar);

    } while(continuar);

    promedio =  (float) acumulador / promedio;

    printf("\n" "El promedio es: %.2f ", promedio);

    return 0;
}

//el %f es la mascara para los float, ahora el %.2f sirve para poner cuantos decimales te va a mostrar.
