#include "Mascotas.h"
#include "Clientes.h"

typedef struct
{
    int idCliente;
    int cantidadMascota;

}sAux;

void MostrarClientesConMascotas(sClientes [], int, sMascotas [], int);

void MostrarListadoMascotas(sMascotas [], sClientes [],int, int );

void MostrarMascotaConCliente(sMascotas, sClientes);

int BorradoClienteCascada(sClientes [], int , sMascotas [], int);

void MostrarClientesConMasDeUnaMascota(sClientes [], sMascotas [], int, int);

void InicializarStructAux(sAux [], sClientes [], int);

void ContadorMascotas_Clientes(sAux [], sMascotas [], int, int);

void MostrarMascotasMasTres(sMascotas [], sClientes [], int, int);

void MostrarClientesConMasDeUnaMascota(sClientes [], sMascotas [], int, int);

void OrdenarClientesPorCantidad(sAux [], sClientes [], sMascotas [], int, int);

void MostrarClientesConMascotaOrdenado(sClientes [], sMascotas[], int, int);

void OrdenarClientesPorCantidadNombre(sAux [], sClientes [], sMascotas [], int, int);

void MostrarClientesPorCantidadMascotaNombre(sClientes [], sMascotas [], int, int);


