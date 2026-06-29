// Е10 Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4
// Ввод: 12 целых чисел через пробел
// Вывод: 12 целых чисел через пробел

#include <stdio.h>

int main() {
    int arr[12], last[4];
    
    // Ввод
    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    for (int i = 0; i < 4; i++) {
        last[i] = arr[i+8];
    }
    

    // Сдвиг
    for (int i = 11; i > 3; i--) {
        arr[i] = arr[i - 4];
    }
    
    
    for (int i = 0; i < 4; i++) {
        arr[i] = last[i];
    }
    
    
    // Вывод
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}