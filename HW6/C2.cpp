#include <stdio.h>
//С2 Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.
// Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0

int power(int n, int p) {
    int output = n;
    
    if (p == 0) output = 1;
    else {
        for (int i=1; i<p; i++) {
        output = output * n;
        }
    }
    
    return output;
}


int main(void) {
    int a=-5, b=3;
    
    scanf("%d%d",&a, &b);
    //if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    printf("%d", power(a, b) );
    return 0;
}