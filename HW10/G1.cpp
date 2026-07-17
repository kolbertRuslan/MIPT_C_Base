// G1 В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.
// Формат входных данных:
// Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.
// Формат результата:
// Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.

#include <stdio.h>
#include <string.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        return 1;
    }

    char str[105];
    if (fgets(str, sizeof(str), in) == NULL) {
        str[0] = '\0';
    }
    fclose(in);

    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }

    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        return 1;
    }
    
    
    fprintf(out, "%s, %s, %s %zu", str, str, str, len);
    fclose(out);

    return 0;
}

