#include "Clientes_Mascotas.h"
#include "Gets.h"
#include <stdio.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0

void MostrarMascotaConCliente(sMascotas unaMascota, sClientes unCliente)
{
    printf("%15s %15d %15s %18s %18s %10s %10d %10.3f %10s \n",  unCliente.nombre,
                                                            unaMascota.id,
                                                            unaMascota.nombre,
                                                            unaMascota.tipo,
                                                            unaMascota.raza.nombreRaza, unaMascota.raza.pais,
                                                            unaMascota.edad,
                                                            unaMascota.peso,
                                                            unaMascota.sexo);
}


void MostrarListadoMascotas(sMascotas listadoMascotas[], sClientes listaClientes[],int sizeMascotas, int sizeClientes)
{
    int i;
    int j;

    for(i=0; i<sizeMascotas; i++)
    {
        for(j=0; j<sizeClientes; j++)
        {
            if(listaClientes[j].isEmpty == OCUPADO && listadoMascotas[i].isEmpty == OCUPADO &&listadoMascotas[i].idCliente == listaClientes[j].id)
            {
                MostrarMascotaConCliente(listadoMascotas[i],listaClientes[j]);
            }
        }
    }
}

void MostrarClientesConMascotas(sClientes listadoClientes[], int sizeClientes, sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    int j;

    for(i=0; i<sizeClientes; i++)
    {
        if(listadoClientes[i].isEmpty == OCUPADO)
        {
            printf("----------------------------------------------------------------------------------------\n");
            printf("%40s %5s\n\n","Cliente: ",listadoClientes[i].nombre);
            printf("%15s %18s %18s %10s %10s %10s %10s\n\n","NOMBRE MASCOTA","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");

        }

        for(j=0; j<sizeMascotas; j++)
        {
            if(listadoClientes[i].id == listadoMascotas[j].idCliente && listadoMascotas[j].isEmpty == OCUPADO)
            {

                printf("%15s %18s %18s %10s %10d %10.3f %10s \n",        listadoMascotas[j].nombre,
                                                                    listadoMascotas[j].tipo,
                                                                    listadoMascotas[j].raza.nombreRaza, listadoMascotas[j].raza.pais,
                                                                    listadoMascotas[j].edad,
                                                                    listadoMascotas[j].peso,
                                                                    listadoMascotas[j].sexo);
            }
        }
    }
}

int BorradoClienteCascada(sClientes listadoCliente[], int sizeClientes, sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    int indice;
    char respuesta[4];

    indice = BuscarIdCliente(listadoCliente, sizeClientes);

    if(indice != -1)
    {
        do
        {
            printf("%15s %15s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");
            MostrarCliente(listadoCliente[indice]);
            printf("Esta seguro de dar de baja a este cliente, se borrara tambien las mascotas. \n\n");
            printf("SI - NO \n");
            GetString("Ingrese opcion: ",respuesta);

        }while(strcmp(respuesta, "Si") != 0 && strcmp(respuesta, "No") != 0);

        if(strcmp(respuesta, "Si") == 0)
        {
            for(i = 0; i<sizeMascotas; i++)
            {
                if(listadoCliente[indice].id == listadoMascotas[i].idCliente)
                {
                    listadoMascotas[i].isEmpty = LIBRE;
                }
            }
            listadoCliente[indice].isEmpty = LIBRE;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return -1;
}


void MostrarClientesConMasDeUnaMascota(sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas)
{
    int i;
    int j;

    sAux Clientes_Mascotas[sizeClientes];
    InicializarStructAux(Clientes_Mascotas, listadoClientes, sizeClientes);
    ContadorMascotas_Clientes(Clientes_Mascotas, listadoMascotas, sizeMascotas, sizeClientes);

    printf("%15s %15s %15s \n","ID CLIENTE","NOMBRE CLIENTE","CANT. MASCOTA");

    for(i = 0; i<sizeClientes; i++)
    {
        for(j = 0; j<sizeClientes; j++)
        {
            if(listadoClientes[j].isEmpty == OCUPADO && listadoClientes[j].id == Clientes_Mascotas[i].idCliente && Clientes_Mascotas[i].cantidadMascota > 1)
            {
                printf("%15d %15s %15d  \n",listadoClientes[i].id, listadoClientes[i].nombre, Clientes_Mascotas[j].cantidadMascota);
            }
        }
    }
}

void InicializarStructAux(sAux listadoAux[],sClientes listadoClientes[], int sizeClientes)
{
    int i;

    for(i = 0; i<sizeClientes; i++)
    {
        listadoAux[i].idCliente = listadoClientes[i].id;
        listadoAux[i].cantidadMascota = 0;
    }
}

void ContadorMascotas_Clientes(sAux Clientes_Mascota[], sMascotas listadoMascotas[], int sizeMascotas, int sizeClientes)
{
    int i;
    int j;

    for(i = 0; i<sizeClientes; i++)
    {
        for(j = 0; j<sizeMascotas; j++)
        {
            if(listadoMascotas[j].isEmpty == OCUPADO && listadoMascotas[j].idCliente == Clientes_Mascota[i].idCliente)
            {
                Clientes_Mascota[i].cantidadMascota++;
            }
        }
    }
}

void MostrarMascotasMasTres(sMascotas listadoMascotas[], sClientes listaClientes[],int sizeMascotas, int sizeClientes)
{
    int i;
    int j;

    for(i=0; i<sizeMascotas; i++)
    {
        for(j=0; j<sizeClientes; j++)
        {
            if(listaClientes[j].isEmpty == OCUPADO && listadoMascotas[i].isEmpty == OCUPADO &&listadoMascotas[i].idCliente == listaClientes[j].id && listadoMascotas[i].edad > 3)
            {
                MostrarMascotaConCliente(listadoMascotas[i],listaClientes[j]);
            }
        }
    }
}

void OrdenarClientesPorCantidad(sAux Clientes_Mascotas[], sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas)
{
    int i;
    int j;
    sAux contadorAuxiliar;

    InicializarStructAux(Clientes_Mascotas, listadoClientes, sizeClientes);
    ContadorMascotas_Clientes(Clientes_Mascotas, listadoMascotas, sizeMascotas, sizeClientes);

    for(i = 0; i<sizeClientes-1; i++)
    {
        for(j = i+1; j<sizeClientes; j++)
        {
            if(Clientes_Mascotas[i].cantidadMascota < Clientes_Mascotas[j].cantidadMascota)
            {
                contadorAuxiliar = Clientes_Mascotas[i];
                Clientes_Mascotas[i] = Clientes_Mascotas[j];
                Clientes_Mascotas[j] = contadorAuxiliar;
            }
        }
    }
}

void MostrarClientesConMascotaOrdenado(sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas)
{
    int i;
    int j;
    int k;

    sAux Clientes_Mascotas[sizeClientes];

    OrdenarClientesPorCantidad(Clientes_Mascotas, listadoClientes, listadoMascotas, sizeClientes, sizeMascotas);

    for(i = 0; i<sizeClientes; i++)
    {
        for(j = 0; j<sizeClientes; j++)
        {
            if(Clientes_Mascotas[i].idCliente == listadoClientes[j].id && listadoClientes[j].isEmpty == OCUPADO)
            {
                printf("-------------------------------------------------------------------------------------------------------------------\n");

                printf("%42s CLIENTE <<<<<<< \n",">>>>>>>");
                printf("%15s %15s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");

                MostrarCliente(listadoClientes[j]);

                printf("\n%42s MASCOTA <<<<<<< \n",">>>>>>>");
                printf("%15s %15s %18s %18s %10s %10s %10s %10s \n\n","ID","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");

                for(k = 0; k<sizeMascotas; k++)
                {
                    if(listadoClientes[j].id == listadoMascotas[k].idCliente && listadoMascotas[k].isEmpty == OCUPADO)
                    {
                        MostrarUnaMascota(listadoMascotas[k]);
                        //printf("%15d %15s %15d \n",listadoClientes[j].id, listadoClientes[j].nombre, Clientes_Mascotas[i].cantidadMascota);
                    }
                }
            }
        }
    }
}

void OrdenarClientesPorCantidadNombre(sAux Clientes_Mascotas[], sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas)
{
    int i;
    int j;
    sAux contadorAuxiliar;

    InicializarStructAux(Clientes_Mascotas, listadoClientes, sizeClientes);
    ContadorMascotas_Clientes(Clientes_Mascotas, listadoMascotas, sizeMascotas, sizeClientes);

    for(i = 0; i<sizeClientes-1; i++)
    {
        for(j = i+1; j<sizeClientes; j++)
        {
            if(Clientes_Mascotas[i].cantidadMascota < Clientes_Mascotas[j].cantidadMascota || Clientes_Mascotas[i].cantidadMascota == Clientes_Mascotas[j].cantidadMascota)
            {

                contadorAuxiliar = Clientes_Mascotas[i];
                Clientes_Mascotas[i] = Clientes_Mascotas[j];
                Clientes_Mascotas[j] = contadorAuxiliar;
            }
            else
            {
                if(strcmp(listadoClientes[i].nombre, listadoMascotas[j].nombre) > 0 && strcmp(listadoClientes[i].nombre, listadoClientes[j].nombre) == 0)
                {
                    contadorAuxiliar = Clientes_Mascotas[i];
                    Clientes_Mascotas[i] = Clientes_Mascotas[j];
                    Clientes_Mascotas[j] = contadorAuxiliar;
                }
            }
        }
    }
}

void MostrarClientesPorCantidadMascotaNombre(sClientes listadoClientes[], sMascotas listadoMascotas[], int sizeClientes, int sizeMascotas)
{
    int i;
    int j;
    int k;

    sAux Clientes_Mascotas[sizeClientes];

    OrdenarClientesPorCantidadNombre(Clientes_Mascotas, listadoClientes, listadoMascotas, sizeClientes, sizeMascotas);

    for(i = 0; i<sizeClientes; i++)
    {
        for(j = 0; j<sizeClientes; j++)
        {
            if(Clientes_Mascotas[i].idCliente == listadoClientes[j].id && listadoClientes[j].isEmpty == OCUPADO)
            {
                printf("-------------------------------------------------------------------------------------------------------------------\n");

                printf("%42s CLIENTE <<<<<<< \n",">>>>>>>");
                printf("%15s %15s %18s %18s %10s %10s %10s \n\n","ID","NOMBRE","APELLIDO","LOCALIDAD","EDAD","TELEFONO","SEXO");

                MostrarCliente(listadoClientes[j]);

                printf("\n%42s MASCOTA <<<<<<< \n",">>>>>>>");
                printf("%15s %15s %18s %18s %10s %10s %10s %10s \n\n","ID","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");

                for(k = 0; k<sizeMascotas; k++)
                {
                    if(listadoClientes[j].id == listadoMascotas[k].idCliente && listadoMascotas[k].isEmpty == OCUPADO)
                    {
                        MostrarUnaMascota(listadoMascotas[k]);
                        //printf("%15d %15s %15d \n",listadoClientes[j].id, listadoClientes[j].nombre, Clientes_Mascotas[i].cantidadMascota);
                    }
                }
            }
        }
    }
}


