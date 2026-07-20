/*Definizione di una struttura "Persona" e stampa dei dati*/

#include<stdio.h>

typedef struct {
    char nome[50];
    char cognome[50];
    int eta;
}persona;

int main(){

    persona p;


    printf("inserisci un nome:\n");
    scanf("%s",p.nome);

    
    printf("inserisci un cognome:\n");
    scanf("%s",p.cognome);

    
    printf("inserisci l'eta':\n");
    scanf("%d", &p.eta);

    printf(" La persona ha i seguenti dati anagrafici:  %s %s %d ", p.nome,p.cognome, p.eta);

    return 0;
}