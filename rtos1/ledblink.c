#include "FreeRTOS.h"
#include "task.h"
void task1(void *a)
{
	int i;
while(1)
{
	IO0SET=1<<2;
	vTaskDelay(50);//1s
	
	IO0CLR=1<<2;
	vTaskDelay(50);
}
}
void task2(void *a)
{
	int i;
while(1)
{
	IO0SET=1<<3;
	
	IO0CLR=1<<3;
	
}
}