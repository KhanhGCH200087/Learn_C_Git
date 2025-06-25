#include <stdio.h>
#include <stdlib.h>

//Question 2

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int x, y;
	printf("\nEnter X: ");
	scanf("%d", &x);
	printf("\nEnter Y: ");
	scanf("%d", &y);
	printf("\n\n Value after swap: x = %d, y = %d", x, y);
	swap(&x, &y);
	printf("\n\n Value after swap: x = %d, y = %d", x, y);
	
	
	return 0;
}
