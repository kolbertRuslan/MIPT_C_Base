// E3 Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
// Ввод: 10 целых чисел через пробел
// Вывод: 4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.

#include <stdio.h>

#define SIZE 10

// Функция ввода символов
int input(int arr[], int lenght) {
    int i = 0;
    for (i = 0; i < lenght; i++) {
        scanf("%d", &arr[i]);
    }
    return i;
}

// Функция вычислений
void calculations(int arr[], int lenght) {
    int i = 0;
    int min = arr[0];
    int max = arr[0];
    int indexMin = 1; 
    int indexMax = 1; 

    for (i = 0; i < lenght; i++) {
        if (arr[i] < min) {
            min = arr[i];
            indexMin = i + 1;
        }
        
        if (arr[i] > max) { 
            max = arr[i];
            indexMax = i + 1;
        }
    }
    printf("%d %d %d %d", indexMax, max, indexMin, min);
}

int main() {
    int array[SIZE] = {0};
    input(array, SIZE);
    calculations(array, SIZE);
    return 0;
}
