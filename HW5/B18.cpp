#include <stdio.h>

//B18 Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов. Ввести количество n элементов
int main(void) {
    unsigned int n=10, previous=1, current=1, m=0;
    
    scanf("%d", &n);
    
    if (n == 1) printf("1");
    else
        if (n != 0) {
            printf("1 1 ");
            
            for (int i = 2; i < n; ++i) {
                m = previous + current;
                previous = current;
                current = m;
                printf("%u ", current);
            }
        }
        
    return 0;
}