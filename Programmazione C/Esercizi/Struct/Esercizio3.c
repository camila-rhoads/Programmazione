//Definizione di una struttura "punto" e calcolare la distanza tra questi due punti

#include<stdio.h>
#include<math.h> // la radice è 




typedef struct p1{
    
    int x;
    int y;

}p1;

typedef struct p2{
    
    int x;
    int y;

}p2;


int main(){

    struct p1 punto1;
    struct p2 punto2;


    printf("Inserisci il primo valore del punto X:\n");
    scanf("%d", &punto1.x);

    printf("Inserisci il valore del secondo numero Y:\n");
    scanf("%d",&punto1.y);

     printf("Inserisci il primo valore del punto X:\n");
    scanf("%d", &punto2.x);

    printf("Inserisci il valore del secondo numero Y:\n");
    scanf("%d",&punto2.y);


    //Calcolare la distanza del punto x e y

    float dist;


    dist = sqrt(pow(punto2.x - punto1.x, 2) + pow(punto2.y - punto1.y, 2));

    printf("La distanza del punto e': %f\n", dist);

    return 0;
}

