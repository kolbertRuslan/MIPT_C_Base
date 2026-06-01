#include <stdio.h>

//B11 Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.
int main() {
    int a=1230, currentNumber=0, newNumber=0;
    
    scanf("%d", &a);
    if (a < 0) a = -a;
    
    //если последнее число 0, то отбросить его
    currentNumber = a%10;
    if (currentNumber == 0) a = a/10;
    
    while (a != 0) {
        //выделить последнее число
        currentNumber = a%10;
    
        newNumber = newNumber * 10 + currentNumber;
        
        //отбросить последнее число
        a = a/10; 
    }
    
    printf("%d", newNumber);
    
    return 0;
}