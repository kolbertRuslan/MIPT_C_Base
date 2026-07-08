// F13 Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива.
// Прототип функции int count_between(int from, int to, int size, int a[])
// Формат входных данных: Функция принимает значения концов отрезка from и to, размер массива, массив целых чисел.
// Формат результата: Функция возвращает целое число - количество числе в интервале [from, to]

int count_between(int from, int to, int size, int a[]) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (a[i] >= from && a[i] <= to) {
            count++;
        }
    }
    
    return count;
}