#include <stdio.h>

int main(void){
    //Bai1: Kiểm tra nhiệt độ và bật/tắt đèn LED tương ứng.
    int temp;
    printf("Enter temperature: ");
    scanf("%d", &temp);
    if(temp >= 10 && temp <= 25){
        printf("\nLed level 1");
    } else if (temp >= 26 && temp <= 30){
        printf("\nLed level 2");
    } else {
        printf("\n Led level 0");
    }
    return 0;
}

//Bài thầy chữa
/* #include <stdio.h>

int main(void){
    int temp = 0;
    printf("Enter temperature: ");
    scanf("%d", &temp);
    if(temp < 0 || temp > 50){
        printf("\nWarning temperature");
    } else if((temp >= 0 && temp <= 15) || (temp>= 30 && temp <= 50)){
        printf("\nTurn off Light");
    } else if(temp >= 15 && temp <= 30){
        printf("\n Turn on light");
    }
    return 0;
} */
