#include <stdio.h>

//A11 Ввести пять чисел и напечатать сумму максимума и минимума
int main() {
    //int a=4, b=15, c=9, d=56, e=4, max=0, min=0, sum=0;
    
    int a=0, b=0, c=0, d=0, e=0, max=0, min=0, sum=0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    
    max = a>b ? a : b;
    max = max>c ? max : c;
    max = max>d ? max : d;
    max = max>e ? max : e;
    
    min = a<b ? a : b;
    min = min<c ? min : c;
    min = min<d ? min : d;
    min = min<e ? min : e;
    
    sum = max + min;
    
    //printf("%d\n", max);
    //printf("%d\n", min);
    printf("%d", sum);
    
    return 0;
}