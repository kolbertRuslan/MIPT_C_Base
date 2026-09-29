#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    uint16_t year;      // dddd - год 4 цифры
    uint8_t month;      // mm - месяц 2 символа
    uint8_t day;        // dd - день 2 цифры
    uint8_t hour;       // hh - часы 2 цифры
    uint8_t minute;     // mm - минуты 2 цифры
    int8_t temperature; // temperature - целое число от -99 до 99
} Record;

typedef struct {
    Record *rec;     // Указатель на массив структур
    int size;        // Текущее количество элементов
    int capacity;    // Выделенная емкость массива
} Array;


void printHelp(void);
void printArray(const Array* arr);

int avgMonthTemp(const Array* arr, uint8_t month);
int minMonthTemp(const Array* arr, uint8_t month);
int maxMonthTemp(const Array* arr, uint8_t month);

int avgYearTemp(const Array* arr, uint16_t year);
int minYearTemp(const Array* arr, uint16_t year);
int maxYearTemp(const Array* arr, uint16_t year);

int compareByTempIncrease(const void* a, const void* b);
int compareByTempDecrease(const void* a, const void* b);
int compareByDateIncrease(const void* a, const void* b);
int compareByDateDecrease(const void* a, const void* b);

void sortByDateIncrease(Array *arr);
void sortByDateDecrease(Array *arr);
void sortByTempIncrease(Array *arr);
void sortByTempDecrease(Array *arr);

void initArray(Array *arr);

void addRecord( Array *arr,
                uint16_t year,
                uint8_t month,
                uint8_t day,
                uint8_t hour,
                uint8_t minute,
                int8_t temperature);

void freeMemory(Array* arr);

void readCSV(Array* arr, const char *filename);


#endif