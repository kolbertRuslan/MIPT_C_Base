//D1 Составить рекурсивную функцию, печать всех чисел от 1 до N
//Вход: Одно натуральное число

#include <stdio.h>

void recFunc(int n) {
    
    if (n>0) {
        recFunc(n-1);
        printf("%d ", n);
    }
    
}

int main() {
	int a=5;
	
	scanf("%d", &a);
	recFunc(a);
	
	return 0;
}