#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Motos.h"
#include "Validaciones.h"

void mostrarClientes(eCliente clientes[],int tamCl)
{
    //int error = 1;
    int flag = 0;
        if(clientes != NULL && tamCl > 0)
        {
            printf("\n      ///Listado de Colores///       \n");
            printf("\n  ID      Nombre     Sexo \n");
            printf(" ----------------------------\n");
            for(int i=0;i<tamCl;i++)
            {
                mostrarCliente(clientes[i]);
                flag = 1;
            }

            if(flag == 0)
            {
                printf("\n      No hay clientes en la lista.\n\n");
            }
            else
            {
                printf("\n\n");
            }
            //error = 0;
        }

    //return error;
}

void mostrarCliente(eCliente cliente)
{
    printf("   %4d | %10s | %c \n",cliente.id, cliente.nombre,cliente.sexo);
}

int cargarNombreCliente(eCliente clientes[],int tamCl,int idCl,char descripcionCl[])
{
    int error=-1;

    if(clientes != NULL && tamCl > 0 && idCl > 0 && descripcionCl != NULL)
    {
        for(int i = 0; i < tamCl; i++)
        {
            if(clientes[i].id == idCl)
            {
                strcpy(descripcionCl,clientes[i].nombre);
                error=0;
            }
        }
   }
    return error;
}

int harcodearMotos(eMoto motos[],int tamM,int cant)
{
    int ids[] = {1000,1001,1002,1003,1004};
    char marcas[][20] = {"Ducati","Yamaha","Victoria","Triumph","KTM"};
    int idsTipos[] = {1000,1001,1002,1003,1004};
    int idsColores[] = {10000,10001,10002,10003,10004};
    int cilindradas[] = {50,125,500,600,750};

    int retorno = -1;

    if(motos != NULL && tamM > 0 && cant <= tamM)
    {
        retorno = 0;
        for(int i=0;i < cant; i++)
        {
            motos[i].id = ids[i];
            strcpy(motos[i].marca,marcas[i]);
            motos[i].idTipo = idsTipos[i];
            motos[i].idColor = idsColores[i];
            motos[i].cilindrada = cilindradas[i];
            motos[i].isEmpty = 0;
            retorno++;
        }

    }
    return retorno;
}

int inicializarMotos(eMoto motos[], int tam)
{
    int error = 1;

    if(motos != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            motos[i].isEmpty= 1;
        }
        error=0;
    }
    return error;
}

int buscarLibreMoto(eMoto motos[],int tam)
{
    int indice = -1;

    for(int i = 0;i<tam;i++)
    {
        if(motos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int mostrarMotos(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl)
{
    int error = 1;
    int flag = 0;
        if(motos != NULL && tam > 0 && negarBandera(motos,tam))
        {
            printf("\n      ///Listado de Motos///       \n");
            printf("\n  ID       Marca           Color        Tipo     Cilindrada   Nombre\n");
            printf(" ----------------------------------------------------------------------\n");
            for(int i=0;i<tam;i++)
            {
                if(motos[i].isEmpty == 0)
                {
                    mostrarMoto(motos[i],tipos,tamT,colores,tamC,clientes,tamCl);
                    flag = 1;
                }
            }

            if(flag == 0)
            {
                printf("\n      No hay motos en la lista.\n\n");
            }
            else
            {
                printf("\n\n");
            }
            error = 0;
        }

    return error;
}

void mostrarMoto(eMoto moto, eTipo tipos[], int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl)
{
    char descripcionT[20];
    char descripcionC[20];
    char descripcionCl[20];

    cargarDescripcionTipos(tipos,tamT,moto.idTipo,descripcionT);
    cargarDescripcionColores(colores,tamC,moto.idColor,descripcionC);
    cargarNombreCliente(clientes,tamCl,moto.idCliente,descripcionCl);

    printf("%5d   %8s   %12s   %12s  %9d   %8s\n", moto.id ,moto.marca, descripcionC, descripcionT,moto.cilindrada,descripcionCl);

}

int altaMotos(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl,int legajo)
{
    int error = 1;

    eMoto nuevaMoto;

    int indice;
    int idTipo;
    int idColor;
    int idCliente;

    if(motos != NULL && tam > 0 && legajo > 0)
    {
        system("cls");
        printf("    *** Alta Moto *** \n\n");
        indice = buscarLibreMoto(motos,tam);

        if(indice == -1)
        {
            printf("Sistema Completo.\n");
        }
        else
        {
            nuevaMoto.id = legajo;
            nuevaMoto.isEmpty=0;
            printf("Ingrese marca: ");
            fflush(stdin);
            gets(nuevaMoto.marca);

            printf("\n Escriba el ID que corresponda a su nombre del siguiente listado: \n");
            mostrarClientes(clientes,tamCl);
            printf("Ingrese su ID:");
            scanf("%d",&idCliente);

            while(validarIdClientes(clientes,tamCl,idCliente)== 0)
            {
                printf("ERROR! Reingrese ID del tipo:");
                scanf("%d",&idCliente);
            }
            printf("\n Escriba el ID que corresponda a su tipo de moto del siguiente listado: \n");
            mostrarTipos(tipos,tamT);
            printf("Ingrese su ID:");
            scanf("%d",&idTipo);

            while(validarIdTipos(tipos,tamT,idTipo)== 0)
            {
                printf("ERROR! Reingrese ID del tipo:");
                scanf("%d",&idTipo);
            }

            printf("\n Escriba el ID que corresponda al color de su moto del siguiente listado: \n");
            mostrarColores(colores,tamC);
            printf("Ingrese su ID:");
            scanf("%d",&idColor);

            while(validarIdColores(colores,tamC,idColor)== 0)
            {
                printf("ERROR! Reingrese ID del color:");
                scanf("%d",&idColor);
            }

            printf("\nIngrese una cilindrada de la siguiente lista: \n");
            printf("- 50 \n");
            printf("- 125 \n");
            printf("- 500 \n");
            printf("- 600 \n");
            printf("- 750 \n");
            fflush(stdin);
            printf("\n");
            scanf("%d",&nuevaMoto.cilindrada);
            while(nuevaMoto.cilindrada != 50 && nuevaMoto.cilindrada !=125 && nuevaMoto.cilindrada !=500 && nuevaMoto.cilindrada != 600 && nuevaMoto.cilindrada !=750)
            {
                system("cls");
                printf("\nERROR! Vuelva a ingresar una nueva cilindrada valida de la siguiente lista: \n");
                printf("- 50 \n");
                printf("- 125 \n");
                printf("- 500 \n");
                printf("- 600 \n");
                printf("- 750 \n");
                fflush(stdin);
                printf("\n");
                scanf("%d",&nuevaMoto.cilindrada);
            }

            nuevaMoto.idCliente = idCliente;
            nuevaMoto.idTipo = idTipo;
            nuevaMoto.idColor = idColor;

            motos[indice] = nuevaMoto;

            error=0;
        }

    }

    return error;
}

int bajaMotos(eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl) // Devuelve 0 baja exitosa , 1 hubo un problema ,  2 se cancelo.
{
    int error = 1;
    int indice;
    int legajo;
    char confirma;

    if(motos != NULL && tam > 0 && negarBandera(motos,tam))
    {
        system("cls");
        printf("*** Baja Motos ***\n\n");
        mostrarMotos(motos,tam,tipos,tamT,colores,tamC,clientes,tamCl);
        printf("Ingrese id para proceder con la eliminacion: ");
        scanf("%d",&legajo);

        indice = buscarMoto(motos,tam,legajo);

        if(indice == -1)
        {
            printf("No hay ninguna moto registrada con ese id.\n\n");
        }
        else
        {
            mostrarMoto(motos[indice],tipos,tamT,colores,tamC,clientes,tamCl);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma == 's')
            {
                motos[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }

    return error;
}

int buscarMoto(eMoto motos[],int tam,int id)
{
    int indice = -1;

    for(int i=0;i<tam;i++)
    {
        if(motos[i].id == id &&  motos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarMoto (eMoto motos[],int tam,eTipo tipos[],int tamT,eColor colores[],int tamC,eCliente clientes[],int tamCl) // Devuelve 0 baja exitosa , 1 hubo un problema ,  2 se cancelo.
{
    int error = 1;
    int indice;
    int legajo;

    if(motos != NULL && tam > 0 && negarBandera(motos,tam))
    {
        //system("cls");
        printf("*** Modificar Moto ***\n\n");
        mostrarMotos(motos,tam,tipos,tamT,colores,tamC,clientes,tamCl);
        printf("Ingrese el id para proceder con la modificacion: ");
        scanf("%d",&legajo);

        indice = buscarMoto(motos,tam,legajo);

        if(indice == -1)
        {
            printf("No hay ninguna moto con ese id.\n\n");
        }
        else
        {
            mostrarMoto(motos[indice],tipos,tamT,colores,tamC,clientes,tamCl);
            error = subMenuModificar(motos,colores,tamC,indice,error);
        }
    }

    return error;
}

int subMenuModificar (eMoto motos[],eColor colores[],int tamC,int indice,int error)
{
    eMoto nuevaMoto;

    int opcion;
    char confirma;
    int idColor;

    printf("\n **** Que quiere modificar ? **** \n");
    printf("\n1 - Color ");
    printf("\n2 - Cilindrada ");

    printf("\n\nIngrese el numero para proceder con la modificacion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    while(opcion<1 || opcion >2 || isalpha(opcion)!=0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }

    switch(opcion)
    {
        case 1:
            printf("\n Escriba el ID del color al cual quiere modificar su moto: \n");
            mostrarColores(colores,tamC);
            printf("Ingrese el ID:");
            scanf("%d",&idColor);

            while(validarIdColores(colores,tamC,idColor)== 0)
            {
                printf("ERROR! Reingrese ID del color:");
                scanf("%d",&idColor);
            }
            break;

        case 2:
            printf("\nIngrese una nueva cilindrada: \n");
            printf("- 50 \n");
            printf("- 125 \n");
            printf("- 500 \n");
            printf("- 600 \n");
            printf("- 750 \n");
            fflush(stdin);
            printf("\n");
            scanf("%d",&nuevaMoto.cilindrada);
            while(nuevaMoto.cilindrada != 50 && nuevaMoto.cilindrada !=125 && nuevaMoto.cilindrada !=500 && nuevaMoto.cilindrada != 600 && nuevaMoto.cilindrada !=750)
            {
                system("cls");
                printf("\nERROR! Vuelva a ingresar una nueva cilindrada valida de la siguiente lista: \n");
                printf("- 50 \n");
                printf("- 125 \n");
                printf("- 500 \n");
                printf("- 600 \n");
                printf("- 750 \n");
                fflush(stdin);
                printf("\n");
                scanf("%d",&nuevaMoto.cilindrada);
            }
            break;
    }

    printf("\nConfirma?( si (s) / no (n) ): ");
    fflush(stdin);
    scanf("%c",&confirma);

    if(confirma == 's')
    {
        switch(opcion)
        {
            case 1:
                motos[indice].idColor = idColor;
                break;
            case 2:
                motos[indice].cilindrada = nuevaMoto.cilindrada;
                break;
        }
        error = 0;
    }
    else
    {
        error = 2;
    }

    return error;
}

int cargarMarcaMotos(eMoto motos[],int tam,int id,char descripcionM[])
{
    int error=-1;

    if(motos != NULL && tam > 0 && id > 0 && descripcionM != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(motos[i].id == id)
            {
                strcpy(descripcionM,motos[i].marca);
                error=0;
            }
        }
   }
    return error;
}

int negarBandera(eMoto motos[],int tam)
{
    int flag=0;

    for(int i=5; i<tam; i++)
    {
        if(motos[i].isEmpty == 0)
        {
            flag = 1;
        }
    }

    return flag;
}
