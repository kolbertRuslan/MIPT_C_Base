#include <stdio.h>
//С3 Написать функцию, которая возвращает среднее арифметическое
// двух переданных ей аргументов (параметров). int middle(int a, int b)
// Вход: два целых не отрицательных числа

int middle(int a, int b) {
    int output = (a+b)/2;
    return output;
}


int main(void) {
    int c=10, d=20;
    
    scanf("%d%d",&c, &d);
    
    printf("%d", middle(c, d) );
    return 0;
}