#include<stdio.h>

int main() {
    int numero, somma = 0;

    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {
        somma += i;
    }

    printf("La somma dei numeri da 1 a %d e': %d\n", numero, somma);

    return 0;
}