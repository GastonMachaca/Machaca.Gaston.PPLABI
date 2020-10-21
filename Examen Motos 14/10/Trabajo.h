#include "Motos.h"
#include "Servicio.h"
#include "Fecha.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fTrabajo;
    int isEmpty;
}eTrabajo;

int harcodearTrabajos(eTrabajo trabajos[],int tamTr,int cant);
int inicializarTrabajos(eTrabajo trabajos[], int tam);
int buscarLibreTrabajo(eTrabajo trabajos[],int tam);
int mostrarTrabajos(eMoto motos[],int tam,eTrabajo trabajos[],int tamTr,eServicio servicios[],int tamS);
void mostrarTrabajo(eTrabajo trabajo,eMoto motos[],int tamM, eServicio servicios[], int tamS);
int altaTrabajos(eTrabajo trabajos[],int tamTr,eMoto motos[],int tam,eServicio servicios[],int tamS,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl,int legajo);
int negarBanderaTrabajo(eTrabajo trabajo[],int tam);
#endif // TRABAJO_H_INCLUDED
