#include <stdio.h>

//C15 Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу. int grow_up(int n)
// Вход: Одно целое не отрицательное число, т.е. 0 и больше

#include <stdio.h>

int grow_up(int n) {
    
    if (n < 10) return 1;
    
    int current = 0;

    int previous = n%10;
    n /= 10;
        
    while (n !=0) {
        current = n%10;
        if (current >= previous) return 0;
            
        n /= 10;
        previous = current;
    }
    return 1;
}


int main() {
    int a=528;
    
    scanf("%d", &a);
    if (grow_up(a) == 1) printf("YES");
    else printf("NO");
}