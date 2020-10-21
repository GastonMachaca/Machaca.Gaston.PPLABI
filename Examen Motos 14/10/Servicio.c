#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Servicio.h"


void mostrarServicios(eServicio servicios[],int tamS)
{
    int flag = 0;
        if(servicios != NULL && tamS > 0)
        {
            printf("\n      ///Listado de Servicios///       \n");
            printf("\n  ID      Descripcion     Precio\n");
            printf(" ------------------------------------\n");
            for(int i=0;i<tamS;i++)
            {
                mostrarServicio(servicios[i]);
                flag = 1;
            }

            if(flag == 0)
            {
                printf("\n      No hay servicios en la lista.\n\n");
            }
            else
            {
                printf("\n\n");
            }
        }

}

void mostrarServicio(eServicio servicio)
{
    printf("  %4d |  %10s  |  %4d \n",servicio.id, servicio.descripcion,servicio.precio);
}

int cargarDescripcionServicios(eServicio servicios[],int tamS,int idS,char descripcionS[])
{
    int error=-1;

    if(servicios != NULL && tamS > 0 && idS > 0 && descripcionS != NULL)
    {
        for(int i = 0; i < tamS; i++)
        {
            if(servicios[i].id == idS)
            {
                strcpy(descripcionS,servicios[i].descripcion);
                error=0;
            }
        }
   }
    return error;
}
