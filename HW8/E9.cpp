// Е9 Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1
// Ввод: 10 целых чисел через пробел
// Вывод: 10 целых чисел через пробел

#include <stdio.h>

int main() {
    int arr[10];
    
    // Ввод
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    int last = arr[9];
    
    // Сдвиг
    for (int i = 9; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[0] = last;
    
    // Вывод
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}