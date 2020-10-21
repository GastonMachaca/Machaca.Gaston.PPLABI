#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eTipo;

void mostrarTipos(eTipo tipos[],int tam);
void mostrarTipo(eTipo tipo);
int cargarDescripcionTipos(eTipo tipos[],int tam,int id,char descripcion[]);

#endif // TIPO_H_INCLUDED
