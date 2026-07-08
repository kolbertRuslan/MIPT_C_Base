//F15 Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько
// элементов превосходят по модулю максимальный элемент.
// Прототип функции int count_bigger_abs(int n, int a[]);
// Вход: Функция получает размер массива и массив целых чисел
// Выход: Функция возвращает целое число раное количеству элементов превосходящих по модулю максимальный элемент.

int count_bigger_abs(int n, int a[]) {
    int max = a[0], current = 0, counter = 0;
    
    for (int i = 0; i < n; i++) {
        current = a[i];
        
        if (current > max) max = current;
    }    
    
    
    for (int i = 0; i < n; i++) {
        
        if (a[i]<0) {
            current = a[i] * (-1);
        }
        
        else current = a[i];
        
        if (current > max) counter++;
    }  
        
    return counter;
}