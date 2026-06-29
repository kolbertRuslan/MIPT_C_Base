// E2 Ввести c клавиатуры массив из 5 элементов, найти минимальный из них
// Ввод: 5 целых чисел через пробел

#include <stdio.h>
#define SIZE 5

// Функция ввода символов
int input(int arr[], int lenght) {
    int i=0;
    for (i=0; i<lenght; i++) {
        scanf("%d", &arr[i]);
    }
    return i;
}


// Функция вычислений
int calculations(int arr[], int lenght) {
    int i=0, min=arr[0];
    for (i = 0; i < lenght; i++) {
        if (arr[i]< min) min = arr[i];
    }
    return min;
}


int main() {
    //int array[SIZE] = {0};
    int array[SIZE] = {1, -2, 3, 0, 5};
    input(array, SIZE);
    printf("%d", calculations(array, SIZE));
    return 0;
}