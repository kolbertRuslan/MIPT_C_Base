#include <stdio.h>

//B4 Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
int main() {
    int a=123, counter=0;
    
    scanf("%d", &a);
    
    while (a != 0) {
    	a = a/10;
    	counter++;
    }
    
    if (counter == 3) printf("YES");
    else printf("NO");
    
    return 0;
}