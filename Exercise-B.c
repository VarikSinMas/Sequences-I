/*FUNDAMENTOS DE PROGRAMACIÓN AA3 (Antoni Fernández Almécija)*/

#include <stdio.h>

void printaExito(int n, int d1, int d2, int *c) {
    if (d1 <= d2) {
        printf("El numero: %d es igual a %d multiplicado por %d\n", n, d1, d2);
        (*c)++;
    }
}

void printaFracaso(int n) {
    printf("El numero: %d no tiene divisores diferentes de 1 que multiplicados sean igual a el.\n", n);
}

int loEs(int x, int y, int z) {
    if (y == z) {
        return 0;
    }
    else {
        return x == (y * z);
    }
}

void buscadivisor1(int n, int *a, int *b, int *c) {
    *a = 2;
    while (*a <= n/2) {
        buscadivisor2(n, *a, b, c);
        (*a)++;
    }
}

void buscadivisor2(int n, int a, int *b, int *c) {
    *b = 3;
    while (*b <= n/2) {
        if (loEs(n, a, *b)) {
            printaExito(n, a, *b, c);
        }
        (*b)++;
    }
}

int main() {
    int num, d1, d2, c;
    printf("Introduce uno o mas numeros enteros: o 0 para salir.\n");
    scanf("%d", &num);
    while (num != 0) {
        c = 0;
        buscadivisor1(num, &d1, &d2, &c);
        if (c > 0) {
            printf("El numero analizado tiene: %d parejas de divisores.\n", c);
        }
        else {
            printaFracaso(num);
        }
        printf("Introduce un numero entero: o 0 para salir.\n");
        scanf("%d", &num);
    }
    return 0;
}
