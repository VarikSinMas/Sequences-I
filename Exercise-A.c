/*FUNDAMENTOS DE PROGRAMACIÓN AA3 (Antoni Fernández Almécija)*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMEROS 10

void imprimirNumeros(int numeros[], int tamano) {
    printf("Posicion\tValor\n");
    for (int i = 0; i < tamano; i++) {
        printf("%d\t\t%d\n", i, numeros[i]);
    }
}

bool compararNumeros(int numeros1[], int numeros2[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        if (numeros1[i] != numeros2[i]) {
            return false;
        }
    }
    return true;
}

void mostrarDiferencias(int numeros1[], int numeros2[], int tamano) {
    printf("Posicion\tJugador 1\tJugador 2\n");
    for (int i = 0; i < tamano; i++) {
        if (numeros1[i] != numeros2[i]) {2;
            printf("%d\t\t%d\t\t%d\n", i, numeros1[i], numeros2[i]);
        }
    }
}

int main() {
    int numeros1[MAX_NUMEROS];
    int numeros2[MAX_NUMEROS];
    int tamanoNumeros1 = 0;
    int tamanoNumeros2 = 0;

    // Pedir números al primer usuario
    printf("Introduce numeros (maximo %d). Introduce -1 para terminar.\n", MAX_NUMEROS);
    while (tamanoNumeros1 < MAX_NUMEROS) {
        int numero;
        scanf("%d", &numero);
        if (numero == -1) {
            break;
        }
        numeros1[tamanoNumeros1] = numero;
        tamanoNumeros1++;
    }

    // Limpiar pantalla
    system("cls");

    // Pedir números al segundo usuario
    printf("Introduce los numeros que ha introducido el primer usuario.\n");
    while (tamanoNumeros2 < tamanoNumeros1) {
        int numero;
        scanf("%d", &numero);
        numeros2[tamanoNumeros2] = numero;
        tamanoNumeros2++;
    }

    // Comprobar si los números son iguales
    bool iguales = compararNumeros(numeros1, numeros2, tamanoNumeros1);

    // Limpiar pantalla
    system("cls");

    // Mostrar resultados
    printf("Numeros introducidos por el primer jugador:\n");
    imprimirNumeros(numeros1, tamanoNumeros1);
    printf("\nNumeros introducidos por el segundo jugador:\n");
    imprimirNumeros(numeros2, tamanoNumeros2);
    if (iguales) {
        printf("\nLos numeros introducidos son iguales. Los dos jugadores han acertado.\n");
    } else {
        printf("\nLos numeros introducidos son diferentes. Los dos jugadores han fallado.\n");
        mostrarDiferencias(numeros1, numeros2, tamanoNumeros1);
    }

    return 0;
}