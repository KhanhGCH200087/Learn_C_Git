#include <stdio.h>
#include <stdlib.h>

int main(){
	float temp[10];
	for(int i = 0; i < 10; i++){
		printf("\nEnter temperature %d: ", i);
		scanf("%f", &temp[i]);
	}
	for(int i = 0; i < 10; i++){
		if(temp[i] > 50){
			printf("\nTemperature is over 50 is %f", temp[i]);
		}
	}
	int count = 0;
	float low_temp = 0.0;
	for(int i = 0; i < 10; i++){
		if(temp[i] < 50){
			low_temp += temp[i];
			count ++;
		}
	}
	
	float result = low_temp / (count * 1.0);
	printf("\nAverage temp below 50 is %f", result);
	
	return 0;
	
}