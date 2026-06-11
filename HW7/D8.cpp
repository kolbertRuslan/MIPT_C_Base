//D8 Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.
//Вход: Два целых числа через пробел.

#include <stdio.h>

void recFunc(int a, int b) {
   printf("%d ", a);
   
   if (a==b) return;
   
   if (a>b) recFunc(a-1, b);
   else recFunc(a+1, b);
}


int main() {
	int a=2, b=7;
	
	scanf("%d%d", &a, &b);
	recFunc(a, b);
	
	return 0;
}