#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "harcodeo.h"
#include "motos.h"

#define TAM 5
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idTrabajo;
    eMoto moto;
    eServicio servicio;
    eFecha fTrabajo;
}eTrabajo;

char menu();

int main()
{
    char seguir = 's';
    char confirma;
    int proximoIdTipo=1000;
    int proximoIdColor=10000;
    int proximoIdServicio=20000;
    int id=1000;

    eMoto motos[TAM];
    eTipo tipo[TAM_T];
    eColor color[TAM_C];
    eServicio servicio[TAM_S];

    proximoIdTipo+= harcodearTipos(tipo,TAM_T,4);
    proximoIdColor+= harcodearColores(color,TAM_C,5);
    proximoIdServicio+= harcodearServicios(servicio,TAM_S,4);
    id+=harcodearMotos(motos,TAM,5);

    do
    {
        switch(menu())
        {

        case 'a':
            if(altaMotos(motos,TAM,tipo,TAM_T,color,TAM_C,id) == 0)
            {
                id++;
                printf("Alta exitosa!!\n");
            }
            else
            {
                printf("No se concreto exitosamente\n");
            }
            break;
        case 'b':
            break;
        case 'c':
            break;
        case 'd':
            system("cls");
            mostrarMotos(motos,tipo,color,TAM,TAM_C,TAM_T);
            break;
        case 'e':
            mostrarTipos(tipo,TAM_T);
            break;
        case 'f':
            mostrarColores(color,TAM_C);
            break;
        case 'g':
            mostrarServicios(servicio,TAM_S);
            break;
        case 'h':
            break;
        case 'i':
            break;
        case 'j':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");
        system("cls");

    }
    while( seguir == 's');


    return 0;
}


char menu()
{
    char opcion;

    printf("  ***Listar Motos***\n\n");
    printf("a. Alta Moto\n");
    printf("b. Modificar Moto \n");
    printf("c. Baja Moto \n");
    printf("d. Listar Motos\n");
    printf("e. Listar Tipos\n");
    printf("f. Listar Colores\n");
    printf("g. Listar Servicios \n");
    printf("h. Alta trabajo\n");
    printf("i. Listar trabajos \n");
    printf("j. Salir \n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}
