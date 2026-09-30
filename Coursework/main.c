/* 
Курсовая работа
Программирование на С. Базовый курс
Выполнил: Кольберт Р.А.
Группа Д01-134

Для сборки программы, в терминале ввести команду:
mingw32-make

Для запуска программы, в терминале ввести команду:
.\prog.exe

Полный перечень команд:
.\prog.exe                                      запустить программы без действий
.\prog.exe -h                                   показать справку
.\prog.exe -f temperature_small.csv             Читать данные из файла
.\prog.exe -f temperature_small.csv -p          напечатать массив
.\prog.exe -f temperature_small.csv -m 1        статистика за указанный месяц
.\prog.exe -f temperature_small.csv -y 2021     статистика за указанный год
.\prog.exe -f temperature_small.csv -s d i      (sortByDateIncrease) отсортировать данные по возрастанию даты
.\prog.exe -f temperature_small.csv -s d d      (sortByDateDecrease) отсортировать данные по убыванию даты
.\prog.exe -f temperature_small.csv -s t i      (sortByTempIncrease) отсортировать данные по возрастанию температуры
.\prog.exe -f temperature_small.csv -s t d      (sortByTempDecrease) отсортировать данные по убыванию температуры

Примечание:
.\prog.exe -f temperature_big.csv - Чтение большого файла работает, но оч долго выполняется
*/


#include "temp_api.h"

//=============================== MAIN ===============================
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");

    Array arr;
    arr.size = 0;
    arr.capacity = 2;
    arr.rec = (Record*)malloc(arr.capacity * sizeof(Record));

    if (arr.rec == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // Приветствие
    printf("\nКурсовая работа\n");
    printf("Программирование на С. Базовый курс\n");
    printf("Выполнил: Кольберт Р.А.\n");
    printf("Группа: Д01-134\n");
    printf("Программа для работы с данными датчика температуры\n");
    printf("Для вызова справки введите: .\\prog.exe -h\n");
    printf("\n");

    // Обработка аргументов командной строки
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
                    //printf("Файл: %s\n", argv[i + 1]);
                    readCSV(&arr, argv[i + 1]);
                    i++;
                }
                else
                {
                    printf("Не указано имя файла\n");
                    return 1;
                }
                break;

            case 'p':
                printf("\n");
                printArray(&arr);
                return 0;
            
            case 'm':
                if (i + 1 < argc)
                {
                    int month = atoi(argv[i+1]);
                    if (month < 1 || month > 12)
                    {
                        printf("\n");
                        printf("Месяц указан неверно. Введите значение от 1 до 12\n");
                        printf("\n");
                        return 1;
                    }
                    i++;
                    printf("\n");
                    printf("Статистика за месяц %d:\n", month);
                    avgMonthTemp(&arr, month);
                    minMonthTemp(&arr, month);
                    maxMonthTemp(&arr, month);
                }
                else
                {
                    printf("Не указан месяц\n");
                    return 1;
                }
                break;
            
            case 'y':
                if (i + 1 < argc)
                {
                    int year = atoi(argv[i + 1]);
                    if (year < 0)
                    {
                        printf("\n");
                        printf("Год указан неверно\n");
                        printf("\n");
                        return 1;
                    }
                    i++;
                    printf("\n");
                    printf("Статистика за год %d:\n", year);
                    avgYearTemp(&arr, year);
                    minYearTemp(&arr, year);
                    maxYearTemp(&arr, year);
                }
                else
                {
                    printf("Не указан год\n");
                    return 1;
                }
                break;
            
            case 's':
                if (i + 2 < argc)
                {
                    if (argv[i+1][0] == 'd' && argv[i+2][0] == 'd') sortByDateDecrease(&arr);
                    else if (argv[i+1][0] == 'd' && argv[i+2][0] == 'i') sortByDateIncrease(&arr);
                    else if (argv[i+1][0] == 't' && argv[i+2][0] == 'd') sortByTempDecrease(&arr);
                    else if (argv[i+1][0] == 't' && argv[i+2][0] == 'i') sortByTempIncrease(&arr);
                    else
                    {
                        printf("Указан не верный тип сортировки\n");
                        return 1;
                    } 
                }
                else
                {
                    printf("Не указан тип сортировки\n");
                    return 1;
                }
                break;

            default:
                printf("Неизвестный ключ: %s\n", argv[i]);
                return 1;
        }
    }
    
/*
    //printHelp();

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
*/
    freeMemory(&arr);
    return 0;
}
