#include <stdio.h>

//A17 Ввести номер месяца и вывести название времени года
int main() {
    int month=4;
    
    scanf("%d", &month);
    
    switch (month) {
        case 1: printf("winter");
            break;
        case 2: printf("winter");
            break;
        case 3: printf("spring");
            break;
        case 4: printf("spring");
            break;
        case 5: printf("spring");
            break;
        case 6: printf("summer");
            break;
        case 7: printf("summer");
            break;
        case 8: printf("summer");
            break;
        case 9: printf("autumn");
            break;
        case 10: printf("autumn");
            break;
        case 11: printf("autumn");
            break;
        case 12: printf("winter");
            break;
        default: printf("incorrect value");
    }
    
    return 0;
}