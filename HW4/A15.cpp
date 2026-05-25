#include <stdio.h>

//A15 Определить уравнение прямой по координатам двух точек. Уравнение вида y=k*x+b
int main() {
    int x1=6, y1=9, x2=-1, y2=3;
    //int x1=1, y1=2, x2=3, y2=4;
    float k=0.0, b=0.0;
    
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    
    k = (float)(y2 - y1) / (x2 - x1);
    b = y1 - k * x1;
    
    printf("%.2f %.2f", k, b);
    
    return 0;
}