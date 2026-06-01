#include <stdio.h>

//B19 Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.
int main() {
    int a=1234, sum=0;
    
    scanf("%d", &a);
    if (a < 0) a = -a;
    
    while (a != 0) {
        sum += a%10;
        a = a/10;
    }
    
    if (sum == 10) printf("YES");
    else printf("NO");
    
    return 0;
}
