#include<stdio.h>
//ricordare il minore con alt sinistro + 6+0 e il alt 6+2 per il maggiore tastiera gamer

typedef struct Persona{
    char nome[20];
    int eta;
}Persona;





int main (){

    struct Persona Persona;

    printf("Inserisci il nome della persona:\n");
    scanf("%s", Persona.nome);

    printf("Inserisci il eta della persona: \n");
    scanf("%d", &Persona.eta);

    printf("I dati della persona sono:\n");
    
    printf("Il nmome della persona e' %s\n", Persona.nome);
    printf("l'eta della persona e' %d\n", Persona.eta);

    return 0;

}