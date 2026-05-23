
#include <stdio.h>

int main()
{
    // А4. Ввести всё вместе через пробел, найти сумму и произведение
    // Пример 1: 1, 2, 3. Пример 2: 4, 5, 7.
    
    int a=1, b=2, c=3, sum, multiplication;
    
    //printf("Input a, b, c:\n");
    scanf ("%d%d%d", &a, &b, &c);
    
    sum = a + b + c;
    multiplication = a * b * c;
    
    printf("%d+%d+%d=%d \n", a, b, c, sum);
    printf("%d*%d*%d=%d \n", a, b, c, multiplication);
    
    return 0;
}
