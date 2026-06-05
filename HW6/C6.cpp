#include <stdio.h>
 
//С6 Необходимо составить функцию, которая определяет, сколько зерен попросил положить на N-ую клетку изобретатель
// шахмат (на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)

unsigned long long func(int N) {
    unsigned long long sum=1;
    
    for (int i=2; i<=N; i++) {
        sum *=2;
    }
    return sum;
}

int main(void) {
    int a=32;
    
    scanf("%d", &a);
    printf("%llu", func(a) );

    return 0;
}
