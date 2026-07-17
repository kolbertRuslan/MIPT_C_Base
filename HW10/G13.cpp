
//G13
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    char path[1000];
    
    fgets(path, 1000, in);

    int len = strlen(path);
    if (path[len - 1] == '\n') {
        path[len - 1] = '\0';
        len--;
    }

    int dot_index = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (path[i] == '.') {
            dot_index = i;
            break; 
        }
        if (path[i] == '/') {
            break; 
        }
    }

    if (dot_index != -1) {
        path[dot_index] = '\0';
    }

    fprintf(out, "%s.html\n", path);

    fclose(in);
    fclose(out);

    return 0;
}
