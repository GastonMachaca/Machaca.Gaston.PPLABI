#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Color.h"

void mostrarColores(eColor colores[],int tamC)
{
    //int error = 1;
    int flag = 0;
        if(colores != NULL && tamC > 0)
        {
            printf("\n      ///Listado de Colores///       \n");
            printf("\n  ID      Descripcion \n");
            printf(" -----------------------\n");
            for(int i=0;i<tamC;i++)
            {
                mostrarColor(colores[i]);
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

void mostrarColor(eColor color)
{
    printf("   %4d | %10s  \n",color.id, color.descripcion);
}

int cargarDescripcionColores(eColor colores[],int tamC,int idC,char descripcionC[])
{
    int error=-1;

    if(colores != NULL && tamC > 0 && idC > 0 && descripcionC != NULL)
    {
        for(int i = 0; i < tamC; i++)
        {
            if(colores[i].id == idC)
            {
                strcpy(descripcionC,colores[i].descripcion);
                error=0;
            }
        }
   }
    return error;
}
