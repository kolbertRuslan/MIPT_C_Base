#include "temp_api.h"

void printHelp(void)
{
    printf("\nДомашнее задание №12\n");
    printf("Выполнил: Кольберт Руслан\n\n");
    printf("Команды для терминала VS Code:\n\n");
    printf("mingw32-make            собрать проект\n");
    printf(".\\prog.exe -h           показать справку\n");
    printf(".\\prog.exe -m 1         статистика только за указанный месяц\n");
    printf(".\\prog.exe -m 2\n");
    printf(".\\prog.exe -m 3\n");
    printf(".\\prog.exe -f data.csv  читать данные из CSV файла\n");
}

void printArray(const struct temp data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%4u-%02u-%02u %02u:%02u %4d\n",
               data[i].year,
               data[i].month,
               data[i].day,
               data[i].hour,
               data[i].minute,
               data[i].temperature);
    }
}

int avgMonthTemp(const struct temp data[], int size, uint8_t month)
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i].month == month)
        {
            sum += data[i].temperature;
            count++;
        }
    }

    if (count == 0)
        return 0;

    return sum / count;
}

int minMonthTemp(const struct temp data[], int size, uint8_t month)
{
    int found = 0;
    int min = 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i].month == month)
        {
            if (!found)
            {
                min = data[i].temperature;
                found = 1;
            }
            else if (data[i].temperature < min)
            {
                min = data[i].temperature;
            }
        }
    }

    return min;
}

int maxMonthTemp(const struct temp data[], int size, uint8_t month)
{
    int found = 0;
    int max = 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i].month == month)
        {
            if (!found)
            {
                max = data[i].temperature;
                found = 1;
            }
            else if (data[i].temperature > max)
            {
                max = data[i].temperature;
            }
        }
    }

    return max;
}

int avgYearTemp(const struct temp data[], int size)
{
    int sum = 0;

    if (size == 0)
        return 0;

    for (int i = 0; i < size; i++)
        sum += data[i].temperature;

    return sum / size;
}

int minYearTemp(const struct temp data[], int size)
{
    if (size == 0)
        return 0;

    int min = data[0].temperature;

    for (int i = 1; i < size; i++)
    {
        if (data[i].temperature < min)
            min = data[i].temperature;
    }

    return min;
}

int maxYearTemp(const struct temp data[], int size)
{
    if (size == 0)
        return 0;

    int max = data[0].temperature;

    for (int i = 1; i < size; i++)
    {
        if (data[i].temperature > max)
            max = data[i].temperature;
    }

    return max;
}

void sortByDate(struct temp data[], int size)
{
    struct temp temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (
                (data[j].year > data[j + 1].year) ||

                (data[j].year == data[j + 1].year &&
                 data[j].month > data[j + 1].month) ||

                (data[j].year == data[j + 1].year &&
                 data[j].month == data[j + 1].month &&
                 data[j].day > data[j + 1].day) ||

                (data[j].year == data[j + 1].year &&
                 data[j].month == data[j + 1].month &&
                 data[j].day == data[j + 1].day &&
                 data[j].hour > data[j + 1].hour) ||

                (data[j].year == data[j + 1].year &&
                 data[j].month == data[j + 1].month &&
                 data[j].day == data[j + 1].day &&
                 data[j].hour == data[j + 1].hour &&
                 data[j].minute > data[j + 1].minute)
               )
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void sortByTempIncrease(struct temp data[], int size)
{
    struct temp temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (data[j].temperature > data[j + 1].temperature)
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void sortByTempDecrease(struct temp data[], int size)
{
    struct temp temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (data[j].temperature < data[j + 1].temperature)
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void addRecord(struct temp data[], int *size,
               uint16_t year,
               uint8_t month,
               uint8_t day,
               uint8_t hour,
               uint8_t minute,
               int8_t temperature)
{
    data[*size].year = year;
    data[*size].month = month;
    data[*size].day = day;
    data[*size].hour = hour;
    data[*size].minute = minute;
    data[*size].temperature = temperature;

    (*size)++;
}