#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Validaciones.h"

int validarIdTipos(eTipo tipos[],int tam,int id)
{
    int esValido = 0;

    for(int i=0;i<tam;i++)
    {
        if(tipos[i].id == id)
        {
            esValido = 1;
            break;
        }
    }

    return esValido;
}

int validarIdMotos(eMoto motos[],int tam,int id)
{
    int esValido = 0;

    for(int i=0;i<tam;i++)
    {
        if(motos[i].id == id)
        {
            esValido = 1;
            break;
        }
    }

    return esValido;
}

int validarIdColores(eColor color[],int tamC,int idC)
{
    int esValido = 0;

    for(int i=0;i<tamC;i++)
    {
        if(color[i].id == idC)
        {
            esValido = 1;
            break;
        }
    }
    return esValido;
}

int validarIdServicios(eServicio servicios[],int tamS,int idS)
{
    int esValido = 0;

    for(int i=0;i<tamS;i++)
    {
        if(servicios[i].id == idS)
        {
            esValido = 1;
            break;
        }
    }

    return esValido;
}

int validarIdClientes(eCliente clientes[],int tam,int id)
{
    int esValido = 0;

    for(int i=0;i<tam;i++)
    {
        if(clientes[i].id == id)
        {
            esValido = 1;
            break;
        }
    }

    return esValido;
}
