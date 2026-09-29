#include "temp_api.h"

void printHelp(void)
{
    printf("Введите одну из перечисленных команд:\n");
    printf(".\\prog.exe                                     запустить программу без действий\n");
    printf(".\\prog.exe -h                                  показать справку\n");
    printf(".\\prog.exe -f temperature_small.csv            прочитать данные из указанного файла\n");
    printf(".\\prog.exe -f temperature_small.csv -p         напечатать массив прочитанных данных\n");
    printf(".\\prog.exe -f temperature_small.csv -m 1       вывести статистику температуры за указанный месяц 1-12\n");
    printf(".\\prog.exe -f temperature_small.csv -y 2021    вывести статистику температуры за указанный год\n");
    printf(".\\prog.exe -f temperature_small.csv -s d i     (sortByDateIncrease) отсортировать данные по возрастанию даты\n");
    printf(".\\prog.exe -f temperature_small.csv -s d d     (sortByDateDecrease) отсортировать данные по убыванию даты\n");
    printf(".\\prog.exe -f temperature_small.csv -s t i     (sortByTempIncrease) отсортировать данные по возрастанию температуры\n");
    printf(".\\prog.exe -f temperature_small.csv -s t d     (sortByTempDecrease) отсортировать данные по убыванию температуры\n");
    printf("\n");
}

void printArray(const Array* arr)
{
    printf("Стр\tГод\tМес\tДн\tЧас\tМин\tТемп\n");

    for (int i=0; i < arr->size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            i,
            arr->rec[i].year,
            arr->rec[i].month,
            arr->rec[i].day,
            arr->rec[i].hour,
            arr->rec[i].minute,
            arr->rec[i].temperature);
    }
    printf("\n");
}

int avgMonthTemp(const Array* arr, uint8_t month)
{
    int sum = 0;
    int count = 0;

    for (int i=0; i < arr->size; i++)
    {
        if (arr->rec[i].month == month)
        {
            sum += arr->rec[i].temperature;
            count++;
        }
    }

    if (count == 0)
    {
        printf("\nНет данных за месяц %d\n", month);
    }
    else 
    {
        float avg = (float)sum / count;
        printf("Средняя температура:        %.1f\n", avg);
        return avg;
    }
}

int minMonthTemp(const Array* arr, uint8_t month)
{
    int min;
    int count = 0;
    int init_flag = 0;

    for (int i=0; i < arr->size; i++)
    {
        if (arr->rec[i].month == month)
        {
            if (!init_flag)
            {
                min = arr->rec[i].temperature;
                init_flag = 1;
            }
            else  if (arr->rec[i].temperature < min)
            {
                min = arr->rec[i].temperature;
            }

            count++;
        }
    }

    if (count == 0)
    {
        printf("\nНет данных за месяц %d\n", month);
    }
    else 
    {
        printf("Минимальная температура:    %d\n", min);
        return min;
    }

    
}

int maxMonthTemp(const Array* arr, uint8_t month)
{
    int max;
    int count = 0;
    int init_flag = 0;

    for (int i=0; i < arr->size; i++)
    {
        if (arr->rec[i].month == month)
        {
            if (!init_flag)
            {
                max = arr->rec[i].temperature;
                init_flag = 1;
            }
            else  if (arr->rec[i].temperature > max)
            {
                max = arr->rec[i].temperature;
            }

            count++;
        }
    }

    if (count == 0)
    {
        printf("\nНет данных за месяц %d\n", month);
    }
    else 
    {
        printf("Максимальная температура:   %d\n", max);
        return max;
    }
}

int avgYearTemp(const Array* arr, uint16_t year)
{
    int sum = 0;
    int count = 0;

    for (int i=0; i < arr->size; i++)
    {
        if (arr->rec[i].year == year)
        {
            sum += arr->rec[i].temperature;
            count++;
        }
    }

    if (count == 0)
    {
        printf("Нет данных за год %d\n", year);
    }
    else 
    {
        float avg = (float)sum / count;
        printf("Средняя температура:        %.1f\n", avg);
        return avg;
    }
}

int minYearTemp(const Array* arr, uint16_t year)
{
    int min;
    int count = 0;
    int init_flag = 0;

    for (int i=0; i < arr->size; i++)
    {
        if (arr->rec[i].year == year)
        {
            if (!init_flag)
            {
                min = arr->rec[i].temperature;
                init_flag = 1;
            }
            else if (arr->rec[i].temperature < min)
            {
                min = arr->rec[i].temperature;
            }

            count++;
        }
    }

    if (count == 0)
    {
        printf("Нет данных за год %d\n", year);
    }
    else 
    {
        printf("Минимальная температура:    %d\n", min);
        return min;
    }
}

int maxYearTemp(const Array* arr, uint16_t year)
{
    int max;
    int count = 0;
    int init_flag = 0;

    for (int i=0; i < arr->size; i++)
    {
        if (arr->rec[i].year == year)
        {
            if (!init_flag)
            {
                max = arr->rec[i].temperature;
                init_flag = 1;
            }
            else  if (arr->rec[i].temperature > max)
            {
                max = arr->rec[i].temperature;
            }

            count++;
        }
    }

    if (count == 0)
    {
        printf("Нет данных за год %d\n", year);
    }
    else 
    {
        printf("Максимальная температура:   %d\n", max);
        return max;
    }
}

int compareByTempIncrease(const void* a, const void* b)
{
    const Record* p1 = (const Record*)a;
    const Record* p2 = (const Record*)b;
    
    return p1->temperature - p2->temperature;   // возрастание
    //return p2->temperature - p1->temperature; // убывание
}

int compareByTempDecrease(const void* a, const void* b)
{
    const Record* p1 = (const Record*)a;
    const Record* p2 = (const Record*)b;
    
    //return p1->temperature - p2->temperature;   // возрастание
    return p2->temperature - p1->temperature; // убывание
}

int compareByDateIncrease(const void* a, const void* b)
{
    const Record* p1 = (const Record*)a;
    const Record* p2 = (const Record*)b;
    
    if (p1->year != p2->year)   return p1->year - p2->year;
    if (p1->month != p2->month) return p1->month - p2->month;
    if (p1->day != p2->day)     return p1->day - p2->day;
    if (p1->hour != p2->hour)   return p1->hour - p2->hour;
    return p1->minute - p2->minute;
}

int compareByDateDecrease(const void* a, const void* b)
{
    const Record* p1 = (const Record*)a;
    const Record* p2 = (const Record*)b;
    
    if (p1->year != p2->year)   return p2->year - p1->year;
    if (p1->month != p2->month) return p2->month - p1->month;
    if (p1->day != p2->day)     return p2->day - p1->day;
    if (p1->hour != p2->hour)   return p2->hour - p1->hour;
    return p2->minute - p1->minute;
}

void sortByDateIncrease(Array *arr)
{
    qsort(arr->rec, arr->size, sizeof(Record), compareByDateIncrease);
    
    printf("\nПосле сортировки по возрастанию даты:\n");
    printArray(arr);
}

void sortByDateDecrease(Array *arr)
{
    qsort(arr->rec, arr->size, sizeof(Record), compareByDateDecrease);
    
    printf("\nПосле сортировки по убыванию даты:\n");
    printArray(arr);
}

void sortByTempIncrease(Array *arr)
{
    qsort(arr->rec, arr->size, sizeof(Record), compareByTempIncrease);
    
    printf("\nПосле сортировки по возрастанию температуры:\n");
    printArray(arr);
}

void sortByTempDecrease(Array *arr)
{
    qsort(arr->rec, arr->size, sizeof(Record), compareByTempDecrease);
    
    printf("\nПосле сортировки по убыванию температуры:\n");
    printArray(arr);
}

void initArray(Array *arr)
{
    arr->size = 0;
    arr->capacity = 2;
    arr->rec = (Record*)malloc(arr->capacity * sizeof(Record));

    if (arr->rec == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
}

void addRecord( Array *arr,
                uint16_t year,
                uint8_t month,
                uint8_t day,
                uint8_t hour,
                uint8_t minute,
                int8_t temperature)
{
    if (arr->size >= arr->capacity)
    {
        arr->capacity *= 2;
        Record *newPtr = (Record*)realloc(arr->rec, arr->capacity * sizeof(Record));
        
        if (newPtr == NULL)
        {
            printf("Ошибка расширения памяти realloc! Запись не добавлена");
            return;
        }
        
        arr->rec = newPtr;
    }

    int i = arr->size;
    arr->rec[i].year = year;
    arr->rec[i].month = month;
    arr->rec[i].day = day;
    arr->rec[i].hour = hour;
    arr->rec[i].minute = minute;
    arr->rec[i].temperature = temperature;

    printf("Запись [%d]: %d-%d-%d %d:%d T: %d\n",
        arr->size,
        arr->rec[i].year,
        arr->rec[i].month,
        arr->rec[i].day,
        arr->rec[i].hour,
        arr->rec[i].minute,
        arr->rec[i].temperature = temperature);

    arr->size++;
}

void freeMemory(Array* arr)
{
    free(arr->rec);
}

void readCSV(Array* arr, const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("\nНе удалось открыть файл %s\n", filename);
        return;
    }
    else
    {
        printf("Фаил %s открыт\n", filename);
        printf("Считывание записей:\n");

        char string[512]; // Буфер для хранения одной строки файла

        // Читаю файл построчно
        while (fgets(string, sizeof(string), file) != NULL)
        {
            int y, m, d, h, min, t;
            int stringCounter = sscanf(string, " %d ; %d ; %d ; %d ; %d ; %d", &y, &m, &d, &h, &min, &t);

            if (stringCounter == 6)
            {
                addRecord(arr, y, m, d, h, min, t);
            }
            else
            {
                printf("Пропущена некорректная строка\n");
            }
        }
    }
    fclose(file);
    printf("Записи считаны\n");
    printf("Фаил %s закрыт\n", filename);
}