// G9 В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
// Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.

// Формат входных данных Строка из меленьких и больших английских букв, знаков препинания и пробелов.
// Размер строки не более 1000 сивмолов.
// Формат результата Строка из меленьких и больших английских букв.

#include <stdio.h> 
#include <string.h>  


#define MAX_SIZE 1002

int main(void) {
    
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    // Проверка 
    if (in == NULL || out == NULL) {
        if (in) fclose(in);  
        if (out) fclose(out);
        return 1;            
    }

    char str[MAX_SIZE];
    int visited[256] = {0};

    // читать строки
    if (fgets(str, sizeof(str), in) != NULL) {
        size_t len = strlen(str);
        size_t write_index = 0;

        for (size_t read_index = 0; read_index < len; read_index++) {
            char current_char = str[read_index];

            
            if (current_char != ' ' && current_char != '\n' && current_char != '\r') {
                unsigned char ascii_code = (unsigned char)current_char;

                if (visited[ascii_code] == 0) {
                    visited[ascii_code] = 1;
                    str[write_index] = current_char;
                    write_index++;
                }
            }
        }

        str[write_index] = '\0';
        fprintf(out, "%s\n", str);
    }

    fclose(in);
    fclose(out);
    return 0;
}
