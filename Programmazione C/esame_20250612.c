#include<stdio.h>
#include<stdlib.h>

#define MAX 19+1

//Questo programma vengono usate le liste

typedef struct Nodo_intero{
    int numero;
    struct Nodo_intero *next;
}Nodo_intero;

//funzioni prototipo

Nodo_intero*listapari(char* nomeFileInput){
    FILE* fInput = fopen(nomeFileInput, "r");
    if(fInput == NULL){
        printf("Errore nell'apertura del file di input\n");
        return NULL;
    }
    Nodo_intero* head = NULL;
    int numero;
    while(fscanf(fInput, "%d", &numero) == 1){
        if(numero % 2 == 0){
            Nodo_intero* newNode = (Nodo_intero*)malloc(sizeof(Nodo_intero));
            newNode->numero = numero;
            newNode->next = head;
            head = newNode;
        }
    }       
    fclose(fInput);
    return head;
}

Nodo_intero* stampalistapari(Nodo_intero* head){
    printf("Numeri pari presenti nel file di input:\n");
    Nodo_intero* current = head;
    while(current != NULL){
        printf("%d ", current->numero);
        current = current->next;
    }
    printf("\n");
    return head;
}




//funzione principale

int main(){

    char nomeFileInput[MAX];

    printf("Inserisci il nome del file di input:");
    scanf("%s",nomeFileInput);

    //rimandare alla funzione attraverso la lista 
    Nodo_intero*lista_pari=listapari(nomeFileInput);
    stampalistapari(lista_pari);


    return 0;
}

