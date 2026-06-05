#include <stdio.h>
//С1 Составить функцию, модуль числа и привести пример ее использования.

int absolute(int a) {
    if (a < 0) a = -a;
    return a;
}

int main(void) {
    int a=-10;
    scanf("%d",&a);
    printf("%d",absolute(a));
    return 0;
}