#include <stdio.h>

int elevado(int base, int pot);
int main(){

    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int x;
    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("O valor de %d elevado a %d eh %d\n ", x,n,elevado(x,n));

    return 0;
}


int elevado(int base, int pot){
    int valor;
    if (pot == 0){
        return 1;
    }
    else{
        return base * elevado(base,pot-1);

    }




}