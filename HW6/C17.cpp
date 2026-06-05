#include <stdio.h>

//C17 Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению. int is_happy_number(int n)
// Вход: Одно целое не отрицательное число, т.е. 0 и больше

#include <stdio.h>

int is_happy_number(int n) {
    int sum = 0, prod = 1, last_digit = 0;
        
    while (n !=0) {
        last_digit = n%10;
        sum += last_digit;
        prod *= last_digit;
        n /= 10;
    }
    
    if (sum == prod) return 1;
    else return 0;
}


int main() {
    int a=123;
    
    scanf("%d", &a);
    if (is_happy_number(a) == 1) printf("YES");
    else printf("NO");
}