// E6 Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.
// Ввод: 12 целых чисел через пробел
// Вывод: Среднее арифметическое в формате "%.2f"

#include <stdio.h>
#define SIZE 12

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
    float avg = 0.0;
    
    for (i = 0; i < lenght; i++) {
        sum = sum + arr[i];
        avg = (float) sum / lenght;
    }
    printf("%.2f", avg);
}


int main() {
    //int array[SIZE] = {0};
    int array[SIZE] = {4, -5, 3, 10, -4, -6, 8, -10, 1, 0, 5, 7};
    input(array, SIZE);
    calculations(array, SIZE);
    return 0;
}