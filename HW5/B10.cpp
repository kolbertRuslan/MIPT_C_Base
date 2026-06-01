#include <stdio.h>

//B10 Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания
int main() {
    int a=11, current=0, previous=0;
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
        if (current >= previous) {
            flag = 1;
            break;
        }
        
        //отбросить последнее число
        a = a/10; 
        
        // передать текущее значение в предыдущее
        previous = current;
    }
    
    if (flag == 1) printf("NO");
    else printf("YES");
    
    return 0;
}
