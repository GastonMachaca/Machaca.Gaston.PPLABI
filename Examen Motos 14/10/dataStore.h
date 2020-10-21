#include "Fecha.h"


#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED

char nombres[10][20] = {
        "Juan",
        "Analia",
        "Aldo",
        "Magali",
        "Miguel",
        "Esteban",
        "Valentina",
        "Gaston",
        "Gustavo",
        "Irene"
};

char sexos[10] = {'m','f','m','f','m','m','f','m','m','f'};

int legajos[10] = {20000,20001,20002,20003,20004,20005,20006,20007,20008,20009};

float alturas[10] = {1.78,1.67,1.59,1.81,1.79,1.75,1.68,1.68,1.72,1.70};

int dias[10] = {4,5,29,26,18,1,5,2,11,15};

int meses[10] = {2,4,5,7,8,9,11,5,10,12};

int anios[10] = {2000,2020,2041,1999,1984,1934,1753,1852,1654,2006};

eFecha fechas[10] = {

        {21,3,2020},
        {10,5,1998},
        {1,6,2000},
        {9,4,2006},
        {24,5,1970},
        {9,4,2006},
        {24,5,1970},
        {12,8,1965},
        {5,6,2003},
        {21,9,1966}
};

int idDeportes[10] = {1005,1001,1000,1001,1003,1002,1001,1000,1004,1005};



#endif // DATASTORE_H_INCLUDED
