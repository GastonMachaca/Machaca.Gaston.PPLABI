#include "Motos.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int mostrarXcolor(eMoto motos[],int tam,eColor colores[], int tamC);
int mostrarXtipo(eMoto motos[],int tam,eTipo tipos[],int tamT);
int cilindradoMayor(eMoto motos[],int tam);
int listaMotosTipos(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl);
int listaMotosTiposColores(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC);
int coloresMayor(eMoto motos[],int tam,eColor colores[],int tamC);

#endif // INFORMES_H_INCLUDED
