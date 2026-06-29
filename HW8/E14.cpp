// E14 Считать массив из 10 элементов и выделить в другой массив все числа,
// которые встречаются более одного раза. В результирующем массиве эти числа не должны повторяться.
// Ввод: 10 целых чисел через пробел
// Вывод: Целые числа через пробел, которые встречаются более одного раза в исходном массиве.


#include <stdio.h>

int main() {
    int input[10];
    int result[10];
    int result_count = 0;

    // Считываем 10 целых чисел
    for (int i = 0; i < 10; i++) {
        scanf("%d", &input[i]);
    }

    // Ищем дубликаты
    for (int i = 0; i < 10; i++) {
        int count = 0;
        
        // Считаем, сколько раз текущее число встречается в массиве
        for (int j = 0; j < 10; j++) {
            if (input[i] == input[j]) {
                count++;
            }
        }

        // Если число встретилось более одного раза
        if (count > 1) {
            int already_exists = 0;
            
            // Проверяем, нет ли его уже в результирующем массиве
            for (int k = 0; k < result_count; k++) {
                if (result[k] == input[i]) {
                    already_exists = 1;
                    break;
                }
            }
            
            // Если числа еще нет в результате, добавляем его
            if (!already_exists) {
                result[result_count] = input[i];
                result_count++;
            }
        }
    }

    // Выводим результирующий массив
    for (int i = 0; i < result_count; i++) {
        printf("%d", result[i]);
        if (i < result_count - 1) {
            printf(" ");
        }
    }
    
    printf("\n");

    return 0;
}