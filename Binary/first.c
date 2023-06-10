#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


SemaphoreHandle_t b;
	void task1(void *); //declaration
void task2(void *); 

int main()
{
b=xSemaphoreCreateBinary();
	PINSEL0=0;

	IO1DIR=0xff<<16;//output
	IO0DIR=0;//Input
	xTaskCreate(task1,"t1",90,NULL,1,NULL);
	xTaskCreate(task2,"t2",90,NULL,1,NULL);
	vTaskStartScheduler();
	while(1);
}
	void task1(void *a)
{
	int i;
while(1)
{
if(xSemaphoreTake(b,100))
{
	IO1SET=0xf<<16;
	vTaskDelay(50);//1s
	
	IO1CLR=0xf<<16;
	vTaskDelay(50);
}
	IO1SET=0xf<<20;
	vTaskDelay(50);//1s
	
	IO1CLR=0xf<<20;
	vTaskDelay(50);
}
}
void task2(void *a)
{
	int i;
while(1)
{
	if((IO0PIN&(1<<12))==(1<<12))
	{
		xSemaphoreGive(b);
		while((IO0PIN&(1<<12))==(1<<12));
	}
	
}
}
