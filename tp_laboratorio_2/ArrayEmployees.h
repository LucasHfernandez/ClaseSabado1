#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
}eEmpleado;

int menuOpcion_getNumero(int, char*, char*);
int obtenerEspacioLibre(eEmpleado[], int);
static int cargaId(void)
void init(eEmpleado[], int);
void alta(eEmpleado[], int);
void baja(eEmpleado[], int);
void orden(int);
#endif
