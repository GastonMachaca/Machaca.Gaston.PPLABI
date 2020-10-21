#include "Trabajo.h"
#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int validarIdMotos(eMoto motos[],int tam,int id);
int validarIdTipos(eTipo tipos[],int tam,int id);
int validarIdColores(eColor color[],int tamC,int idC);
int validarIdServicios(eServicio servicios[],int tamS,int idS);
int validarIdClientes(eCliente clientes[],int tam,int id);

#endif // VALIDACIONES_H_INCLUDED
