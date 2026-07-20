#include<stdio.h>



int main(){


    int v[5];



    printf("Inserisci 5 numeri interi:\n");
    for(int i=0;i<5;i++){
        scanf("%d", &v[i]);
    }


    printf("Mostrami i numeri rovesciato:\n");
    for(int i=4; i>=0; i--){
        printf("%d ", v[i]);
    }

    return 0;
}