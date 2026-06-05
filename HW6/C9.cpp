#include <stdio.h>

//С9 Составить функцию вычисления N!. Использовать ее при вычислении факториала int factorial(int n)
// Целое положительное число не больше 20

 unsigned long long factorial (int n) {
    unsigned long long fac = 1;

    if (n == 0) return 1;

    for (int i=1; i<=n; i++) {
        fac = fac * i;
    }
    
    return fac;
}

int main(void) {
    int a = 1;
    
    scanf("%d", &a);
    printf("%llu", factorial(a) );

    return 0;
}