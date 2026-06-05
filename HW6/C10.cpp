//С10 Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа. void print_simple(int n)
// Вход: Целое положительное число

void print_simple(int n) {
    int firstIterationFlag = 1;
    int prostoe_chislo = 2, current = 0, ostatok = 0;

    if (n == 0 || n == 1) {
        printf("%d", n);
    }
    
    else {
        
        while (n > 1) {
            // нахождение простого множителя
            if ( n%prostoe_chislo == 0) {
                n = n / prostoe_chislo;
                printf("%d ", prostoe_chislo);
                continue;
            }
            
            // перейти к следующему простому числу
            if (firstIterationFlag == 1) {
                prostoe_chislo += 1;
                firstIterationFlag = 0;
            }
            else prostoe_chislo += 2;
        }
        
    }
    
}

int main(void) {
    int a = 120;
    
    scanf("%d", &a);
    print_simple(a);

    return 0;
}