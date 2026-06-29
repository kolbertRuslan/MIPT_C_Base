// Е7 Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива
// Ввод: 10 целых чисел через пробел
// Вывод: 10 целых чисел через пробел

#include <stdio.h>
#define aSize 10
 
void aPrint(int *arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
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
    
    for (int i = 0; i < aSize; i++) {
        
        if (scanf("%d", &array[i]) != 1) {
            return 1;
        }
    }


    for (int i = 0; i < 2; i++) {
        reverseArray(array + i * aSize / 2, aSize / 2);
    }

    aPrint(array, aSize);
    return 0;
}
