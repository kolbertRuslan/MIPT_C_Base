//D4 Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию void print_num(int num)
//Вход: Одно не отрицательное целое число

#include <stdio.h>

void print_num(int num) {

    if (num/10 > 0) {
        print_num(num/10);
    }
    printf("%d ", num%10);
}

int main() {
	int a=54321;
	
	scanf("%d", &a);
	print_num(a);
	
	return 0;
}
