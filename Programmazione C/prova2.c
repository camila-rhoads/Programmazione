#include<stdio.h>


//Funzione somma 

/*int somma_puntatori(int *a, int *b){
    return *a + *b;
}*/

int main(){

 /*1. Dichiarare e usare un puntatore

Scrivi un programma che:

    dichiari una variabile int, crei un puntatore a quella variabile stampi:
    il valore della variabile
    l’indirizzo della variabile
    il valore tramite dereferenziazione

    Esempio:

    int x = 10;    memoria 101
                        10
    int *p = &x; */

    /*
    int x = 10;
    int *p = &x;

    printf("Valore della variabile: %d\n", x);
    printf("Indirizzo della variabile: %p\n", &x);
    printf("Valore tramite dereferenziazione: %d\n", *p);*/




    /* Modificare una variabile tramite puntatore 

    int x= 20;
    int *p = &x;

    printf("Valore originale di x: %d\n", x);

    *p = 30;

    printf("Valore modificato di x: %d\n", x);*/

/*Somma tramite funzione con puntatori 

    int a = 5, b = 10;
    int *pA = &a;
    int *pB = &b;

     somma_puntatori(*pA, *pB);

    printf("Somma: %d\n", somma_puntatori(*pA, *pB));*/


    /*Swap di due variabili con puntatori

    int x = 15, y = 25;
    int *pX = &x;
    int *pY = &y;
    printf("Valori originali: x = %d, y = %d\n", x, y);

    //swap
    int tmp=0;
     
    tmp = *pX;
    *pX = *pY;  
    *pY = tmp;              

    printf("Valori dopo lo swap: x = %d, y = %d\n", x, y);*/

    /*Scorrere array con puntatori


    int array[] = {1, 2, 3, 4, 5};
    int *pArray = array; // o &array[0]

    printf("Elementi dell'array:\n");
    for(int i = 0; i < 5; i++){
        printf("%d ", *pArray);
        pArray++; // spostiamo il puntatore al prossimo elemento
    }
*/

/*Trovare massimo in un array*/


int array[] = {3, 7, 2, 9, 5};
int *pArray = array; // o &array[0]

int max = *pArray; // inizializziamo max al primo elemento
int i;
for(i=0;i<5;i++){

        printf("%d ", *pArray);

        if (*pArray <= *(pArray + 1)){           
            *pArray = *pArray;    
        }
            else{
                *pArray=(*pArray+1);
            }
        
        
            
        pArray++;

        printf("%d",&pArray);
}





    return 0;
}