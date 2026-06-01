#include <stdio.h>

//B17 Ввести натуральное число и напечатать все числа от 10 до введенного числа -
// у которых сумма цифр равна произведению цифр
int main() {
    int a=1000;
   
    scanf("%d", &a);
    if (a < 0) a = -a;
    
    // Цикл перебора всех чисел от 10 до введенного числа
    for (int i = 10; i <= a; ++i) {
        int temp = i, sum = 0, multiply = 1;
        
        while (temp != 0) {
            int current = temp % 10;
            
            sum += current;
            multiply *= current;
            
            temp = temp/10;
        }
        
        if (sum == multiply) {
            printf("%d ", i);
        }
    }
    
    return 0;
}