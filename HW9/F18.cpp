// F18 Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм вычисления суммы максимальных элементов из каждой строки. Напечатать значение этой суммы. Предполагается, что в каждой строке такой элемент единственный. Реализовать функцию поиска максимума в строке из 10 элементов
// Вход: 10 строк состоящих из 10 целых чисел через пробел.
// Выход: Одно целое число

#include <stdio.h>

#define SIZE 10

int findMax (int i, int n, int mtx[SIZE][SIZE]) {
    int max = mtx[i][0];
    
    for (int j=0; j<n; j++) {
        if (mtx[i][j] > max) max = mtx[i][j];
    }
    
    return max;
}



int main() {
    int matrix[SIZE][SIZE];
    int sum=0; int nomerStroki = 0;
    
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (nomerStroki; nomerStroki < SIZE; nomerStroki++) {
        sum += findMax(nomerStroki, SIZE, matrix);
    }
    
    printf ("%d", sum);
    
    return 0;
}