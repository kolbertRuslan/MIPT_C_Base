//D2 Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
//Вход: Одно натуральное число

#include <stdio.h>

int recFunc(int n) {
    static int sum=0;
    
    if (n>0) {
        sum = sum+n;
        recFunc(n-1);
    }
    return sum;
}

int main() {
	int a=100;
	
	scanf("%d", &a);
	printf("%d ", recFunc(a));
	
	return 0;
}