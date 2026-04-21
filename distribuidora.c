#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int productoID;
    int cantidad;
    char *TipoProducto;
    float precioUnitario;
} typedef Producto;

struct Cliente {
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *Productos;
} typedef Cliente;

int main() {
    //Producto *p[50];
    Producto p;
    char *clientes[50];
    int cantClientes = 2;

    for (int i = 0; i < cantClientes; i++) {
        clientes[i] = (char *) malloc(100 * sizeof(char));
        //p[i] = (Producto *) malloc(100 * sizeof(Producto));
    }

    for (int i = 0; i < cantClientes; i++) {
        printf("Ingresar los clientes:\n");
        gets(clientes[i]);

        p.productoID = 1 + i;
        p.cantidad = 1 + rand() % 10;
        p.precioUnitario = 10 + rand() % 90; 
        p.TipoProducto = TiposProductos[rand() % 5];
    }

    for (int i = 0; i < cantClientes; i++) {
        printf("Id del producto: %d | Cantidad: %d | Precio unitario: %d | Tipo: %s\n", p.productoID, p.cantidad, p.precioUnitario, p.TipoProducto);
    }

    return 0;
}

