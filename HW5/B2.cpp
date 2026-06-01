#include <stdio.h>

//B2 Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.

int main() {
    int a=1, b=5;
    
    scanf("%d%d", &a, &b);

    
    for (int i=a; i<=b; i++) {
        printf("%d ", i*i);
    }
    
    
    return 0;
}