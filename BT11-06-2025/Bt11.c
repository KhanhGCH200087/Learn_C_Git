#include <stdio.h>

int main(void){
    //Bt11: Đo 10 lần nhiệt độ và tính trung bình
    int sum = 0;
    int x = 0;
    int count = 1;
    while (count <= 10){
        printf("Enter x: ");
        scanf("%d", &x);
        sum = sum + x;
        count++;
    }
    float result = sum / 10 * 1.0;
    printf("Final result: %f", result);
    return 0;
}
