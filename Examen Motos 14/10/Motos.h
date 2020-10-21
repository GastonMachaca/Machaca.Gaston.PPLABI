
#include "Tipo.h"
#include "Color.h"

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;

}eCliente;

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int idCliente;
    int cilindrada;
    int isEmpty;    // 1 esta vacia , 0 esta cargada.

}eMoto;

int inicializarMotos(eMoto motos[], int tam);
int mostrarMotos(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl);
void mostrarMoto(eMoto moto, eTipo tipos[], int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl);
int harcodearMotos(eMoto motos[],int tamM,int cant);
int altaMotos(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl,int legajo);
int bajaMotos(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl);
int buscarMoto(eMoto motos[],int tam,int id);
int buscarLibreMoto(eMoto motos[],int tam);
int modificarMoto (eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl);
int subMenuModificar (eMoto motos[],eColor colores[],int tamC,int indice,int error);
int cargarMarcaMotos(eMoto motos[],int tam,int id,char descripcionM[]);
int negarBandera(eMoto motos[],int tam);
int harcodearClientes(eCliente clientes[],int tamCl,int cant);
void mostrarClientes(eCliente clientes[],int tamCl);
void mostrarCliente(eCliente cliente);
int cargarNombreCliente(eCliente clientes[],int tamCl,int idCl,char descripcionCl[]);
#endif // PERSONA_H_INCLUDED
