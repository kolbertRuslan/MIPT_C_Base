#include <stdio.h>

//A7 Ввести два числа и вывести их в порядке возрастания.
int main() {
    //int a=15, b=9;
    
    int a=0, b=0;
    scanf("%d%d", &a, &b);
    
    if (a>b) printf("%d  ", b);
    else printf("%d  ", a);
    
    if (a>b) printf("%d  ", a);
    else printf("%d  ", b);
    
    return 0;
}