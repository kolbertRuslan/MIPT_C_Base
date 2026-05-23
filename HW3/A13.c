
#include <stdio.h>

int main()
{
    // А13. На вход подается произвольное трехзначное число, напечать произведение цифр этого числа
    // Пример 1:435. Прмиер 2: 102.
    
    //~ int a=435;
    int a=0;
    int sum;
    
    //~ printf("Input a:\n");
    scanf ("%d", &a);
    
    
    sum = a%10;
    sum *= (a/10)%10;
    sum *= (a/100)%10;
    
    printf("%d \n", sum);
    
    return 0;
}
