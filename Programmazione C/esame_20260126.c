#include<stdio.h>
#include<stdlib.h>

//definiamo la struct

typedef struct{
    int idx;
    int Q1;
    int Q2;
    int Qd;
} Codice;

//in questo eserczio si usano gli array



 //funzioni Prototipo

    //Quesito 1

    int leggi_codebook(const char *nomefile, Codice **cb){
        FILE *f = fopen(nomefile,"r");
        if (!f) return -1;


        int cap = 4, n = 0;
        *cb = malloc(cap*sizeof(Codice));

        int q1,q2;
        while (fscaf(f, "%d %d", &q1, &q2) == 2){
            if (n == cap){
                cap *= 2;
                *cb = realloc(*cb, cap*sizeof(Codice));
            }
            (*cb)[n].idx = n;
            (*cb)[n].Q1 = q1;
            (*cb)[n].Q2 = q2;
            (*cb)[n].Qd = abs(q2 - q1);
            n++;
        }
        fclose(f);
        return n;

    }


    //Quesito 2

    int verifica_unicita(Codice *cb, int n){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a[3] = {cb[i].Q1, cb[i].Q2, cb[i].Qd};
                int b[3] = {cb[j].Q1, cb[j].Q2, cb[j].Qd};
                for(int x=0;x<3;x++)
                    for(int y=0;y<3;y++)
                        if (a[x] == b[y])
                            return 0; // errore
                    }  
        }
        return 1;
    }   

    

    //quesito 3

    int arrotonda(double x){
        if(x>0 )
            return (int)(x+0.5);
        else
            return (int)(x-0.5);
    }

    void calcola_quanti(double t0, double t1, double t2,int *Q1,int *Q2,int *Qd,double Tq){
       double T1=t1-t0;
       double T2=t2-t0;
       double Td=t2-t1;

       *Q1=arrotonda(T1/Tq);
       *Q2=arrotonda(T2/Tq);
       *Qd=arrotonda(Td/Tq);
    }


    //quesito 4

    int trova_codice(Codice *cb, int n, int Q1, int Q2, int Qd){
        for(int i=0;i<n;i++){
            if (cb[i].Q1 == Q1 && cb[i].Q2 == Q2 && cb[i].Qd == Qd)
                return cb[i].idx;
        }
        return -1;
    }


    //quesito 5

    int min3(   int a, int b, int c){
        int m=a<b ? a:b;
        return m<c ? m:c;
    }

    int cmp(const void *a, const void *b){
        Codice *x = (Codice *)a;
        Codice *y = (Codice *)b;
        int mx=min3(x->Q1, x->Q2, x->Qd);
        int my=min3(y->Q1, y->Q2, y->Qd);
        return my - mx; //Ordine decrescente
    }

    //Quesito 6
    void processa_sequenza(const char *fileSeq, Codice *cb, int n, int Tq){
        FILE *f = fopen(fileSeq,"r");
        if (!f) return;

        double t0,t1,t2;

        while (fscanf(f, "%lf %lf %lf", &t0, &t1, &t2) == 3){
            int Q1,Q2,Qd;
            calcola_quanti(t0,t1,t2,Tq,&Q1,&Q2,Qd);
            int idx = trova_codice(cb, n, Q1, Q2, Qd);  
            printf("%d\n", idx);
        }
        fclose(f);
    }






 //Quesito 7: funzioni main


int main(void){

    Codice *codebook = NULL;

    int n = leggi_codebook("codebook.txt", &codebook);
    if (n < 0){
        printf("Errore di apertura del codebook\n");
        return 1;
    }

    if (!verifica_unicita(codebook, n)){
        printf("Codebook non valido: codici non unici\n");
        free(codebook);
        return 1;
    }

    qsort(codebook,n,sizeof(Codice), cmp);

    double Tq=40.0;
    processa_sequenza("sequenza.txt", codebook, n, Tq);

    free(codebook);

    return 0;
}