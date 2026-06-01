#include <stdio.h>

//B12 Организовать ввод натурального числа с клавиатуры.
// Программа должна определить наименьшую и наибольшую цифры,
// которые входят в состав данного натурального числа

int main() {
    int a=22, currentNumber=0, minNumber=9, maxNumber=0;
    
    scanf("%d", &a);
    if (a < 0) a = -a;
    
    do {
        //выделить последнее число
        currentNumber = a%10;
    
        if (currentNumber < minNumber) minNumber = currentNumber;
        if (currentNumber > maxNumber) maxNumber = currentNumber;
        
        //отбросить последнее число
        a = a/10; 
    } while (a != 0);
    
    printf("%d %d", minNumber, maxNumber);
    
    return 0;
}