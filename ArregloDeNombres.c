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

int main () {

    

    char *nombres[5];
    char *buff;
    int cant = 3;

    for (int i = 0; i < cant; i++) {
        nombres[i] = (char *) malloc(100 * sizeof(char));
    }
    //buff = (char *) malloc(100 * sizeof(char));

    for (int i = 0; i < cant; i++) {
        printf("Ingrese nombres:\n");
        gets(nombres[i]);
    }

    
    mostrarPersonas(nombres, cant);

    //free(nombres);
    //free(buff);

    return 0;
}