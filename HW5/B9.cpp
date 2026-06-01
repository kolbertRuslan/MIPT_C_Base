#include <stdio.h>

//B9 Ввести целое число и определить, верно ли, что все его цифры четные.
int main() {
    int a=24680, currentNumber=0;
    int flag=0;
    
    scanf("%d", &a);
    if (a < 0) a = -a;
    
    while (a != 0) {
        //выделить последнее число
        currentNumber = a%10;
        
        if (currentNumber%2 != 0) {
            flag=1;
            break;
        }
        //отбросить последнее число
        a = a/10; 
    }
    
    if (flag == 1) printf("NO");
    else printf("YES");
    
    return 0;
}