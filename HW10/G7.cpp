// G7 В файле input.txt считать символьную строку, не более 10 000 символов.
// Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке.
// Учитывать только английские буквы. Результат записать в файл output.txt.

// Формат входных данных: Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
// Формат результата: Два целых числа. Количество строчных букв и количество заглавных букв.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10001

int main(void) {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (in == NULL || out == NULL) {
        if (in) fclose(in);
        if (out) fclose(out);
        return 1;
    }

    char str[MAX_SIZE];
    int lowercase_count = 0;
    int uppercase_count = 0;

    // Чтение строки из файла
    if (fgets(str, sizeof(str), in) != NULL) {
        // Определение длины строки с помощью <string.h>
        size_t len = strlen(str);

        for (size_t i = 0; i < len; i++) {
            // Проверка диапазона строчных английских букв
            if (str[i] >= 'a' && str[i] <= 'z') {
                lowercase_count++;
            }
            // Проверка диапазона прописных английских букв
            else if (str[i] >= 'A' && str[i] <= 'Z') {
                uppercase_count++;
            }
        }
    }

    // Запись двух чисел через пробел
    fprintf(out, "%d %d\n", lowercase_count, uppercase_count);

    fclose(in);
    fclose(out);

    return 0;
}

