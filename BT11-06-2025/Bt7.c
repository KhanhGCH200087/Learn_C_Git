#include <stdio.h>

int main(void){
    //Bt7: Tính tổng các số từ 1 đến 10
    int sum = 0;
    for(int i = 0; i <= 10; i++){
        sum = sum + i;
    }
    printf("Sum of 1 to 10: %d", sum);
    
    return 0;
}