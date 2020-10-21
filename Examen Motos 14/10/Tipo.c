#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Tipo.h"

void mostrarTipos(eTipo tipos[],int tam)
{
    //int error = 1;
    int flag = 0;
        if(tipos != NULL && tam > 0)
        {
            printf("\n      ///Listado de Tipos///       \n");
            printf("\n  ID      Descripcion \n");
            printf(" -----------------------\n");
            for(int i=0;i<tam;i++)
            {
                mostrarTipo(tipos[i]);
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

void mostrarTipo(eTipo tipo)
{
    printf("   %4d | %10s  \n",tipo.id, tipo.descripcion);
}

int cargarDescripcionTipos(eTipo tipos[],int tamT,int idT,char descripcionT[])
{
    int error=-1;

    if(tipos != NULL && tamT > 0 && idT > 0 && descripcionT != NULL)
    {
        for(int i = 0; i < tamT; i++)
        {
            if(tipos[i].id == idT)
            {
                strcpy(descripcionT,tipos[i].descripcion);
                error=0;
            }
        }
    }
    return error;
}
