
#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

void mostrarServicios(eServicio servicios[],int tamS);
void mostrarServicio(eServicio servicio);
int cargarDescripcionServicios(eServicio servicios[],int tamS,int idS,char descripcionS[]);

#endif // SERVICIO_H_INCLUDED
