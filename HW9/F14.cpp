// F14 Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
// Прототип функции int sum_between_ab(int from, int to, int size, int a[])
// Формат входных данных Функция принимает концы отрезка from и to, размер массива, массив целых чисел
// Формат результата Функция возвращает сумму элементов в интервале [from, to]

int sum_between_ab(int from, int to, int size, int a[]) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        
        if (from > to) {
        int temp = from;
        from = to;
        to = temp;
    }
    
        if (a[i] >= from && a[i] <= to) {
            
            sum += a[i];
        }
    }
    
    return sum;
}