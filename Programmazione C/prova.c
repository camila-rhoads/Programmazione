#include<stdio.h>
#include<stdlib.h

#define MAX 19+1

//Funzioni prototipo 



void funzioneListaPari(FILE *fInput){

    int numero;
    printf("Numeri pari presenti nel file di input:\n");
    while(fscanf(fInput, "%d", &numero) == 1){
        if(numero % 2 == 0){
            printf("%d\n", numero);
        }
    }
}



int main(){


//1-Inserire il nome del file di input

char nomeFileInput[MAX];

printf("Inserisci il nome del file di input:");
scanf("%s",nomeFileInput);

//2-Apertura del file di input in modalita' lettura
FILE *fInput = fopen(nomeFileInput, "r");
if(fInput == NULL){
    printf("Errore nell'apertura del file di input\n");
    return 1;
}

//1a-Funzione lista contententi i numeri pari presenti nel file di input

funzioneListaPari(fInput);

//Chiusura del file di input
fclose(fInput);




    return 0;
}