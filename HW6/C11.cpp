#include <stdio.h>

//С11 Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования. int nod(int a, int b)
// Вход: Два целых положительных числа

// Разделите большее число на меньшее с остатком.Если остаток равен нулю, то меньшее число и есть НОД.
// Если остаток не равен нулю, замените большее число на меньшее, а меньшее — на остаток.
// Повторяйте шаги до тех пор, пока остаток не станет равен нулю. Последний ненулевой остаток — это НОД.

int nod(int a, int b) {
   int max = 0, min = 0, ostatok = 0;
   
   if ( a == 0 || b == 0) return 0;
   
   if (a>b) {
       max = a;
       min = b;
   }
   else {
       max = b;
       min = a;
   }
   
   ostatok = max%min;
   
   if (ostatok == 0) return min;
   else {
       while (ostatok != 0) {
           max = min;
           min = ostatok;
           ostatok = max%min;
       }
    return min;
   }
}

int main(void) {
    int a = 14, b = 21;
    
    scanf("%d%d", &a, &b);
    printf("%d", nod(a, b) );

    return 0;
}