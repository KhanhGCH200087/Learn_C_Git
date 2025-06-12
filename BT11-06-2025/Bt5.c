#include <stdio.h>

int main(void){
    //Bt5: Chuyển đổi chế độ hoạt động của thiết bị dựa vào nút nhấn.
    int button;
    printf("Enter button status 1 or 0: ");
    scanf("%d", &button);
    if(button == 0){
        printf(" --> OFF");
    } else if(button == 1){
        printf(" --> ON");
    }
    
    return 0;
}