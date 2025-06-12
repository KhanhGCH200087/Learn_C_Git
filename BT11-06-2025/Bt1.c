#include <stdio.h>

int main(void){
    //Bai1: Kiểm tra nhiệt độ và bật/tắt đèn LED tương ứng.
    int temp;
    printf("Enter temperature: ");
    scanf("%d", &temp);
    if(10 <= temp <= 25){
        printf("\nLed level 1");
    } else if (26 <= temp <= 30){
        printf("\nLed level 2");
    } else {
        printf("\n Led level 0");
    }
    
    return 0;
}