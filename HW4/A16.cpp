#include <stdio.h>

//A16 Ввести три числа и определить, верно ли, что они вводились в порядке возрастания
int main() {
    int a=4, b=5, c=17;
    //int a=0, b=0, c=0;
    
    scanf("%d%d%d", &a, &b, &c);
    
    if (a<b && b<c) printf("YES");
    else printf("NO");
    
    return 0;
}