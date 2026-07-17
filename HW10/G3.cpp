// G3 В файле input.txt дана строка из не более 1000 символов. Показать номера символов,
// совпадающих с последним символом строки. Результат записать в файл output.txt.
// Формат входных данных: Строка из не более 1000 символов
// Формат результата: Целые числа через пробел - номера символа, который совпадает с последним символом строки.

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1005

int main() {
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    
    if (f_in == NULL || f_out == NULL) {
        return 1;
    }

    char str[MAX_LEN];
    if (fgets(str, MAX_LEN, f_in) != NULL) {
        size_t len = strlen(str);
        
    
        while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
            str[len - 1] = '\0';
            len--;
        }

        if (len > 0) {
            char last_char = str[len - 1];
            
            
            for (size_t i = 0; i < len - 1; i++) {
                if (str[i] == last_char) {
                    fprintf(f_out, "%zu ", i);
                }
            }
        }
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}


