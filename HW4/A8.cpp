#include <stdio.h>

//A8 Ввести три числа и найти наибольшее из них
int main() {
    //int a=4, b=15, c=9, max=0;
    
    int a=0, b=0, c=0, max=0;
    scanf("%d%d%d", &a, &b, &c);
    
    if (a>b) max = a;
    else max = b;
    
    if (c>max) max =c;
    
    printf("%d", max);

    return 0;
}