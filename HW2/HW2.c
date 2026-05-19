#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	
	int n1_10 = 12345678;
	int n2_10 = 1000000;
	int n1_16 = 0x12345678;
	int n2_16 = 0x1000000;
	
	printf("1. Перевести из десятичнойв шестнадцатиричную\n");
	
	printf("Десятичная	|	Шестнадцатиричная\n");
	printf("%d	|	%x\n", n1_10, n1_10);
	printf("%d		|	%x\n", n2_10, n2_10);
	
	printf("\n");
	
	printf("2. Перевести из шестнадцатиричной в десятичную\n");
	printf("Шестнадцатиричная	|	Десятичная\n");
	printf("%x		|	%d\n", n1_16, n1_16);
	printf("%x			|	%d\n", n2_16, n2_16);
	
	printf("\n");
	
	printf("3. Сгущённого молока и мёда и можно без хлеба\n");
	char milk = 'M', honey = 'H', bread = 'B';
	printf("%c && %c && !%c \n", milk, honey, bread);
	
	printf("\n");
	
	printf("4. Доказать тождества\n");
	printf("A->B = !A||B\n");
	printf("A	|	B	|	A->B	|	!A||B\n");
	printf("0	|	0	|	1	|	1\n");
	printf("0	|	1	|	1	|	1\n");
	printf("1	|	0	|	0	|	0\n");
	printf("1	|	1	|	1	|	1\n");
	
	printf("\n");
	
	printf("A<->B = (A&&B) || (!A&&!B)\n");
	printf("A	|	B	|	A<->B	|	A&&B	|	!A&&!B	|	(A&&B) || (!A&&!B)\n");
	printf("0	|	0	|	1	|	0	|	1	|	1\n");
	printf("0	|	1	|	0	|	0	|	0	|	0\n");
	printf("1	|	0	|	0	|	0	|	0	|	0\n");
	printf("1	|	1	|	1	|	1	|	0	|	1\n");
	
	
	return 0;
}
