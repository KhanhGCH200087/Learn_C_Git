#include <stdio.h>

int main(void){
    //Bt12: Chớp tắt LED 10 lần với khoảng dừng
    
    for(int i = 0; i <= 10; i++){
        printf("\nLed ON ");
        for(int j = 0; j<= 5; j++){
            printf("%d ", j);
            printf("\a");
        }
        printf("\nLed OFF ");
        for(int k = 0; k<= 5; k++){
            printf("%d ", k);
            printf("\a");
        }
    }
    return 0;
}