#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eColor;

void mostrarColores(eColor colores[],int tamC);
void mostrarColor(eColor color);
int cargarDescripcionColores(eColor colores[],int tamC,int idC,char descripcionC[]);

#endif // COLOR_H_INCLUDED
