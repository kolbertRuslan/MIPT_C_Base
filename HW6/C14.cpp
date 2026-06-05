#include <stdio.h>

//C14 Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу.
// Вход: Одно целое не отрицательное число, т.е. 0 и больше
#include <stdio.h>

void func(int input) {
    int sum=0;
    
    if (input == 0) printf("YES");
    else {
        while (input !=0) {
            // отделяю последнюю цифру и добавляю её в сумму
            sum += input%10;
            
            // отбрасываю последнюю цифру
            input /= 10;
        }
        
        if (sum%2 == 0) printf("YES");
        else printf("NO");
    }
}


int main() {
    int a=0;
    
    scanf("%d", &a);
    func(a);
    
}