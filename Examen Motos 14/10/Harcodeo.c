#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Tipo.h"

void mostrarDeportes(eDeporte sports[],int tam)
{
    //int error = 1;
    int flag = 0;
        if(sports != NULL && tam > 0)
        {
            printf("\n      ///Listado de Deportes///       \n");
            printf("\n  ID      Descripcion \n");
            printf(" -----------------------\n");
            for(int i=0;i<tam;i++)
            {
                mostrarDeporte(sports[i]);
                flag = 1;
            }

            if(flag == 0)
            {
                printf("\n      No hay deportes en la lista.\n\n");
            }
            else
            {
                printf("\n\n");
            }
            //error = 0;
        }

    //return error;
}

void mostrarDeporte(eDeporte sport)
{
    printf("   %4d | %10s  \n",sport.id, sport.descripcion);
}

int cargarDescripcionDeporte(eDeporte sports[],int tam,int id,char descripcion[])
{
    int error=-1;

    if(sports != NULL && tam > 0 && id > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(sports[i].id == id)
            {
                strcpy(descripcion,sports[i].descripcion);
                error=0;
            }
        }
    }

    return error;
}
