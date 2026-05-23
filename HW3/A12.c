
#include <stdio.h>

int main()
{
    // А12. На вход подается произвольное трехзначное число, напечать сумму цифр этого числа
    // Пример 1:435. Прмиер 2: 100.
    
    int a=100;
    int sum;
    
    //printf("Input a:\n");
    scanf ("%d", &a);
    
    
    sum = a%10;
    sum += (a/10)%10;
    sum += (a/100)%10;
    
    printf("%d \n", sum);
    
    return 0;
}
