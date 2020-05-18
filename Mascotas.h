
typedef struct
{
    char nombreRaza[30];
    char pais[30];

}sRaza;


typedef struct
{
    int id;
    char nombre[30];
    char tipo[30];
    sRaza raza;
    int edad;
    float peso;
    char sexo[10];
    int idCliente;
    int isEmpty;

}sMascotas;

void HardcodeoMascotas(sMascotas [], int);

void InicializarMascotas(sMascotas [], int);

int BuscarMascotaLibre(sMascotas [], int);

int AltaMascotas(sMascotas [], int, int);

sMascotas CargarMascotas(sMascotas);

int BajaMascota(sMascotas [], int);

int ModificarMascota(sMascotas [], int);

void MostrarListadoSoloMascotas(sMascotas [], int);

void MostrarUnaMascota(sMascotas);

void OrdenarMascotasPorTipo(sMascotas [], int );

void MostrarMascotasPorTipo(sMascotas [], int);

int ContadorMascotas(sMascotas [], int);

int SumaEdadMascotas(sMascotas [], int);

void PromedioEdadMascota(sMascotas [], int);

int SumaEdadMascotasPorTipo(sMascotas [], int, char[]);

int ContadorMascotasPorTipo(sMascotas [], int, char[]);

void PromedioEdadMascotaPorTipo(sMascotas [], int);

