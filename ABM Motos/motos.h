#include "harcodeo.h"

#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED

typedef struct
{
    int idMoto;
    char marca[20];
    eTipo tipo;
    eColor color;
    int cilindrado;

}eMoto;

int altaMotos(eMoto motos[],int tam,eTipo tipo[],int tamT,eColor color[],int tamC,int id);
int validarIdTipos(eTipo tipo[],int tam,int id);
int validarIdColores(eColor color[],int tamC,int id);
int cargarDescripcionTipos(eMoto motos[],int tam,int id,char descripcion[]);
void mostrarMoto(eMoto moto,eTipo tipo[],eColor color[],int tamC,int tamT);
int mostrarMotos(eMoto motos[],eTipo tipo[],eColor color[],int tam,int tamC,int tamT);
int cargarDescripcion(eTipo tipos[],eColor color[],char descripcionC[],char descripcionT[],int idC,int idT,int tamC,int tamT);
int harcodearMotos(eMoto motos[],int tam,int cant);
#endif // MOTOS_H_INCLUDED
