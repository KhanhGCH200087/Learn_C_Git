#include <stdio.h>

int main(void){
    //Bt8: In ra các số chẵn từ 2 đến 20
    for(int i = 2; i <= 20; i++){
        if(i % 2 == 0){
            printf("\n %d", i);
        }
    }
    return 0;
}