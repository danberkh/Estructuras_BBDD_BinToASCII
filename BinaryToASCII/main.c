#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void mostrar(FILE *);
char convertir(const char[]);
int error(const char[]);
void pausa(void);

int main() {
    FILE *archivo;
    char nom1[80] = "textoBinario.txt", cad[81]; // nombre físico del archivo
    system("cls");
    if ((archivo = fopen(nom1, "r")) == NULL)
        exit(error(nom1)); // crea el archivo para escritura y lectura;
    printf("\nEl archivo %s se ha abierto satisfactoriamente", nom1);
    printf("\nPresione una tecla para visualizar el contenido del archivo: %s\n\n", nom1);
    pausa();
    system("cls");
    rewind(archivo);
    printf("\nEl contenido del archivo %s es:\n\n", nom1);
    mostrar(archivo);
    pausa();
    rewind(archivo);
    printf("\nMOSTRAMOS EL MENSAJE\n\n");
    while (fgets(cad, 81, archivo) != NULL) {
        int len = strlen(cad);
        for (int i = 0; i < len - 1; i += 8) {
            char binary[9];
            strncpy(binary, &cad[i], 8);
            binary[8] = '\0';
            printf("%c", convertir(binary));
        }
        printf("\n");
    }
    printf("\n\n");
    pausa();
    fclose(archivo);

    return (0);
}

void mostrar(FILE *x) {
    char caracter;
    while ((caracter = fgetc(x)) != EOF) {
        printf("%c", caracter);
    }
}

int error(const char *x)
{
    fprintf(stderr, "No se pudo abrir el archivo %s", x);
    return (1);
}

char convertir(const char x[]) {
    int n = 0;
    for (int i = 0; i < 8; i++) {
        n = n + (x[i] - '0') * pow(2, 7 - i);
    }
    unsigned char letra = n; // Unsigned para evitar que se le asigne un valor fuera de rango en la conversion
    return letra;
}

void pausa() {
    printf("\nPresiona Enter para continuar...\n");
    fflush(stdin);
    while (getchar() != '\n');
}

