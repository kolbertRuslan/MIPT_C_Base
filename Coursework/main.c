/*
    Курсовая работа
    Выполнил: Кольберт Руслан
*/


#include "temp_api.h"
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    
    printf("Hello, Здравствуйте!\n");
    

    getchar(); // Ждет нажатия Enter
    return 0;
}
