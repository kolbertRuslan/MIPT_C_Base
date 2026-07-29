#include <stdint.h>
#include <stdio.h>

struct temp {
    uint16_t year;      // dddd - год 4 цифры
    uint8_t month;      // mm - месяц 2 символа
    uint8_t day;        // dd - день 2 цифры
    uint8_t hour;       // hh - часы 2 цифры
    uint8_t minute;     // mm - минуты 2 цифры
    int8_t temperature; // temperature - целое число от -99 до 99
};

void printHelp(void);

void printArray(const struct temp data[], int size);

int avgMonthTemp(const struct temp data[], int size, uint8_t month);
int minMonthTemp(const struct temp data[], int size, uint8_t month);
int maxMonthTemp(const struct temp data[], int size, uint8_t month);

int avgYearTemp(const struct temp data[], int size);
int minYearTemp(const struct temp data[], int size);
int maxYearTemp(const struct temp data[], int size);

void sortByDate(struct temp data[], int size);

void sortByTempIncrease(struct temp data[], int size);
void sortByTempDecrease(struct temp data[], int size);

void addRecord(struct temp data[], int *size,
               uint16_t year,
               uint8_t month,
               uint8_t day,
               uint8_t hour,
               uint8_t minute,
               int8_t temperature);