#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Trabajo.h"
#include "Validaciones.h"


int harcodearTrabajos(eTrabajo trabajos[],int tamTr,int cant)
{
    int idMotos[] = {1000,1001,1002,1003,1004};
    int idTrabajos[] = {10000,10001,10002,10003,10004,10005,10006,10007};
    eFecha fechas[] = {

        {21,3,2020},
        {10,5,1998},
        {1,6,2000},
        {9,4,2006},
        {24,5,1970},
        {9,4,2006},
        {24,5,1970},
        {12,8,1965}

    };
    int idServicios[] = {20000,20001,20002,20003,20004,20005,20006};

    int retorno = -1;

    if(trabajos != NULL && tamTr > 0 && cant <= tamTr)
    {
        retorno = 0;
        for(int i=0;i < cant; i++)
        {
            trabajos[i].id = idTrabajos[i];
            trabajos[i].idMoto = idMotos[i];
            trabajos[i].idServicio = idServicios[i];
            trabajos[i].fTrabajo = fechas[i];
            trabajos[i].isEmpty = 0;
            retorno++;
        }

    }
    return retorno;
}

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int error = 1;

    if(trabajos != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            trabajos[i].isEmpty= 1;
        }
        error=0;
    }
    return error;
}

int buscarLibreTrabajo(eTrabajo trabajos[],int tam)
{
    int indice = -1;

    for(int i = 0;i<tam;i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int mostrarTrabajos(eMoto motos[],int tam,eTrabajo trabajos[],int tamTr,eServicio servicios[],int tamS)
{
    int error = 1;
    int flag = 0;
        if(trabajos != NULL && tamTr > 0 && negarBanderaTrabajo(trabajos,tamTr))
        {
            printf("\n      ///Listado de Trabajos///       \n");
            printf("\n  ID       Marca      Fecha      Servicio \n");
            printf(" --------------------------------------------\n");
            for(int i=0;i<tamTr;i++)
            {
                if(trabajos[i].isEmpty == 0)
                {
                    mostrarTrabajo(trabajos[i],motos,tam,servicios,tamS);
                    flag = 1;
                }
            }

            if(flag == 0)
            {
                printf("\n      No hay trabajos en la lista.\n\n");
            }
            else
            {
                printf("\n\n");
            }
            error = 0;
        }

    return error;
}

void mostrarTrabajo(eTrabajo trabajo,eMoto motos[],int tamM, eServicio servicios[], int tamS)
{
    char descripcionS[20];
    char descripcionM[20];

    cargarDescripcionServicios(servicios,tamS,trabajo.idServicio,descripcionS);
    cargarMarcaMotos(motos,tamM,trabajo.idMoto,descripcionM);

    printf("%5d  |  %8s  |  %02d/%02d/%d  |  %12s \n", trabajo.id ,descripcionM, trabajo.fTrabajo.dia,trabajo.fTrabajo.mes,trabajo.fTrabajo.anio, descripcionS);

}


int altaTrabajos(eTrabajo trabajos[],int tamTr,eMoto motos[],int tam,eServicio servicios[],int tamS,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl,int legajo)
{
    int error = 1;

    eTrabajo nuevoTrabajo;

    int indice;
    int idServicio;
    int idMoto;

    if(trabajos != NULL && tamTr > 0 && legajo > 0)
    {
        system("cls");
        printf("    *** Alta Trabajo *** \n\n");
        indice = buscarLibreTrabajo(trabajos,tamTr);

        if(indice == -1)
        {
            printf("Sistema Completo.\n");
        }
        else
        {
            nuevoTrabajo.id = legajo;
            nuevoTrabajo.isEmpty=0;

            printf("\n Seleccione el ID que corresponda el servicio a la moto del siguiente listado: \n");
            mostrarServicios(servicios,tamS);
            printf("Ingrese su ID:");
            scanf("%d",&idServicio);

            while(validarIdServicios(servicios,tamS,idServicio)== 0)
            {
                printf("ERROR! Reingrese ID del servicio:");
                scanf("%d",&idServicio);
            }

            printf("\n Seleccione el ID de la moto del siguiente listado: \n");
            mostrarMotos(motos,tam,tipos,tamT,colores,tamC,clientes,tamCl);
            printf("Ingrese su ID:");
            scanf("%d",&idMoto);

            while(validarIdMotos(motos,tam,idMoto)== 0)
            {
                printf("ERROR! Reingrese ID de la moto:");
                scanf("%d",&idMoto);
            }
            printf("Ingrese fecha dd/mm/aaaa:");
            scanf("%d/%d/%d",&nuevoTrabajo.fTrabajo.dia,&nuevoTrabajo.fTrabajo.mes,&nuevoTrabajo.fTrabajo.anio);

            while(nuevoTrabajo.fTrabajo.dia < 0 || nuevoTrabajo.fTrabajo.dia > 31)
            {
                printf("El dia ingresado es invalido.\nVuelva a ingresar el dia :");
                scanf("%d",&nuevoTrabajo.fTrabajo.dia);
            }
            while(nuevoTrabajo.fTrabajo.mes < 0 || nuevoTrabajo.fTrabajo.mes > 12)
            {
                printf("El mes ingresado es invalido.\nVuelva a ingresar el mes :");
                scanf("%d",&nuevoTrabajo.fTrabajo.mes);
            }
            while(nuevoTrabajo.fTrabajo.anio != 2020)
            {
                printf("El año ingresado es invalido.\nEstamos en 2020 :");
                scanf("%d",&nuevoTrabajo.fTrabajo.anio);
            }

            nuevoTrabajo.idMoto = idMoto;
            nuevoTrabajo.idServicio = idServicio;

            trabajos[indice] = nuevoTrabajo;

            error=0;
        }

    }

    return error;
}

int negarBanderaTrabajo(eTrabajo trabajo[],int tam)
{
    int flag=0;

    for(int i=4; i<tam; i++)
    {
        if(trabajo[i].isEmpty == 0)
        {
            flag = 1;
        }
    }

    return flag;
}
