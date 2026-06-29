// E1 Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива
// Ввод: 5 целых не нулевых чисел через пробел
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
float calculations(int arr[], int lenght) {
    int i=0, sum=0;
    for (i = 0; i < lenght; i++) {
        sum += arr[i];
    }
    return (float)sum/i;
}


// Функция печати
void output(int arr[], int lenght) {
    for (int i = 0; i < lenght; i++)
        printf("%d", arr[i]);
        //printf("\n");
}

int main() {
    //int array[SIZE] = {0};
    int array[SIZE] = {1, 2, 3, 4, 5};
    input(array, SIZE);
    printf("%.3f", calculations(array, SIZE)); 
    //output(array, SIZE);
    return 0;
}
