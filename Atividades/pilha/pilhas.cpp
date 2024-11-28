#include <stdio.h>
#include <string.h>

const int MAX_LINHA =2000; 
const int MAX_CASOS =100; 
int estavel(char *str);
void empilhe(char *str,char valor,int *t,int n);
int desempilhe(char *str,int *t);
int verif(char *str);

int main() {
    char entradas[MAX_CASOS][MAX_LINHA + 1]; 
    int n = 0;                           
    char linha[MAX_LINHA + 1];             

    printf("Digite as strings de entrada (terminar com 1 ou mais '-'(menos)):\n");

  
    while (1) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0'; 

        if (linha[0] == '-') {
            break;
        }

        strcpy(entradas[n], linha);
        n++; 

        if (n >= MAX_CASOS) {
            printf("Número máximo de casos atingido (%d).\n", MAX_CASOS);
            break;
        }
    }

 
   
    for (int i = 0; i < n; i++) {
        int n = estavel(entradas[i]);
        printf("%d. %d \n",i+1,n);
    }

    return 0;
}

int estavel(char *str){
    int passos = 0,t=0;
    char aux[strlen(str)];
   /* int verificador = verif(str);
    if (verificador == 0)
        return 0;
    else{
*/

    for (int i = 0; i<strlen(str);i = i+2){
        if(str[i] == '}'){ 
            str[i] = '{';
            passos++;
            if (str[i+1] == '}'){
                empilhe(aux,str[i],&t,strlen(str));
                empilhe(aux,str[i+1],&t,strlen(str));
            }
            else{
                str[i+1] = '{';
                passos++;
                empilhe(aux,str[i],&t,strlen(str));
                empilhe(aux,str[i+1],&t,strlen(str));
        }
        }
        else {
            if (str[i+1] == '}'){
                empilhe(aux,str[i],&t,strlen(str));
                empilhe(aux,str[i+1],&t,strlen(str));
            }
            else{
                str[i+1] = '{';
                passos++;
                empilhe(aux,str[i],&t,strlen(str));
                empilhe(aux,str[i+1],&t,strlen(str));
            }
        }
}
    
    return passos;
}
//}
void empilhe(char *str,char valor,int *t,int n){
    if(*t == n){
        return;
    }else{
        str[*t] = valor;
        (*t)++;
    }

}
//Funçoes nao utilizadas, desempilhe foi feita para suporte mas nao foi utilizada e função verif foi feita para verificar quando existir {S}
int desempilhe(char *str,int *t){
    int valor = *t;
    if (str[valor] <= 0)
        return -1;
    else{
        (*t)--;
        return str[valor];
    }
}
int verif(char *str){
    int tamanho = strlen(str);
    int iguais = 0;
    
 

    int meio = tamanho / 2;

    char str1[meio + 1];  
    char str2[meio + 1];  

    strncpy(str1, str, meio);
    str1[meio] = '\0';  

    strncpy(str2, str + meio, meio);
    str2[meio] = '\0'; 
    int i =0;
    while (meio > 0 && i < tamanho/2)
    {
        if (str1[meio-1] != str2[i]){
            iguais++;
            meio--;
            i++;
        }
        else
        {
            break;
            meio = -1;
            i = tamanho;
        }
        
    }
    if (iguais == tamanho/2)
        return 0;
    else
        return 1;

}