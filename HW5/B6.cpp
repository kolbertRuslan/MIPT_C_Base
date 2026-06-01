#include <stdio.h>

//B6 Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.
int main() {
    int a=132, current=0, previous=0;
    int flag = 0;
    
    scanf("%d", &a);
    if (a < 0) a = -a;
    
    current = a%10;
    a = a/10;
    previous = current;
    
    while (a != 0) {
        //выделить текущее число
        current = a%10;
        
        // сравнить текущее с предыдущим
        if (current == previous) {
            flag = 1;
            break;
        }
        
        //отбросить последнее число
        a = a/10; 
        
        // передать текущее значение в предыдущее
        previous = current;
    }
    
    if (flag == 1) printf("YES");
    else printf("NO");
    
    return 0;
}