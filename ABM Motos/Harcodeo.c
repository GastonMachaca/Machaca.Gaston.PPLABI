#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "harcodeo.h"
#include "dataStoreMotos.h"


int harcodearTipos(eTipo moto[],int tam,int cant)
{
    int retorno=-1;

    if(moto != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0;
        for(int i=0;i < cant ; i++)
        {
            moto[i].idTipo = idTipo[i];
            strcpy(moto[i].descripcionTipo,descripcionTipos[i]);
            retorno++;
        }

    }

    return retorno;
}

int harcodearColores(eColor moto[],int tam,int cant)
{
    int retorno=-1;

    if(moto != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0;
        for(int i=0;i < cant ; i++)
        {
            moto[i].idColor = idColor[i];
            strcpy(moto[i].nombreColor,color[i]);
            retorno++;
        }
    }
    return retorno;
}

int harcodearServicios(eServicio moto[],int tam,int cant)
{
    int retorno=-1;

    if(moto != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0;
        for(int i=0;i < cant ; i++)
        {
            strcpy(moto[i].descripcionServicio, nombresServicios[i]);
            moto[i].idServicio = idServicio[i];
            moto[i].precio = servicios[i];
            retorno++;
        }
    }
    return retorno;
}

void mostrarTipos(eTipo tipos[],int tam)
{
    int flag = 0;
        if(tipos != NULL && tam > 0)
        {
            printf("\n      ///Listado de Tipos///       \n");
            printf("\n  ID      Descripcion\n");
            printf(" ------------------------\n");

            for(int i=0;i<tam;i++)
            {
                mostrarTipo(tipos[i]);
                flag=1;
            }

            if(flag == 0)
            {
                printf("\n      No hay personas en la lista.\n\n");
            }
            else
            {
                printf("\n\n");
            }
        }
}

void mostrarTipo(eTipo tipo)
{
    printf("   %4d | %10s    \n",tipo.idTipo,tipo.descripcionTipo);
}

void mostrarColores(eColor tipos[],int tam)
{
    int flag = 0;
        if(tipos != NULL && tam > 0)
        {
            printf("\n      ///Listado de Colores///       \n");
            printf("\n  ID      Descripcion\n");
            printf(" ------------------------\n");

            for(int i=0;i<tam;i++)
            {
                mostrarColor(tipos[i]);
                flag=1;
            }

            if(flag == 0)
            {
                printf("\n      No hay personas en la lista.\n\n");
            }
            else
            {
                printf("\n\n");
            }
        }
}

void mostrarColor(eColor tipo)
{
    printf("   %4d | %10s    \n",tipo.idColor,tipo.nombreColor);
}

void mostrarServicios(eServicio tipos[],int tam)
{
    int flag = 0;
        if(tipos != NULL && tam > 0)
        {
            printf("\n      ///Listado de Servicios///       \n");
            printf("\n  ID      Descripcion     Precio\n");
            printf(" ----------------------------------\n");

            for(int i=0;i<tam;i++)
            {
                mostrarServicio(tipos[i]);
                flag=1;
            }

            if(flag == 0)
            {
                printf("\n      No hay personas en la lista.\n\n");
            }
            else
            {
                printf("\n\n");
            }
        }

}

void mostrarServicio(eServicio tipo)
{
    printf("   %4d | %10s  |  %d  \n",tipo.idServicio,tipo.descripcionServicio,tipo.precio);
}
