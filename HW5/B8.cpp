#include <stdio.h>

//B8 Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9»
int main() {
    int a=190, currentNumber=0, counter9=0;
    
    scanf("%d", &a);
    if (a < 0) a = -a;

    while (a != 0) {
        currentNumber = a%10;
        if (currentNumber == 9) counter9++;
        a = a/10; 
    }
    
    if (counter9 == 1) printf("YES");
    else printf("NO");
    
    return 0;
}