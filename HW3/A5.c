
#include <stdio.h>

int main()
{
    // А5. Ввести int получить float
    // Пример 1: 4, 5, 7. Прмиер 2: 1, 2, 3.
    
    //~ int a=4, b=5, c=7;
    int a=0, b=0, c=0;
    float average;
    
    //printf("Input a, b, c:\n");
    scanf ("%d%d%d", &a, &b, &c);
    
    average = (a + b + c) / 3.0f;
    
    printf("%.2f \n", average);
    
    return 0;
}
