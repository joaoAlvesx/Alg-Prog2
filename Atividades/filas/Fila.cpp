#include <stdio.h>

void enfileirar(int f[],int *s,int *t,int x);
int desenfileirar(int f[],int *s);
void emprimir(int f[]);
int quantidade(int f[], int *s,int *t);

int main(){
    int f[6];
    int s = 0;
    int t = 0;
    enfileirar(f,&s,&t,5);
    enfileirar(f,&s,&t,10);
    enfileirar(f,&s,&t,30);
   
    emprimir(f);

    desenfileirar(f,&s);
 
 
    enfileirar(f,&s,&t,90);
    enfileirar(f,&s,&t,20);
    emprimir(f);

    int quant = quantidade(f,&s,&t);
    printf("\n");
    printf("%d",quant);
}



void enfileirar(int f[],int *s,int *t,int x){
    f[*t] = x;
    *t = *t + 1;
   
    if (*t == 6)
        *t = 0;

}
int desenfileirar(int f[],int *s){
    int x;

    x = f[*s];
  
    *s = (*s + 1) % 5;
    return x;

}

void emprimir(int f[]){

    for (int i = 0; i <= 4; i++){
        printf("[%d]",f[i]);
    }
    printf("\n");

}
int quantidade(int f[], int *s,int *t){

    printf("%d",*s);
    printf("\n");
    printf("%d",*t);
    if ( *s < *t)
        return *t -*s;
    else
        return *s - *t;
printf("\n");
}


