/* 
Домашнее задание №12.
Выполнил: Кольберт Руслан

Команды для терминала VS Code:
mingw32-make            собрать проект
.\prog.exe              запустить программу
.\prog.exe -h           показать справку
.\prog.exe -m 1         статистика только за указанный месяц
.\prog.exe -m 2
.\prog.exe -m 3
.\prog.exe -f data.csv  читать данные из CSV файла
*/


#include "temp_api.h"
#include <locale.h>


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");

    struct temp data[] =
    {
        {2024, 1, 1,  0,  0, -10},
        {2024, 1, 5,  6,  30,  -12},
        {2024, 1, 10, 12,  0,  -3},
        {2024, 1, 22, 18, 15,  -6},

        {2024, 3, 3,  0,  0,   3},
        {2024, 3, 3,  6,  15,   5},
        {2024, 3, 17, 12,  25,   -5},
        {2024, 3, 26, 18,  5,   0},

        {2024, 2, 2,  0,  45,  -5},
        {2024, 2, 9,  6,  25,  0},
        {2024, 2, 12, 12,  34,   2},
        {2024, 2, 28, 18,  12,   -1}
    };



    int month = 0;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-')
            continue;

        switch (argv[i][1])
        {
            case 'h':
                printHelp();
                return 0;

            case 'f':
                if (i + 1 < argc)
                {
                    printf("CSV файл: %s\n", argv[i + 1]);
                    printf("\nЧтение CSV в ДЗ№12 не требуется.\n\n");
                    return 0;   // завершить программу
                }
                else
                {
                    printf("Ошибка! Не указано имя файла.\n");
                    return 1;
                }
                break;

            case 'm':
                if (i + 1 < argc)
                {
                    month = argv[i + 1][0] - '0';

                    // Если месяц состоит из двух цифр
                    if (argv[i + 1][1] != '\0')
                    {
                        month = month * 10 + (argv[i + 1][1] - '0');
                    }

                    i++;
                }
                else
                {
                    printf("Ошибка! Не указан номер месяца.\n");
                    return 1;
                }
                break;

            default:
                printf("Неизвестный ключ: %s\n", argv[i]);
                return 1;
        }
    }



    int size = sizeof(data) / sizeof(data[0]);

    printf("\nИсходные данные\n");
    printArray(data, size);

    if (month != 0)
    {
        printf("\nМесяц %d\n", month);
        printf("Средняя температура : %d\n", avgMonthTemp(data, size, month));
        printf("Минимальная         : %d\n", minMonthTemp(data, size, month));
        printf("Максимальная        : %d\n", maxMonthTemp(data, size, month));
    }
    else
    {
        printf("\nЯнварь\n");
        printf("Средняя температура : %d\n", avgMonthTemp(data, size, 1));
        printf("Минимальная         : %d\n", minMonthTemp(data, size, 1));
        printf("Максимальная        : %d\n", maxMonthTemp(data, size, 1));

        printf("\nФевраль\n");
        printf("Средняя температура : %d\n", avgMonthTemp(data, size, 2));
        printf("Минимальная         : %d\n", minMonthTemp(data, size, 2));
        printf("Максимальная        : %d\n", maxMonthTemp(data, size, 2));

        printf("\nМарт\n");
        printf("Средняя температура : %d\n", avgMonthTemp(data, size, 3));
        printf("Минимальная         : %d\n", minMonthTemp(data, size, 3));
        printf("Максимальная        : %d\n", maxMonthTemp(data, size, 3));

        printf("\nЗа год\n");
        printf("Средняя температура : %d\n", avgYearTemp(data, size));
        printf("Минимальная         : %d\n", minYearTemp(data, size));
        printf("Максимальная        : %d\n", maxYearTemp(data, size));

        sortByDate(data, size);
        printf("\nСортировка по дате\n\n");
        printArray(data, size);

        sortByTempIncrease(data, size);
        printf("\nСортировка по возрастанию температуры\n\n");
        printArray(data, size);

        sortByTempDecrease(data, size);
        printf("\nСортировка по убыванию температуры\n\n");
        printArray(data, size);

        addRecord(data, &size, 2024, 4, 1, 12, 0, 15);
        printf("\nДобавление записи\n\n");
        printArray(data, size);
    }

    //getchar();
    return 0;
}