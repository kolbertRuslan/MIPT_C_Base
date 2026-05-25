#include <stdio.h>

//A10 Ввести пять чисел и найти наименьшее из них
int main() {
    //int a=4, b=15, c=9, d=56, e=4, min=0;
    
    int a=0, b=0, c=0, d=0, e=0, min=0;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    
    min = a<b ? a : b;
    min = min<c ? min : c;
    min = min<d ? min : d;
    min = min<e ? min : e;
    
    printf("%d", min);
    
    return 0;
}