#include <stdio.h>

int main(void){
    //Bt2: Kiểm tra điện áp đầu vào và hiển thị trạng thái 'Ổn định' hoặc 'Cảnh báo'.
    float input_voltage;
    printf("Enter input voltage: ");
    scanf("%f", &input_voltage);
    if(input_voltage <= 6 && input_voltage >= 5 ){
        printf("\nStable");
    } else if(0 <= input_voltage && input_voltage < 5){
        printf("\nDanger");
    }
    
    return 0;
}