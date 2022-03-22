#include "FreeRTOS.h"
#include "task.h"
void task1(void *); //declaration
void task2(void *); 
int main()
{
	PINSEL0=0;
	
	IO0DIR=1<<2|1<<3;
	xTaskCreate(task1,"t1",90,NULL,1,NULL);
	xTaskCreate(task2,"t2",90,NULL,0,NULL);
	vTaskStartScheduler();
	while(1);
}
	
