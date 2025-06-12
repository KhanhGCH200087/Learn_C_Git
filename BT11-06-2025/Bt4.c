#include <stdio.h>

int main(void){
    //Bt4: Bật quạt làm mát nếu nhiệt độ vượt ngưỡng cho phép.
    int input_temperature;
    printf("Enter temperature: ");
    scanf("%d", &input_temperature);
    if(input_temperature >= 30){
        printf("\n Turn on Fan");
    } else {
        printf("\n It is not that Hot");
    }
    
    return 0;
}