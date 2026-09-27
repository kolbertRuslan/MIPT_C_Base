/* 
Курсовая работа. Базовый курс по C.
Выполнил: Кольберт Руслан

Команды для терминала VS Code:

mingw32-make            собрать проект
.\prog.exe              запустить программу

.\prog.exe -h           показать справку

.\prog.exe -f temperature_small.csv         Читать данные из файла

.\prog.exe -m 1         статистика за указанный месяц
.\prog.exe -y 2021      статистика за указанный год

-sortByDateIncrease
-sortByDateDecrease
-sortByTempIncrease
-sortByTempDecrease

.\prog.exe -f temperature_small.csv -m 1    

*/


#include "temp_api.h"

//=============================== MAIN ===============================
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");

    //printHelp();

    Array arr;
    arr.size = 0;
    arr.capacity = 2;
    arr.rec = (Record*)malloc(arr.capacity * sizeof(Record));

    if (arr.rec == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    //initArray(&arr);  // функция написана, но не используется
    
    readCSV(&arr, "temperature_small.csv");
    //readCSV(&arr, "temperature_big.csv");
    //readCSV(&arr, "test_big.txt");

    //printArray(&arr);

    avgMonthTemp(&arr, 2);
    minMonthTemp(&arr, 2);
    maxMonthTemp(&arr, 2);

    avgYearTemp(&arr, 2021);
    minYearTemp(&arr, 2021);
    maxYearTemp(&arr, 2021);

    sortByDateDecrease(&arr);
    sortByTempIncrease(&arr);
    sortByTempDecrease(&arr);
    sortByDateIncrease(&arr);

    //getchar(); // Ждет нажатия Enter

    freeMemory(&arr);
    return 0;
}
