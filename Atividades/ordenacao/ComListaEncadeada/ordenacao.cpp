#include <stdio.h>
#include<stdlib.h>

struct celula
{
    int conteudo;
    struct celula *ant;
    struct celula *seg;
    
};typedef struct celula celula;


void adicionarLista(celula *lst,int valor);
void remover(celula *lst);
void percorrer(celula *lst);
void bubble_sort(celula *lst,int n);
void section_sort(celula *lst);
int main(){

    celula *lst;
    int menu = 3;
    while (menu != 0)
    {
    printf("\nQual a quantidade de elementos que deseja ordernar? ");
    int n=0;
    scanf("%d",&n);

    int *numeros;
    numeros = (int *) malloc(n*sizeof(int));
    printf("\nEnsira %d elementos separados por espaço: ",n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    lst-> conteudo= numeros[0];
    lst->seg = NULL;
    lst->ant = NULL;

    for (int i =1; i<n;i++){
        adicionarLista(lst,numeros[i]);
    }


    printf("antes das ordenaçoes: ");
    percorrer(lst);

    printf("Ordenar com Bubble sort(1) ou Selection sort(2)");
    scanf("%d",&menu);
    if (menu == 1){
        bubble_sort(lst,n);
        percorrer(lst);
    }
    else if(menu == 2){
        section_sort(lst);
        percorrer(lst);
    }
    else
        return 1;

    printf("Deseja ordenar novamente?(1 para Sim e 0 para nao)");
    scanf("%d",&menu);
    if (menu == 0)
        return 1;
}
}

void adicionarLista(celula *lst,int valor){

    celula *nova;
    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = valor;
    nova->seg = lst->seg; 
    lst->seg = nova;
    nova -> ant = lst;

}
/*
void remover(celula *lst){
    celula *remover,*aux;
    if (lst == NULL || lst->seg == NULL) {
        printf("Nada para remover.\n");
        return;
    }
    remover = lst->seg;
    lst->seg = remover->seg;
    if (remover->seg != NULL){
        aux = remover->seg;
        aux->ant = lst;
        free(remover);
        return;
    }else{
        free(remover);
        return;
    }
}
*/
void percorrer(celula *lst)
{
    celula *atual = lst;
    while(atual != NULL){
        printf("%d ",atual->conteudo);
        atual = atual->seg;
    }    
    printf("\n");
}


void bubble_sort(celula *lst,int n){
    celula *atual = lst;
    int aux = 0,troca = 1;

        while(troca){
            troca = 0;
            atual = lst;
            while(atual->seg != NULL){
                if (atual->conteudo > atual->seg->conteudo){
                    aux = atual->conteudo;
                    atual->conteudo = atual->seg->conteudo;
                    atual->seg->conteudo = aux;
                    troca=1;
                }
            atual = atual->seg;
    }
    }
    printf("Bubble Sort: ");
    return;
}
void section_sort(celula *lst){
    
    celula *atual,*proxima,*menor;

    for (atual =lst; atual != NULL; atual = atual->seg){
        menor = atual;

        for (proxima = atual->seg;proxima != NULL;proxima = proxima->seg){
            if ( proxima->conteudo < menor ->conteudo){
                menor = proxima;
            }
        }
        if (menor != atual){
            int aux = atual -> conteudo;
            atual ->conteudo = menor -> conteudo;
            menor -> conteudo = aux;
        }

    }

    printf("Selection Sort: ");
    


}


