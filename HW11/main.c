
#include "temp_api.h"

struct temp {
    uint16_t year;      // dddd - год 4 цифры
    char month[3];      // mm - месяц 2 символа
    uint8_t day;        // dd - день 2 цифры
    uint8_t hour;       // hh - часы 2 цифры
    uint8_t minute;     // mm - минуты 2 цифры
    int8_t temperature; // temperature - целое число от -99 до 99
};


int main () {
getchar(); 
return 0;
}