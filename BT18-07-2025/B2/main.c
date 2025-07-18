#include <stdio.h>

struct Motor{
	int speed[5];
};

void motor_highest_speed(struct Motor *motor_Test){
	int highest_speed[5];
	
	int motor_count = 0; 
	for(int i = 0; i < 5; i++){
		int speed = 0;
		for(int j = 0; j < 5; j++){
			if(motor_Test[motor_count].speed[j] > speed){
				speed = motor_Test[motor_count].speed[j];
			}
		}
		highest_speed[motor_count] = speed;
		motor_count++;
	}
	
	int speed_2 = 0;
	int choosen_motor;
	for(int i = 0; i < 5; i++){
		if(highest_speed[i] > speed_2){
			speed_2 = highest_speed[i];
			choosen_motor = i;
		}
	}
	
	printf("\nMotor with highest speed is: %d", choosen_motor);
	for(int i = 0; i < 5; i++){
		printf("\nSpeed %d is %d", i, motor_Test[choosen_motor].speed[i]);
	}
}

void adjustSpeed(struct Motor *motor_Test){
	int motor_count = 0; 
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(motor_Test[motor_count].speed[j] < 1000){
				motor_Test[motor_count].speed[j] = motor_Test[motor_count].speed[j] + motor_Test[motor_count].speed[j] / 10;
			}
		}
		motor_count++;
	}
}

void print_all(struct Motor *motor_Test){
	int motor_count = 0; 
	for(int i = 0; i < 5; i++){
		printf("\nSpeed of motor %d is: ", motor_count);
		for(int j = 0; j < 5; j++){
				printf(" %d ", motor_Test[motor_count].speed[j]);
			}
		motor_count++;
	}
}


int main(){
	struct Motor motor[5];
	for(int i = 0; i < 5; i++){
		printf("\nMotor %d", i);
		for(int j = 0; j < 5; j++){
			printf("\nEnter speed %d: ", j);
			scanf("%d", &motor[i].speed[j]);
		}
	}
	
	motor_highest_speed(&motor);
	
	printf("\nAfter");
	print_all(&motor);
	printf("\nBefore");
	adjustSpeed(&motor);
	print_all(&motor);
	
	return 0;

}