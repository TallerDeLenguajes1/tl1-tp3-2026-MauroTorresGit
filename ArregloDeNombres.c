#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas (char *nom[], int cant) {
    //printf("%s", nom);
    //puts(nom);
    for (int i = 0; i < cant; i++) {
        printf("%d- ", i+1);
        printf("%s\n", nom[i]);
    }
}

int buscarNombre(char *nom[], int cant, char buff[10]) {
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
    char buff[10];
    int cant = 5;

    for (int i = 0; i < cant; i++) {
        nombres[i] = (char *) malloc(100 * sizeof(char));
        //buff[i] = (char *) malloc(100 * sizeof(char));
    }
    
    for (int i = 0; i < cant; i++) {
        printf("Ingrese nombres:\n");
        gets(nombres[i]);
    }

    mostrarPersonas(nombres, cant);

    printf("Ingresar nombre a buscar");
    scanf(" %s", &buff);
    puts(buff);
    //gets(buff[0]);
    //buff[0] = "pepe";

    int resultado = buscarNombre(nombres, cant, buff);

    if (resultado == -1) printf("No se encontro");

    //free(nombres);
    //free(buff);

    return 0;
}