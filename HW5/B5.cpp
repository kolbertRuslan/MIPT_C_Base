#include <stdio.h>

//B5 Ввести целое число и найти сумму его цифр. число >= 0
int main() {
    int a=111, sum=0;
    
    scanf("%d", &a);
    
    while (a != 0) {
        sum += a%10;
        a = a/10;
    }
    
    printf("%d", sum);
    
    return 0;
}