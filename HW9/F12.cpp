// F12 Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
// Input format
// Функция принимает на вход размер массива и массив чисел типа int
// Output format
// Функция не возвращает значения, измененный массив сохраняется на месте исходного.


void change_max_min(int size, int a[]) {
    int max = a[0], min = a[0];
    int minId = 0, maxId = 0;
    
    
    for (int i = 0; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
            maxId = i;
        }
        
        if (a[i] < min) {
            min = a[i];
            minId = i;
        }
    }
    
    int temp = a[maxId];
    a[maxId] = a[minId];
    a[minId] = temp;
    
}