#ifndef DATASTOREMOTOS_H_INCLUDED
#define DATASTOREMOTOS_H_INCLUDED

char descripcionTipos[10][20] = {
        "Enduro",
        "Chopera",
        "Scooter",
        "Ciclomotor"
};

char color[10][20] = {
        "Gris",
        "Negro",
        "Blanco",
        "Azul",
        "Rojo"
};

char nombresServicios[10][25] = {
        "Limpieza",
        "Ajuste",
        "Balanceo",
        "Cadena"
};

char marcas[10][20] = {

        "Mitsubishi",
        "Yamaha",
        "Honda",
        "Motomel",
        "Harley Davidson"
};

eTipo tipos[10] = {

        {1000,"Enduro"},
        {1001,"Chopera"},
        {1002,"Scooter"},
        {1003,"Ciclomotor"}
};

eColor colores[10] = {

        {10000,"Gris"},
        {10001,"Negro"},
        {10002,"Blanco"},
        {10003,"Azul"},
        {10004,"Rojo"}

};

int servicios[] = {250,300,17,190};
int idTipo[] = {1000,1001,1002,1003};
int idColor[] = {10000,10001,10002,10003,10004};
int idServicio[] = {20000,20001,20003,20004};
int idMotos[] = {1000,1001,1002,1003,1004};
int cilindrados[] = {50,125,500,600,750};
#endif // DATASTOREMOTOS_H_INCLUDED
