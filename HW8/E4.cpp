// E4 Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
// Ввод: 10 целых чисел через пробел.
// Вывод: Сумма двух максимальных элементов.

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

// Вывод
void output(int arr[], int lenght) {
    for (int i = 0; i < lenght; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

// Функция вычислений
void bubbleSort(int arr[], int n) {
    int swapped;
    
    for (int i = 0; i < n - 1; ++i) {
        swapped = 0; // Логический ноль (false)
        
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Вручную меняем элементы местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1; // Логическая единица (true)
            }
        }
        // Если обменов не было, массив отсортирован
        if (swapped == 0) {
            //output(arr, SIZE);    // вывод массива целиком
            printf("%d ", (arr[8] + arr[9]) );
            break;
        }
    }
}



int main() {
    //int array[SIZE] = {0};
    int array[SIZE] = {1, -2, 3, 0, -5, 4, 3, 78, -412, 0};
    input(array, SIZE);
    bubbleSort(array, SIZE);
    return 0;
}

