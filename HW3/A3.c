#include <stdio.h>
#include <locale.h>

int main(void)
{
    // А3. Ввести по очереди и найти сумму
    //Пример 1: 4, 5, 7. Пример 2: 10, 20, 30
    
    //~ int a=4, b=5, c=7, sum;
    int a=0, b=0, c=0, sum;
    
    //printf("Input a: "); 
    scanf ("%d", &a);
    
    //printf("Input b: ");
    scanf ("%d", &b);
    
    //printf("Input c: ");
    scanf ("%d", &c);
    
    //printf("Sum: ");
    sum = a + b + c;
    
    printf("%d+%d+%d=%d \n", a, b, c, sum);
    
    return 0;
}
