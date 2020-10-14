#ifndef HARCODEO_H_INCLUDED
#define HARCODEO_H_INCLUDED

typedef struct
{
    int idTipo;
    char descripcionTipo[20];
}eTipo;

typedef struct
{
    int idColor;
    char nombreColor[20];
}eColor;

typedef struct
{
    int idServicio;
    char descripcionServicio[20];
    int precio;
}eServicio;


int harcodearTipos(eTipo moto[],int tam,int cant);
int harcodearColores(eColor moto[],int tam,int cant);
int harcodearServicios(eServicio moto[],int tam,int cant);
void mostrarTipo(eTipo tipo);
void mostrarTipos(eTipo tipos[],int tam);
void mostrarColores(eColor tipos[],int tam);
void mostrarColor(eColor tipo);
void mostrarServicios(eServicio tipos[],int tam);
void mostrarServicio(eServicio tipo);

#endif // HARCODEO_H_INCLUDED
