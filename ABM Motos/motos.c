#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "harcodeo.h"
#include "motos.h"
#include "dataStoreMotos.h"



int altaMotos(eMoto motos[],int tam,eTipo tipo[],int tamT,eColor color[],int tamC,int id)
{
    int error = 1;

    eMoto nuevaMoto;

    int idTipo;
    int idColor;
    int cilindrado;

    if(motos != NULL && tam > 0 && id >= 0)
    {
        system("cls");

        printf("    *** Alta Moto *** \n\n");

        nuevaMoto.idMoto = id;
        printf("Ingrese marca: ");
        fflush(stdin);
        gets(nuevaMoto.marca);

        printf("\n Escriba el ID que corresponda a su tipo de moto del siguiente listado: \n");
        mostrarTipos(tipo,tamT);
        printf("Ingrese su ID:");
        scanf("%d",&idTipo);

        while(validarIdTipos(tipo,tamT,idTipo)== 0)
        {
            printf("ERROR! Reingrese ID del tipo:");
            scanf("%d",&idTipo);
        }

        printf("\n Escriba el ID que corresponda al color de su moto del siguiente listado: \n");
        mostrarColores(color,tamC);
        printf("Ingrese su ID:");
        scanf("%d",&idColor);

        while(validarIdColores(color,tamC,idColor)== 0)
        {
            printf("ERROR! Reingrese ID del color:");
            scanf("%d",&idColor);
        }

        printf("Ingrese su cilindrado de la siguiente lista: \n");
        printf("- 50 \n");
        printf("- 125 \n");
        printf("- 500 \n");
        printf("- 600 \n");
        printf("- 750 \n");

        scanf("%d",&cilindrado);

        error=0;
    }

    return error;
}

int validarIdTipos(eTipo tipo[],int tam,int id)
{
    int esValido = 0;

    for(int i=0;i<tam;i++)
    {
        if(tipo[i].idTipo == id)
        {
            esValido = 1;
            break;
        }
    }

    return esValido;
}

int validarIdColores(eColor color[],int tam,int id)
{
    int esValido = 0;

    for(int i=0;i<tam;i++)
    {
        if(color[i].idColor == id)
        {
            esValido = 1;
            break;
        }
    }

    return esValido;
}

int mostrarMotos(eMoto motos[],eTipo tipo[],eColor color[],int tam,int tamC,int tamT)
{
    int error = 1;
    int flag = 0;
        if(motos != NULL && tam > 0)
        {
            printf("\n      ///Listado de Motos///       \n");
            printf("\n  ID     Marca     Tipo de Moto     Color       Cilindrada \n");
            printf(" -------------------------------------------------------------\n");
            for(int i=0;i<tam;i++)
            {
                mostrarMoto(motos[i],tipo,color,tamC,tamT);
                flag = 1;
            }

            if(flag == 0)
            {
                printf("\n      No hay personas en la lista.\n\n");
            }
            else
            {
                printf("\n\n");
            }
            error = 0;
        }

    return error;

}

void mostrarMoto(eMoto moto,eTipo tipo[],eColor color[],int tamC,int tamT)
{
    char descripcionC[20];
    char descripcionT[20];

    if(cargarDescripcion(tipo, color, descripcionC, descripcionT, moto.color.idColor, moto.tipo.idTipo, tamC, tamT)==0)
    {
        printf("    %5d      %12s   %15s   %15s  %3d\n", moto.idMoto ,moto.marca, descripcionC, descripcionT,moto.cilindrado);
    }else
    {
        printf("Ocurrio un inconveniente...\n\n");
    }
}

int cargarDescripcion(eTipo tipo[],eColor color[],char descripcionC[],char descripcionT[],int idC,int idT,int tamC,int tamT)
{
  int error=1;

        for(int i=0;i<tamC;i++)
        {
            if(idC==color[i].idColor)
            {
                strcpy(descripcionC, color[i].nombreColor);
                error=0;

            }
        }

        for(int i=0;i<tamT;i++)
        {
            if(idT==tipo[i].idTipo)
            {
                strcpy(descripcionT, tipo[i].descripcionTipo);
                error=0;

            }
        }

    return error;
}

int harcodearMotos(eMoto motos[],int tam,int cant)
{
    int retorno=-1;

    if(motos != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0;
        for(int i=0;i < cant ; i++)
        {
            motos[i].idMoto = idMotos[i];
            strcpy(motos[i].marca,marcas[i]);
            motos[i].tipo = tipos[i];
            motos[i].color = colores[i];
            motos[i].cilindrado = cilindrados[i];

            retorno++;
        }
    }

    return retorno;
}
