#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mascotas.h"
#include "Gets.h"
#define OCUPADO 1
#define LIBRE 0

void HardcodeoMascotas(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;

    int id[20] = {100,101,102,103,104,105,106,107,108,109,110};
    char nombre[20][30] = {"GatoUNO","GatoDOS","GatoTRES","GatoCUATRO","PerroUNO","PerroDOS","PerroTRES","PerroCUATRO","GatoCINCO","PerroCINCO","IguanaUNO"};
    char tipo[20][30] = {"Gato","Gato","Gato","Gato","Perro","Perro","Perro","Perro","Gato","Perro","Raro"};
    char raza[20][30] = {"Persa","Siames","Bengala","Sphynx","Labrador","Pitbull","Bulldog","Caniche","Persa","Bulldog","Iguana"};
    char paisRaza[20][30] = {"Persa","PaisEJ","China","Egipto","Alemania","Usa","Frances","Nose","Persa","Aleman","Honduras"};
    int edad[20] = {5,5,6,7,9,3,7,8,3,3,3};
    float peso[20] = {5.000,6.100,7.600,8.200,9.500,4.120,9.300,10.100,9.300,6.200,5.700};
    char sexo[20][10] = {"Hembra","Hembra","Macho","Macho","Macho","Macho","Macho","Hembra","Macho","Macho","Macho"};
    int idCliente[20] = {100,100,104,104,101,103,104,102,102,102,103};
    int isEmpty[20] = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};


    for(i = 0; i<sizeMascotas; i++)
    {
        listadoMascotas[i].id = id[i];
        strcpy(listadoMascotas[i].nombre, nombre[i]);
        strcpy(listadoMascotas[i].tipo, tipo[i]);
        strcpy(listadoMascotas[i].raza.nombreRaza, raza[i]);
        strcpy(listadoMascotas[i].raza.pais, paisRaza[i]);
        listadoMascotas[i].edad = edad[i];
        listadoMascotas[i].peso = peso[i];
        strcpy(listadoMascotas[i].sexo, sexo[i]);
        listadoMascotas[i].idCliente = idCliente[i];
        listadoMascotas[i].isEmpty = isEmpty[i];
    }
}

void InicializarMascotas(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;

    for(i=0; i<sizeMascotas; i++)
    {
        listadoMascotas[i].isEmpty = LIBRE;
    }
}

int BuscarMascotaLibre(sMascotas listadoMascota[], int sizeMascotas)
{
    int i;
    int indice;

    indice = -1;

    for(i=0; i<sizeMascotas; i++)
    {
        if(listadoMascota[i].isEmpty == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void MostrarUnaMascota(sMascotas unaMascota)
{
    printf("%15d %15s %18s %18s %10s %10d %10.3f %10s \n",   unaMascota.id,
                                                        unaMascota.nombre,
                                                        unaMascota.tipo,
                                                        unaMascota.raza.nombreRaza, unaMascota.raza.pais,
                                                        unaMascota.edad,
                                                        unaMascota.peso,
                                                        unaMascota.sexo);
}

void MostrarListadoSoloMascotas(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    printf("%15s %15s %18s %18s %10s %10s %10s \n","ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO");
    for(i=0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            MostrarUnaMascota(listadoMascotas[i]);
        }
    }
}

int AltaMascotas(sMascotas listadoMascotas[], int sizeMascotas, int idMascota)
{
    int indiceEncontrado;

    indiceEncontrado = BuscarMascotaLibre(listadoMascotas, sizeMascotas);

    if(indiceEncontrado != -1)
    {
        listadoMascotas[indiceEncontrado] = CargarMascotas(listadoMascotas[indiceEncontrado]);
        listadoMascotas[indiceEncontrado].id = idMascota;
        return 1;
    }
    else
    {
        return -1;
    }
}

sMascotas CargarMascotas(sMascotas auxMascotas)
{
    auxMascotas.idCliente = GetInt("Ingrese ID del cliente para asignarle una mascota: ");

    GetString("Ingrese nombre de la mascota: ",auxMascotas.nombre);

    do
    {
        printf("TIPOS : GATO - PERRO - RARO \n");
        GetString("Ingrese tipo de la mascota: ",auxMascotas.tipo);

    }while(strcmp(auxMascotas.tipo, "Gato") != 0 && strcmp(auxMascotas.tipo, "Perro") != 0 && strcmp(auxMascotas.tipo, "Raro") != 0 );

    GetString("Ingrese RAZA de la mascota: ",auxMascotas.raza.nombreRaza);

    GetString("Ingrese PAIS de la RAZA de la mascota: ",auxMascotas.raza.pais);

    auxMascotas.edad = GetInt("Ingrese edad de la mascota: ");

    auxMascotas.peso = GetFloat("Ingrese peso de la mascota: ");

    do
    {
        printf("SEXO: MACHO - HEMBRA \n");
        GetString("Ingrese sexo de la mascota: ",auxMascotas.sexo);

    }while(strcmp(auxMascotas.sexo, "Hembra") != 0 && strcmp(auxMascotas.sexo, "Macho") != 0);

    auxMascotas.isEmpty = OCUPADO;

    return auxMascotas;
}

int BuscarIdMascota(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    int idIngresado;

    MostrarListadoSoloMascotas(listadoMascotas, sizeMascotas);
    idIngresado = GetInt("Ingrese ID de la MASCOTA: ");

    for(i = 0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].id == idIngresado && listadoMascotas[i].isEmpty == OCUPADO)
        {
            return i;
        }
    }
    return -1;
}

int BajaMascota(sMascotas listadoMascotas[], int sizeMascotas)
{
    int index;
    char respuesta[4];

    index = BuscarIdMascota(listadoMascotas, sizeMascotas);

    if(index != -1)
    {
        do
        {
            system("cls");
            printf("%15s %15s %18s %18s %10s %10s %10s %10s \n","ID","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");
            MostrarUnaMascota(listadoMascotas[index]);
            GetString("Desea dar de baja a esta mascota (SI - NO): ",respuesta);
            strlwr(respuesta);

        }while(strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);

        if(strcmp(respuesta, "si") == 0)
        {
            listadoMascotas[index].isEmpty = LIBRE;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return index;
}

int ModificarMascota(sMascotas listadoMascotas[], int sizeMascotas)
{
    int index;
    int opcion;

    index = BuscarIdMascota(listadoMascotas, sizeMascotas);

    if(index != -1)
    {
        do
        {
            printf("%15s %15s %18s %18s %10s %10s %10s %10s \n","ID","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");
            MostrarUnaMascota(listadoMascotas[index]);
            printf("Que desea modifcar: \n");
            printf("1-NOMBRE. \n");
            printf("2-TIPO. \n");
            printf("3-NOMBRE de la RAZA. \n");
            printf("4-Pais de la RAZA. \n");
            printf("5-EDAD. \n");
            printf("6-PESO. \n");
            printf("7-SEXO. \n");
            printf("8-SALIR. \n");
            opcion = GetInt("Ingrese opcion: ");

            switch(opcion)
            {
                case 1:
                    GetString("Ingrese nuevo NOMBRE: ", listadoMascotas[index].nombre);
                break;

                case 2:
                    do
                    {
                        printf("TIPO: PERRO - GATO - RARO \n");
                        GetString("Ingrese nuevo TIPO: ", listadoMascotas[index].tipo);

                    }while(strcmp(listadoMascotas[index].tipo, "Perro") != 0 && strcmp(listadoMascotas[index].tipo, "Gato") != 0 && strcmp(listadoMascotas[index].tipo, "Raro") != 0);

                break;

                case 3:
                    GetString("Ingrese nuevo NOMBRE de RAZA: ", listadoMascotas[index].raza.nombreRaza);

                break;

                case 4:
                    GetString("Ingrese nuevo PAIS de la RAZA: ", listadoMascotas[index].raza.pais);
                break;

                case 5:
                    listadoMascotas[index].edad = GetInt("Ingrese nueva EDAD: ");
                break;

                case 6:
                    listadoMascotas[index].peso = GetFloat("Ingrese nuevo PESO: ");
                break;

                case 7:
                    do
                    {
                        printf("SEXO: MACHO - HEMBRA \n");
                        GetString("Ingrese nuevo SEXO: ", listadoMascotas[index].sexo);

                    }while(strcmp(listadoMascotas[index].sexo, "Macho") != 0 && strcmp(listadoMascotas[index].sexo, "Hembra") != 0);

                break;

                case 8:
                break;
            }
        system("cls");
        }while(opcion != 8);

    }

    return index;
}

void OrdenarMascotasPorTipo(sMascotas listadoMascotas[], int sizeMascotas)
{
    sMascotas auxMascotas;

    int i;
    int j;
    for(i = 1; i<sizeMascotas-1; i++)
    {
        for(j = i+1; j<sizeMascotas; j++)
        {
            if(stricmp(listadoMascotas[i].tipo, listadoMascotas[j].tipo) > 0)
            {
                auxMascotas = listadoMascotas[i];
                listadoMascotas[i] = listadoMascotas[j];
                listadoMascotas[j] = auxMascotas;
            }
        }
    }
}

void MostrarMascotasPorTipo(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    char respuesta[10];

    do
    {
        printf("Que desea mostrar. PERRO - GATO - RARO \n");
        GetString("Ingrese tipo de mascota a mostrar: ", respuesta);

    }while(strcmp(respuesta, "Perro") != 0 && strcmp(respuesta, "Gato") != 0 && strcmp(respuesta, "Raro") != 0);

    printf("%15s %15s %18s %18s %10s %10s %10s %10s \n","ID","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO");
    for(i = 0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO && strcmp(listadoMascotas[i].tipo, respuesta) == 0)
        {
            MostrarUnaMascota(listadoMascotas[i]);
        }
    }
}

int SumaEdadMascotas(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    int acumuladorEdad = 0;

    for(i = 0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            acumuladorEdad += listadoMascotas[i].edad;
        }
    }
    return acumuladorEdad;
}

int ContadorMascotas(sMascotas listadoMascotas[], int sizeMascotas)
{
    int i;
    int contadorMascotas = 0;

    for(i = 0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].isEmpty == OCUPADO)
        {
            contadorMascotas++;
        }
    }
    return contadorMascotas;
}

void PromedioEdadMascota(sMascotas listadoMascotas[], int sizeMascotas)
{
    int edadSumada;
    int cantidadMascota;
    float promedio;

    edadSumada = SumaEdadMascotas(listadoMascotas, sizeMascotas);
    cantidadMascota = ContadorMascotas(listadoMascotas, sizeMascotas);

    promedio = (float)edadSumada/cantidadMascota;

    printf("PROMEDIO DE EDAD ENTRE MASCOTAS: %.3f \n",promedio);
}

void PromedioEdadMascotaPorTipo(sMascotas listadoMascota[], int sizeMascotas)
{
    char respuesta[30];
    int edadMascotas;
    int cantidadMascotas;
    float promedio;

    do
    {
        printf("TIPOS: PERRO - GATO - RARO \n");
        printf("Ingrese TIPO de MASCOTA para calcular el PROMEDIO. \n");
        GetString("Ingrese TIPO: ", respuesta);

    }while(strcmp(respuesta, "Gato") != 0 && strcmp(respuesta, "Perro") != 0 && strcmp(respuesta, "Raro") != 0);

    if(strcmp(respuesta, "Gato") == 0)
    {
        edadMascotas = SumaEdadMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
        cantidadMascotas = ContadorMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
    }
    else if(strcmp(respuesta, "Perro") == 0)
    {
        edadMascotas = SumaEdadMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
        cantidadMascotas = ContadorMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
    }
    else
    {
        edadMascotas = SumaEdadMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
        cantidadMascotas = ContadorMascotasPorTipo(listadoMascota, sizeMascotas, respuesta);
    }
    promedio = (float)edadMascotas/cantidadMascotas;

    printf("Promedio de edad de mascota del TIPO %s es: %.3f \n",respuesta, promedio);
}

int SumaEdadMascotasPorTipo(sMascotas listadoMascotas[], int sizeMascotas, char tipo[])
{
    int i;
    int sumaEdad = 0;

    for(i = 0; i<sizeMascotas; i++)
    {
        if(strcmp(tipo, listadoMascotas[i].tipo) == 0 && listadoMascotas[i].isEmpty == OCUPADO)
        {
            sumaEdad += listadoMascotas[i].edad;
        }
    }
    return sumaEdad;
}

int ContadorMascotasPorTipo(sMascotas listadoMascotas[], int sizeMascotas, char tipo[])
{
    int i;
    int cantidadMascotas = 0;

    for(i = 0; i<sizeMascotas; i++)
    {
        if(strcmp(tipo, listadoMascotas[i].tipo) == 0 && listadoMascotas[i].isEmpty == OCUPADO)
        {
            cantidadMascotas++;
        }
    }
    return cantidadMascotas;
}



