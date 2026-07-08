// F17 Составить функцию которая находит след матрицы в двумерном массиве.
// Показать пример ее работы на матрице из 5 на 5 элементов.
// След матрицы - это сумма элементов на главной диагонали.
// Вход: 25 целых чисел через пробел
// Выход: Одно целое число

#include <stdio.h>

#define SIZE 5

int matrixFunc (int n, int mtx[SIZE][SIZE]) {
    int sum = 0;
    
    for (int i=0; i < n; i++) {
        sum += mtx[i][i];    
    }
    
    return sum;
}



int main() {
    int matrix[SIZE][SIZE];
    
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf ("%d", matrixFunc(SIZE, matrix));
    
    return 0;
}