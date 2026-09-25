/*
    Курсовая работа
    Выполнил: Кольберт Руслан
*/


//#include "temp_api.h"
#include <stdint.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct
{
    uint16_t year;      // dddd - год 4 цифры
    uint8_t month;      // mm - месяц 2 символа
    uint8_t day;        // dd - день 2 цифры
    uint8_t hour;       // hh - часы 2 цифры
    uint8_t minute;     // mm - минуты 2 цифры
    int8_t temperature; // temperature - целое число от -99 до 99
} Temperature;

void printHelp(void)
{
    printf("\nКурсовая работа\n");
    printf("Выполнил: Кольберт Руслан\n\n");
    printf("Команды для терминала VS Code:\n\n");
    printf("mingw32-make            собрать проект\n");
    printf(".\\prog.exe -h           показать справку\n");
    printf(".\\prog.exe -m 1         статистика только за указанный месяц\n");
    printf(".\\prog.exe -m 2\n");
    printf(".\\prog.exe -m 3\n");
    printf(".\\prog.exe -f data.csv  читать данные из CSV файла\n");
}

void printArray(const Temperature* data_ptr, int arr_size)
{
    printf("Стр\tГод\t\tМес\tДн\tЧас\tМин\tТемп\n");
    for (int i=0; i<arr_size; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            i,
            (data_ptr + i) ->year,
            data_ptr[i].month,
            data_ptr[i].day,
            data_ptr[i].hour,
            data_ptr[i].minute,
            data_ptr[i].temperature);
    }
}

int avgMonthTemp(const Temperature* data_ptr, int arr_size, uint8_t month)
{
    int sum = 0;
    float avg;
    int count = 0;

    for (int i=0; i<arr_size; i++)
    {
        if ((data_ptr+i)->month == month)
        {
            sum += (data_ptr+i)->temperature;
            count++;
        }
    }

    if (count == 0)
    {
        printf("\nНет данных за месяц %d\n", month);
    }
    else 
    {
        avg = (float)sum / count;
        //printf("sum %d\n", sum);
        //printf("count %d\n", count);
        printf("\nСредняя температура за месяц %d: %.1f\n", month, avg);
    }

    return avg;
}

int minMonthTemp(const Temperature* data_ptr, int arr_size, uint8_t month)
{
    int min;
    int count = 0;
    int init_flag = 0;

    for (int i=0; i<arr_size; i++)
    {
        if ((data_ptr+i)->month == month)
        {
            if (!init_flag)
            {
                min = (data_ptr+i)->temperature;
                init_flag = 1;
            }
            else  if ((data_ptr+i)->temperature < min)
            {
                min = (data_ptr+i)->temperature;
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
        printf("\nМинимальная температура за месяц %d: %d\n", month, min);
    }

    return min;
}

int maxMonthTemp(const Temperature* data_ptr, int arr_size, uint8_t month)
{
    int max;
    int count = 0;
    int init_flag = 0;

    for (int i=0; i<arr_size; i++)
    {
        if ((data_ptr+i)->month == month)
        {
            if (!init_flag)
            {
                max = (data_ptr+i)->temperature;
                init_flag = 1;
            }
            else  if ((data_ptr+i)->temperature > max)
            {
                max = (data_ptr+i)->temperature;
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
        printf("\nМаксимальная температура за месяц %d: %d\n", month, max);
    }

    return max;
}

int avgYearTemp(const Temperature* data_ptr, int arr_size, uint16_t year)
{
    int sum = 0;
    float avg;
    int count = 0;

    for (int i=0; i<arr_size; i++)
    {
        if ((data_ptr+i)->year == year)
        {
            sum += (data_ptr+i)->temperature;
            count++;
        }
    }

    if (count == 0)
    {
        printf("\nНет данных за год %d\n", year);
    }
    else 
    {
        avg = (float)sum / count;
        //printf("sum %d\n", sum);
        //printf("count %d\n", count);
        printf("\nСредняя температура за год %d: %.1f\n", year, avg);
    }

    return avg;
}

int minYearTemp(const Temperature* data_ptr, int arr_size, uint16_t year)
{
    int min;
    int count = 0;
    int init_flag = 0;

    for (int i=0; i<arr_size; i++)
    {
        if ((data_ptr+i)->year == year)
        {
            if (!init_flag)
            {
                min = (data_ptr+i)->temperature;
                init_flag = 1;
            }
            else  if ((data_ptr+i)->temperature < min)
            {
                min = (data_ptr+i)->temperature;
            }

            count++;
        }
    }

    if (count == 0)
    {
        printf("\nНет данных за год %d\n", year);
    }
    else 
    {
        printf("\nМинимальная температура за год %d: %d\n", year, min);
    }

    return min;
}

int maxYearTemp(const Temperature* data_ptr, int arr_size, uint16_t year)
{
    int max;
    int count = 0;
    int init_flag = 0;

    for (int i=0; i<arr_size; i++)
    {
        if ((data_ptr+i)->year == year)
        {
            if (!init_flag)
            {
                max = (data_ptr+i)->temperature;
                init_flag = 1;
            }
            else  if ((data_ptr+i)->temperature > max)
            {
                max = (data_ptr+i)->temperature;
            }

            count++;
        }
    }

    if (count == 0)
    {
        printf("\nНет данных за год %d\n", year);
    }
    else 
    {
        printf("\nМаксимальная температура за год %d: %d\n", year, max);
    }

    return max;
}

int compareByTempIncrease(const void* a, const void* b) 
{
    const Temperature* p1 = (const Temperature*)a;
    const Temperature* p2 = (const Temperature*)b;
    
    return p1->temperature - p2->temperature;   // возрастание
    //return p2->temperature - p1->temperature; // убывание
}

int compareByTempDecrease(const void* a, const void* b) 
{
    const Temperature* p1 = (const Temperature*)a;
    const Temperature* p2 = (const Temperature*)b;
    
    //return p1->temperature - p2->temperature;   // возрастание
    return p2->temperature - p1->temperature; // убывание
}

int compareByDate(const void* a, const void* b) 
{
    const Temperature* p1 = (const Temperature*)a;
    const Temperature* p2 = (const Temperature*)b;
    
    if (p1->year != p2->year)   return p1->year - p2->year;
    if (p1->month != p2->month) return p1->month - p2->month;
    if (p1->day != p2->day)     return p1->day - p2->day;
    if (p1->hour != p2->hour)   return p1->hour - p2->hour;
    return p1->minute - p2->minute;
}

void sortByDate(Temperature* data, int arr_size)
{
    qsort(data, arr_size, sizeof(Temperature), compareByDate);
    
    printf("\nПосле сортировки по убыванию даты:\n");
    printArray(data, arr_size);
}

void sortByTempIncrease(Temperature* data, int arr_size)
{
    qsort(data, arr_size, sizeof(Temperature), compareByTempIncrease);
    
    printf("\nПосле сортировки по возрастанию температуры:\n");
    printArray(data, arr_size);
}

void sortByTempDecrease(Temperature* data, int arr_size)
{
    qsort(data, arr_size, sizeof(Temperature), compareByTempDecrease);
    
    printf("\nПосле сортировки по убыванию температуры:\n");
    printArray(data, arr_size);
}

void addRecord( Temperature* data,
                int *size,
                uint16_t year,
                uint8_t month,
                uint8_t day,
                uint8_t hour,
                uint8_t minute,
                int8_t temperature)
{
    //printf("\nВедите данные через пробел: год месяц день час минута температура\n");
    data[*size].year = year;
    data[*size].month = month;
    data[*size].day = day;
    data[*size].hour = hour;
    data[*size].minute = minute;
    data[*size].temperature = temperature;

    (*size)++;

    printArray(data, *size);
}


//============= MAIN =============
int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    
    //printHelp();
    
    Temperature data[] =
    {
        {2024, 1, 1,  0,  0,   -10},
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

    int arr_size = sizeof(data) / sizeof(data[0]);
    //printf("размер массива  %d\n", arr_size);
    
    printArray(data, arr_size);

    //avgMonthTemp(data, arr_size, 2);
    //minMonthTemp(data, arr_size, 2);
    //maxMonthTemp(data, arr_size, 2);

    //avgYearTemp(data, arr_size, 2024);
    //minYearTemp(data, arr_size, 2024);
    //maxYearTemp(data, arr_size, 2024);

    sortByDate(data, arr_size);
    //sortByTempIncrease(data, arr_size);
    //sortByTempDecrease(data, arr_size);
    
    addRecord(data, &arr_size, 2024, 4, 1, 12, 0, 15);
    

    //getchar(); // Ждет нажатия Enter
    return 0;
}
