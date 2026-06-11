//D7 Составить рекурсивную функцию, печать всех чисел от N до 1.
//Вход: Одно натуральное число

#include <stdio.h>

void print_num(int n) {
    printf("%d ", n);
    if (n > 1) {
        print_num(n-1);
    }
    
}

int main() {
	int a=5;
	
	scanf("%d", &a);
	print_num(a);
	
	return 0;
}