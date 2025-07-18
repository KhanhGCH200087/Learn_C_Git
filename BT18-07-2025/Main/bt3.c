#include <stdio.h>
#include <stdlib.h>

struct TechnicalSpec{
	float op_voltage;
	float cur_consumption;
	int op_time;
};

struct Device{
	char device_id[10];
	int status;
	struct TechnicalSpec tech;
};

void check_status_n(int *status, int *check){
	if(*status == 0 || *status == 1){
		*check = 0;
	} else {
		printf("\nEnter 1 or 0: ");
		*check = 1;
	}
}

void check_hour(int *hour, int *check){
	if(*hour >= 0 && *hour <= 24){
		*check = 0;
	} else {
		printf("\nEnter from 0 to 24 hours: ");
		*check = 1;
	}
}

void intput_device(struct Device *device, int number){
	for(int i = 0; i < number; i++){
		printf("\nEnter device %d", i);
		
		printf("\nEnter ID: ");
		scanf("%s", &device[i].device_id);
		
		int check_status = 1;
		while(check_status){
			printf("\nEnter status: ");
			scanf("%d", &device[i].status);
			int av_status = device[i].status;
			check_status_n(&av_status, &check_status);
		}
		
		printf("\nEnter operating voltage: ");
		scanf("%f", &device[i].tech.op_voltage);
		
		printf("\nEnter current consumption: ");
		scanf("%f", &device[i].tech.cur_consumption);

		int check_hours = 1;
		while(check_hours){
			printf("\nEnter operating time during the day: ");
			scanf("%d", &device[i].tech.op_time);
			int hour = device[i].tech.op_time;
			check_hour(&hour, &check_hours);
		}
		
	} 
}

void calculate_consumption(struct Device *device, int number, float *device_consum){
	for(int i = 0; i < number; i++){
		float P = device[i].tech.cur_consumption * device[i].tech.op_voltage * (device[i].tech.op_time * 60 * 1.0);
		device_consum[i] = P;
	}
}

void print_1_device(struct Device *device, int number){
	printf("\nDevice ID: %s", device[number].device_id);
	
	int status = device[number].status;
	if(status == 0){
		printf("\nStatus: Inactive");
	} else if(status == 1){
		printf("\nStatus: Active");
	}

	printf("\nOperating voltage: %f", device[number].tech.op_voltage);
	
	printf("\nCurrent consumption: %f", device[number].tech.cur_consumption);

	printf("\nOperating time during the day: %d", device[number].tech.op_time);
}

int main() {
	int number;
	printf("Enter number of device: ");
	scanf("%d", &number);
	
	struct Device device[number];
	float device_consumption[number];
	
	intput_device(&device, number);
	
	printf("\n***********");

	printf("\nList of device");
	for(int i = 0; i < number; i++){
		print_1_device(&device, i);
	}
	
	printf("\n***********");

	calculate_consumption(&device, number, &device_consumption);
	printf("\nActive devices with consumption greater than 1000 Wh");
	for(int i = 0; i < number; i++){
		if(device_consumption[i] > 1000 && device[i].status == 1){
			printf("\nDevice number: %d", i);
			print_1_device(&device, i);
			printf("\n Device consumption: %f", device_consumption[i]);
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}






