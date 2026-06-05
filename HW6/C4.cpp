#include <stdio.h>
 
//С4 Описать функцию вычисления f(x).
// Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.
// Вход: Последовательность не нулевых целых чисел, в конце последовательности число 0.

// Функция вычисления f(x)
int middle(int x) {
    int f=0;
    
    if (x >= -2 && x < 2) f = x*x;
    else if (x >= 2) f = x*x + 4*x + 5;
    else if (x < -2) f = 4;
    
    return f;
}

int main(void) {
    int a=0, max = -1, firstIterationFlag = 1; 

    while (1) {
        if (scanf("%d", &a) != 1) break; // Выход, если ввод некорректен

        if (a == 0) break; // Выход при встрече нуля (конец последовательности)
        
        int current = middle(a);

        // Если это первое число или нашли значение больше текущего максимума
        if (firstIterationFlag || (current > max) ) {
            max = current;
            firstIterationFlag = 0; // Сбрасываем флаг после первой записи
        }
    }

    printf("%d", max);
    
    return 0;
}