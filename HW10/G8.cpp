// G8 В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
// Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
// Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
// Вывести массив по возрастанию в файл output.txt.

// Формат входных данных Строка из английских букв, цифр и знаков препинания
// Формат результата Последовательность целых чисел отсортированная по возрастанию

#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 1002
#define MAX_NUMS_SIZE 501

int main(void) {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (in == NULL || out == NULL) {
        if (in) fclose(in);
        if (out) fclose(out);
        return 1;
    }

    char str[MAX_STR_SIZE];
    int numbers[MAX_NUMS_SIZE];
    int count = 0;

    // читаьт
    if (fgets(str, sizeof(str), in) != NULL) {
        size_t len = strlen(str);
        int current_num = 0;
        int in_number = 0;

        // искать
        for (size_t i = 0; i <= len; i++) {
            // Проверка
            if (str[i] >= '0' && str[i] <= '9') {
                current_num = current_num * 10 + (str[i] - '0');
                in_number = 1;
            } else {
                if (in_number) {
                    numbers[count++] = current_num;
                    current_num = 0;
                    in_number = 0;
                }
            }
        }

        //Сорт поплавком 
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }
    }

    // Вывод
    for (int i = 0; i < count; i++) {
        fprintf(out, "%d", numbers[i]);
        if (i < count - 1) {
            fprintf(out, " ");
        }
    }
    fprintf(out, "\n");

    fclose(in);
    fclose(out);

    return 0;
}