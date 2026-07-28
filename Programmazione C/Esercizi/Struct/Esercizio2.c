//Calcolo l'eta media di un gruppo di persone

#include<stdio.h>

typedef struct Persona {
    char nome[20];
    int eta;
}Persona;


int main (){

    struct Persona Persona[3];

    int i;

    //voglio un gruppo di 5 persone

    for (i=0; i<3; i++){

        printf("Inserisci il nome:\n");
        scanf("%s", Persona[i].nome);

        printf("Inserisci la eta:\n");
        scanf("%d",&Persona[i].eta);

    }



    for (i=0; i<3; i++){

        printf("nome %i: %s\n", i, Persona[i].nome);
        printf("eta %i: %d\n", i, Persona[i].eta);
    }


    for(i=0;i<3;i++){

        int somma=0;
        int etamedia=0;

        for(i=0;i<3;i++){

            somma=somma+Persona[i].eta;
        }

        printf("La somma delle persona risulta: %d\n", somma);
        etamedia=(etamedia+somma)/i;
        printf("la media delle persona e': %d\n", etamedia);


    }


    return 0;
}