#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Informes.h"

int mostrarXcolor(eMoto motos[],int tam,eColor colores[], int tamC)
{
    int error = 1;
    int flag = 0;
    int idColor;
    char color[20];

    if(motos != NULL && colores != NULL && tam > 0 && tamC > 0)
    {
        mostrarColores(colores,tamC);
        printf("Ingrese ID del color:");
        scanf("%d",&idColor);
        while(validarIdColores(colores,tamC,idColor)== 0)
        {
            printf("ERROR! Reingrese ID del deporte:");
            scanf("%d",&idColor);
        }
        cargarDescripcionColores(colores,tamC,idColor,color);
        printf("Listado de motos del color seleccionado %s\n\n", color);
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0 && motos[i].idColor == idColor)
            {
                printf("%s\n",motos[i].marca);
                //mostrarPersona(personas[i],sports,tamD);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\n      No hay motos que coincidan con %s\n\n",color);
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }

    return error;
}

int mostrarXtipo(eMoto motos[],int tam,eTipo tipos[],int tamT)
{
    int error = 1;
    int flag = 0;
    int idTipo;
    char tipo[20];

    if(motos != NULL && tipos != NULL && tam > 0 && tamT > 0)
    {

        mostrarTipos(tipos,tamT);
        printf("Ingrese ID del tipo:");
        scanf("%d",&idTipo);
        while(validarIdTipos(tipos,tamT,idTipo)== 0)
        {
            printf("ERROR! Reingrese ID del tipo:");
            scanf("%d",&idTipo);
        }
        cargarDescripcionTipos(tipos,tamT,idTipo,tipo);
        printf("Listado de motos del tipo seleccionado %s\n\n", tipo);
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0 && motos[i].idTipo == idTipo)
            {
                printf("%s\n",motos[i].marca);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\n      No hay motos que coincidan con %s\n\n",tipo);
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }

    return error;

}

int cilindradoMayor(eMoto motos[],int tam)
{
    int error=1;
    int contadores[tam];
    int mayor;
    int flag=0;

    if(motos!= NULL && tam > 0)
    {
        for(int p=0; p<tam; p++)
        {
            contadores[p]=0;
        }
        for(int s=1; s<tam; s++)
        {
            for(int j=0; j<tam; j++)
            {
                if(motos[j].isEmpty==0 && motos[j].cilindrada > motos[s].cilindrada)
                {
                    contadores[j]++;
                }
            }
        }

        for(int i=0; i<tam; i++)
        {
            if(contadores[i]>mayor || flag==0)
            {
                mayor=contadores[i];
                flag=1;
            }
        }

        printf("El o las motos de mayor cilindradas son: \n");

        for(int i=0; i<tam; i++)
        {
            if(contadores[i]==mayor)
            {
                printf("%s\n",motos[i].marca);
            }
        }
        printf("\n\n\n");
        error=0;
    }
    return error;
}

int listaMotosTipos(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl)
{
    int error = 1;
    int flag = 0;
    int idTipo;
    char tipo[20];

    if(motos != NULL && tipos != NULL && tam > 0 && tamT > 0)
    {

        mostrarTipos(tipos,tamT);
        printf("Ingrese ID del tipo:");
        scanf("%d",&idTipo);
        while(validarIdTipos(tipos,tamT,idTipo)== 0)
        {
            printf("ERROR! Reingrese ID del tipo:");
            scanf("%d",&idTipo);
        }
        cargarDescripcionTipos(tipos,tamT,idTipo,tipo);
        printf("Listado de motos del tipo seleccionado %s\n\n", tipo);
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0 && motos[i].idTipo == idTipo)
            {
                mostrarMoto(motos[i],tipos,tamT,colores,tamC,clientes,tamCl);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\n      No hay motos que coincidan con %s\n\n",tipo);
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }

    return error;
}

int listaMotosTiposColores(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC)
{
    int error = 1;
    int flag = 0;
    int idTipo;
    char tipo[20];
    int idColor;
    char color[20];
    int contador=0;

    if(motos != NULL && tipos != NULL && tam > 0 && tamT > 0)
    {

        mostrarTipos(tipos,tamT);
        printf("Ingrese ID del tipo:");
        scanf("%d",&idTipo);
        while(validarIdTipos(tipos,tamT,idTipo)== 0)
        {
            printf("ERROR! Reingrese ID del tipo:");
            scanf("%d",&idTipo);
        }
        cargarDescripcionTipos(tipos,tamT,idTipo,tipo);
        mostrarColores(colores,tamC);
        printf("Ingrese ID del color:");
        scanf("%d",&idColor);
        while(validarIdColores(colores,tamC,idColor)== 0)
        {
            printf("ERROR! Reingrese ID del deporte:");
            scanf("%d",&idColor);
        }
        cargarDescripcionColores(colores,tamC,idColor,color);
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0 && motos[i].idTipo == idTipo && motos[i].idColor == idColor)
            {
                //mostrarMoto(motos[i],tipos,tamT,colores,tamC);
                contador++;
                flag = 1;
            }
        }

        printf("La cantidad de motos de color %s y tipo %s son: %d",color,tipo,contador);

        if(flag == 0)
        {
            printf("\n      No hay motos que coincidan con %s\n\n",tipo);
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }

    return error;

}

int coloresMayor(eMoto motos[],int tam,eColor colores[],int tamC)
{
    int error=1;
    int contadores[tamC];
    int mayor;
    int flag=0;

    if(motos!= NULL && tam > 0 && colores != NULL)
    {
        for(int p=0; p<tamC; p++)
        {
            contadores[p]=0;
        }
        for(int s=0; s<tamC; s++)
        {
            for(int j=0; j<tam; j++)
            {
                if(motos[j].isEmpty==0 && motos[j].idColor == colores[s].id)
                {
                    contadores[s]++;
                }
            }
        }

        for(int i=0; i<tamC; i++)
        {
            if(contadores[i]>mayor || flag==0)
            {
                mayor=contadores[i];
                flag=1;
            }
        }

        printf("\n El o los colores mas seleccionados por el usuario son: \n");

        for(int i=0; i<tam; i++)
        {
            if(contadores[i]==mayor)
            {
                printf("%s\n",colores[i].descripcion);
            }
        }
        printf("\n\n\n");
        error=0;
    }
    return error;
}




