#include <stdio.h>
 
//С5 Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования

int func(int N) {
    int sum=0;
    
    for (int i=0; i<=N; i++) {
        sum +=i;
    }
    return sum;
}

int main(void) {
    int a=100;
    
    scanf("%d", &a);
    printf("%d", func(a) );

    return 0;
}
