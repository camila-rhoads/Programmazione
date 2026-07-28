//Definizione di una struttura libro e stampa i dati

#include<stdio.h>

typedef struct libro{

    char titolo[20];
    char autore[20];
    int datapubb;
}libro;

int main(){

    struct libro libro;


    printf("Inserisci il nome di un titolo di un libro: \n");
    scanf("%s",libro.titolo);

    printf("Inserisci l'autore di un libro: \n");
    scanf("%s",libro.autore);

    printf("Inserisci l'anno di pubblicazione di un libro: \n");
    scanf("%d",&libro.datapubb);



    printf("I dati del libro sono: %s %s %d ", libro.titolo, libro.autore, libro.datapubb);


    return 0;
}