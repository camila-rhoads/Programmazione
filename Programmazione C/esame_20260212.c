#include<stdio.h>
#include<stdlib.h>


//strutta dati

typedef struct {

    int idPaziente;
    int timpstamp; //0<=timpstamp<=1e9
    float valore;
    char tipo;
}misure;


//costruzione nodo
typedef struct Nodo{
    misure m;
    struct Nodo*next;
} Nodo;


//funzione protopipo

int leggi_misure(const char *nomefile, misure **misure){
    FILE *f = fopen(nomefile,"r");
    if (!f) return -1;

    int cap = 4, n = 0;
    *misure = malloc(cap*sizeof(misure));

    int idPaziente, timpstamp;
    float valore;
    char tipo;

    while (fscanf(f, "%d %d %f %c", &idPaziente, &timpstamp, &valore, &tipo) == 4){
        if (n == cap){
            cap *= 2;
            *misure = realloc(*misure, cap*sizeof(misure));
        }
        (*misure)[n].idPaziente = idPaziente;
        (*misure)[n].timpstamp = timpstamp;
        (*misure)[n].valore = valore;
        (*misure)[n].tipo = tipo;
        n++;
    }
    fclose(f);
    return n;

}



int stampa_misure(misure *misure, int n){
    for(int i=0;i<n;i++){
        printf("%d %d %.2f %c\n", misure[i].idPaziente, misure[i].timpstamp, misure[i].valore, misure[i].tipo);
    }
    return n;
}


//funzione principale Main


int main(){


    misure *misure;

    int n = leggi_misure("misure.txt", &misure);
    if (n < 0){
        printf("Errore di apertura del file misure.txt\n");
        return 1;
    }


    int n1 = stampa_misure(misure, n);
    printf("Numero di misure stampate: %d\n", n1);


    return 0;

}
