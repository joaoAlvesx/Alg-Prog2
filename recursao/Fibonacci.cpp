#include <stdio.h>


int fibonacci(int n);
int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("O %dº elemento da sequência de Fibonacci é %d\n", n, fibonacci(n));
    return 0;
}


int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}