#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas (char *nom[], int cant) {
    for (int i = 0; i < cant; i++) printf("%d- %s\n", i+1, nom[i]);
}

void buscarNombre2 (int id, int cant, char *nom[]) {
    int aux = 0;
    for (int i = 0; i < cant; i++) {
        if (id-1 == i) {
            printf("Buscado por id: %d- %s\n", i+1, nom[i]);
            aux = 1;
            break;
        } else {
            if (i+1 == cant && aux == 0) {
                printf("No se encontro el valor buscado");
            }
        }
    }
}

void buscarNombrePorId (int id, int cant, char *nom[]) {
    int i = 0;
    for (i = 0; i < cant; i++) {
        if (id-1 == i) {
            printf("Buscado por id: %d- %s\n", i+1, nom[i]);
            break;
        } 
    }
    if (i == cant) printf("No se encontro el valor buscado");
}

int buscarNombrePorPalabra(char *nom[], int cant, char buff[10]) {
    char *res;
    int i = 0, ret = -1;
    for (i = 0; i < cant; i++) {
        res = strstr(nom[i], buff);
        if (res != NULL) {
            printf("Se encontro. %d- %s", i+1, nom[i]);
            ret = 0;
            break;
        }  
    } 
    return ret;
}

int main () {
    char *nombres[5];
    int cant = 5, id = 5;
    char buff[10];

    for (int i = 0; i < cant; i++) 
        nombres[i] = (char *) malloc(100 * sizeof(char));
    
    for (int i = 0; i < cant; i++) {
        printf("Ingrese nombres:\n");
        gets(nombres[i]);
    }

    mostrarPersonas(nombres, cant);

    int opcion = 0;
    printf("Buscar personas:\n 1- Buscar por Id\n 2- Buscar por nombre");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese un id:\n");
        scanf("%d", &id);

        buscarNombrePorId(id, cant, nombres);
    } else {
        if (opcion == 2) {
            printf("Ingresar nombre a buscar");
            scanf(" %s", &buff);
            puts(buff);

            int resultado = buscarNombrePorPalabra(nombres, cant, buff);
            if (resultado == -1) printf("No se encontro");
        } else {
            printf("Opcion no valida");
        }
    } 

    for (int i = 0; i < cant; i++)
        free(nombres[i]);

    return 0;
}