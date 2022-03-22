#include "header.h"
	SemaphoreHandle_t b;
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
	}
	
}
}