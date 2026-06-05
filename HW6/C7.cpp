#include <stdio.h>

//С7 Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.
// Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9

int func(int N, int P) {
    int NewNumber = 0, rank = 1;

    if (N == 0) return 0;

    while (N != 0) {
        int ostatok = N % P;
        N /= P;
        
        NewNumber = NewNumber + ostatok * rank;
        
        rank *= 10;
    }
    
    return NewNumber;
}

int main(void) {
    int a = 10, b = 10;
    
    scanf("%d%d", &a, &b);
    printf("%d\n", func(a, b) );

    return 0;
}