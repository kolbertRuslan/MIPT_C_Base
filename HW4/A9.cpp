#include <stdio.h>

//A9 Ввести пять чисел и найти наибольшее из них
int main() {
    //int a=4, b=15, c=9, d=56, e=4, max=0;
    
    int a=0, b=0, c=0, d=0, e=0, max=0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    
    max = a>b ? a : b;
    max = max>c ? max : c;
    max = max>d ? max : d;
    max = max>e ? max : e;
    
    printf("%d", max);
    
    return 0;
}