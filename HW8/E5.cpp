// E5 Считать массив из 10 элементов и посчитать сумму положительных элементов массива.
// Ввод: 10 целых чисел через пробел
// Вывод: Одно целое число - сумма положительных элементов массива

#include <stdio.h>
#define SIZE 10

// Функция ввода символов
int input(int arr[], int lenght) {
    int i=0;
    for (i=0; i<lenght; i++) {
        scanf("%d", &arr[i]);
    }
    return i;
}


// Функция вычислений
void calculations(int arr[], int lenght) {
    int i=0, sum = 0;
    
    for (i = 0; i < lenght; i++) {
        if (arr[i] > 0) {
            sum = sum + arr[i];
        }
    }
    printf("%d", sum);
}


int main() {
    //int array[SIZE] = {0};
    int array[SIZE] = {1, -2, 3, 0, -5, 4, 3, 78, -412, 0};
    input(array, SIZE);
    calculations(array, SIZE);
    return 0;
}