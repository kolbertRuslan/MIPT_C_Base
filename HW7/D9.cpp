//D9 Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию. int sum_digits(int n)
//Вход: Одно натуральное число.


#include <stdio.h>

int recFunc(int n) {
    int sum = n%10;
   
    if (n>= 10) {
        sum += recFunc(n/10);
        //printf("%d", sum);
    }
    return sum;
}


int main() {
	int a=1000;
	
	scanf("%d", &a);

	printf("%d", recFunc(a));
	return 0;
}