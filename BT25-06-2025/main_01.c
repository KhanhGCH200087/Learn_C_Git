#include <stdio.h>
#include <stdlib.h>

//Question 1

void input_arr(int arr[], int index){
	for(int i = 0; i < index; i++){
			printf("\nEnter arr[%d]: ", i);
			scanf("%d", &arr[i]);
	}
}

void print_arr(int arr[], int n){
	printf("\nArray after done input: arr[%d] = {", n);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("}");
}

int sum_arr(int arr[], int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
	}
	printf("\nSum of Array: %d", sum);
	return sum;
}

int main() {
	int condition = 1;
	while(condition){
		int n;
		printf("\n\nEnter n: ");
		scanf("%d", &n);
		if(n >= 1 && n <= 100){
			int arr[n];
		
			input_arr(arr, n);
			
			print_arr(arr, n);
			
			int sum_2 = sum_arr(arr, n);
			
			int average = sum_2 / n;
			
			int count = 0;
			for(int i = 0; i < n; i++){
				if(arr[i] > average){
					count ++;
				}
			}
			printf("\nThere are %d elements are greater then average value of arr[%d], which is %d", count, n, average);
		} else {
			printf("Should enter n >= 1 and n <= 100");
			condition = 0;
		}
	}
	
	return 0;
}