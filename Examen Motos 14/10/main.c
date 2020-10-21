#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Motos.h"
#include "Tipo.h"
#include "Color.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Informes.h"

#define TAM 10
#define TAM2 10
#define TAM_M 5
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_TR 4
#define TAM_CL 5

char menu();
void subMenuInformes (eMoto motos[],int tam,eColor colores[],int tamC,eServicio servicios[],int tamS,eTipo tipos[],int tamT,eCliente clientes[],int tamCl,int id);
int main()
{
    char seguir = 's';
    char confirma;
    int rta;
    int proximoLegajoM = 1000;
    int proximoLegajoT = 10000;

    eMoto motos[TAM];

    eTipo tipos[TAM_T]={

    {1000,"Enduro"},
    {1001,"Chopera"},
    {1002,"Scooter"},
    {1003,"Ciclomotor"}

    };

    eColor colores[TAM_C]={

    {10000,"Gris"},
    {10001,"Negro"},
    {10002, "Blanco"},
    {10003, "Azul"},
    {10004, "Rojo"}

    };

    eServicio servicios[TAM_S]={

    {20000,"Limpieza",250},
    {20001,"Ajuste",300},
    {20002,"Balanceo",17},
    {20003,"Cadena",190}

    };

    eCliente clientes[TAM_CL] = {

    {1000,"Alberto",'m'},
    {1001,"Juan",'m'},
    {1002,"Martina",'f'},
    {1003,"Luciano",'m'},
    {1004,"Felipe",'m'}
    /*{1000,"Juana",'f'},
    {1001,"Luis",'m'},
    {1002,"Manolo",'m'},
    {1003,"Sergio",'m'},
    {1004,"Lucia",'f'}*/

    };

    eTrabajo trabajos[TAM2];

    if(inicializarMotos(motos,TAM)== 0)
    {
        printf("\nInicializacion Exitosa de Motos!!!\n");
    }
    else
    {
        printf("Fallo al inicializar... \n");
    }

    proximoLegajoM+= harcodearMotos(motos,TAM,5);

    if(inicializarTrabajos(trabajos,TAM2)== 0)
    {
        printf("\nInicializacion Exitosa de Trabajos!!!\n");
    }
    else
    {
        printf("Fallo al inicializar... \n");
    }

    proximoLegajoT+= harcodearTrabajos(trabajos,TAM2,4);

    do
    {
        switch(menu())
        {
            case 'a':
                if(altaMotos(motos,TAM,tipos,TAM_T,colores,TAM_C,clientes,TAM_CL,proximoLegajoM) == 0)
                {
                    proximoLegajoM++;
                    printf("Alta exitosa!!\n");
                }
                else
                {
                    printf("No se concreto exitosamente\n");
                }
                break;

            case 'b':
                system("cls");
                modificarMoto(motos,TAM,tipos,TAM_T,colores,TAM_C,clientes,TAM_CL);
                break;

            case 'c':
                system("cls");
                rta = bajaMotos(motos,TAM,tipos,TAM_T,colores,TAM_C,clientes,TAM_CL);

                if(rta == 0)
                {
                    printf("Se realizo la baja con exito.");
                }
                else if (rta==1)
                {
                    printf("Problemas al intentar dar de baja.\n\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario.\n\n");
                }

                break;

            case 'd':
                system("cls");
                mostrarMotos(motos,TAM,tipos,TAM_T,colores,TAM_C,clientes,TAM_CL);
                break;

            case 'e':
                mostrarTipos(tipos,TAM_T);
                break;

            case 'f':
                mostrarColores(colores,TAM_C);
                break;

            case 'g':
                mostrarServicios(servicios,TAM_S);
                break;

            case 'h':
                if(altaTrabajos(trabajos,TAM2,motos,TAM,servicios,TAM_S,tipos,TAM_T,colores,TAM_C,clientes,TAM_CL,proximoLegajoT) == 0)
                {
                    proximoLegajoT++;
                    printf("Alta exitosa!!\n");
                }
                else
                {
                    printf("No se concreto exitosamente\n");
                }
                break;

            case 'i':
                mostrarTrabajos(motos,TAM,trabajos,TAM2,servicios,TAM_S);
                break;

            case 'j':
                subMenuInformes(motos,TAM,colores,TAM_C,servicios,TAM_S,tipos,TAM_T,clientes,TAM_CL,proximoLegajoM);
                break;

            case 'z':

                printf("Confirma salida?: ");
                fflush(stdin);
                scanf("%c",&confirma);
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
    while(seguir == 's');

    return 0;
}

char menu()
{
    char opcion;

    printf("  ***ABM Motos***\n\n");
    printf("a. Alta Motos\n");
    printf("b. Modificar Moto\n");
    printf("c. Baja Moto \n");
    printf("d. Listar Motos\n");
    printf("e. Listar Tipos \n");
    printf("f. Listar Colores \n");
    printf("g. Listar Servicios \n");
    printf("h. Alta Trabajo \n");
    printf("i. Listar Trabajos \n");
    printf("j. Informes \n");
    //printf("z.Salir \n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

void subMenuInformes (eMoto motos[],int tam,eColor colores[],int tamC,eServicio servicios[],int tamS,eTipo tipos[],int tamT,eCliente clientes[],int tamCl,int id)
{

    system("cls");

    int opcion;

    if(motos != NULL && tam > 0 && negarBandera(motos,tam))
    {
        printf("\n *** INFORMAR *** \n");
        printf("\n 1- Mostrar las motos del color seleccionado por el usuario.");
        printf("\n 2- Mostrar las motos de un tipo seleccionado.");
        printf("\n 3- Informar la o las motos de mayor cilindrada.");
        printf("\n 4- Mostrar un listado de las motos separadas por tipo.");
        printf("\n 5- Elegir un color y un tipo y contar cuantas motos hay de ese color y ese tipo.");
        printf("\n 6- Mostrar el o los colores más elegidos por los clientes.");

        printf("\n \n Elija una opcion: ");
        scanf("%d",&opcion);

        while(opcion<1 || opcion >6)
        {
            printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                mostrarXcolor(motos,tam,colores,tamC);
                break;
            case 2:
                mostrarXtipo(motos,tam,tipos,tamT);
                break;
            case 3:
                cilindradoMayor(motos,tam);
                break;
            case 4:
                listaMotosTipos(motos,tam,tipos,tamT,colores,tamC,clientes,tamCl);
                break;
            case 5:
                listaMotosTiposColores(motos,tam,tipos,tamT,colores,tamC);
                break;
            case 6:
                coloresMayor(motos,tam,colores,tamC);
                break;
        }
    }
    else
    {
        printf("\n No se dio de alta.");
    }
}




