#include <stdio.h>

int main(void){
    //Bt3: Xác định mức pin và hiển thị thông báo tương ứng (Thấp, Trung bình, Cao).
    int battery;
    printf("Enter battery status: ");
    scanf("%d", &battery);
    if(battery <= 20 && battery >= 0){
        printf("\n LOW");
    } else if (battery >= 21 && battery <= 40){
        printf("\n Standard");
    } else if (battery >= 41 && battery <= 100){
        printf("\n High");
    }
    
    return 0;
}