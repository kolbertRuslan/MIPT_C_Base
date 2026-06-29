// Е8 Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
// Ввод: 12 целых чисел через пробел
// Вывод: 12 целых чисел через пробел

#include <stdio.h>
 #define aSize 12

void aPrint(int *arr, int len) {
    for (int i = 0; i < len; i++)
    printf("%d ",arr[i]);
}

// идти с двух концов части навстречу
void reverseArray(int *array, int num) {
    for (int i = 0, j = num - 1; i < j; i++, j--) {
    int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}

int main() {
 
    int array[aSize] = {0};
    
    for (int i=0; i < aSize; i++) {
        scanf("%d", &array[i]);
    }

    // отрезать кусок массив и передать в ф-ю чтоб перевернуть эту часть, где i - номер части
    for (int i=0; i<3; i++) {
        reverseArray(array + i*aSize/3, aSize/3);
    }

    aPrint(array, aSize);
    return 0;
} 