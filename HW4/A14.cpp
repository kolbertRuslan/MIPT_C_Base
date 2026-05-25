#include <stdio.h>

//A14 Дано трехзначное число, напечатать макисмальную цифру
int main() {
    //int a=435, num1=0, num2=0, num3=0, maxNum=0;
    
    int a=0, num1=0, num2=0, num3=0, maxNum=0;
    scanf("%d", &a);
    
    //отделить каждую цифру
    num1 = a%10;
    num2 = (a/10)%10;
    num3 = (a/100)%10;
    
    //найти максимальную цифру
    if (num1 > num2) maxNum = num1;
    else maxNum = num2;
    if (num3 > maxNum) maxNum = num3;
    
    //printf("%d _ %d _ %d\n", num1, num2, num3);
    printf("%d", maxNum);
    
    return 0;
}