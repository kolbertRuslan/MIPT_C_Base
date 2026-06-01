#include <stdio.h>

//B13 Посчитать количество четных и нечетных цифр числа
int main() {
    int a=101, currentNumber=0, evenCounter=0, oddCounter=0;
    
    scanf("%d", &a);
    if (a < 0) a = -a;
    
    do {
        //выделить последнее число
        currentNumber = a%10;
        
        if (currentNumber%2 == 0) evenCounter++;
        else oddCounter++;
        
        //отбросить последнее число
        a = a/10; 
    } while (a != 0);
    
    printf("%d %d", evenCounter, oddCounter);
    
    return 0;
}