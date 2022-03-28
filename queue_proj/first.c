#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
void display(const char *);
void trans(char a);
SemaphoreHandle_t m;
xQueueHandle q;

void task1(void *); //declaration
void task2(void *); 

int main()
{m=xSemaphoreCreateMutex();
	q=xQueueCreate(5,sizeof(char));
	PINSEL0=1|1<<2;//uart
	U0LCR=0x83;
	U0DLL=98;
	U0DLM=0;
	U0FDR=1<<4;
	U0LCR=0x03;//uart
	PINSEL1=0;
	IO0DIR=0;
	IO1DIR=~0;
	xTaskCreate(task1,"t1",90,NULL,1,NULL);
	xTaskCreate(task2,"t2",90,NULL,1,NULL);
	vTaskStartScheduler();
	while(1);
}
	
void trans(char a)
{
while((U0LSR&(1<<5))==0);
U0THR=a;

}
void display(const char *a)
{
	while(*a)
	{
	trans(*a++);
	}
}
void task1(void *a)//send q
{

while(1)
{
	char i;
if((IO0PIN&(1<<12))==(1<<12))
		{
	i++;
			display("\rSending to queue\r");
		if(xQueueSend(q,&i,1000))
		{
			if(xSemaphoreTake(m,3000)==1)
			{
			display("\rSuccess\r");
				xSemaphoreGive(m);	
			}
		}
		else
		{
					if(xSemaphoreTake(m,3000)==1)
			{
			display("\rFailed to write\r");
					xSemaphoreGive(m);	
			}
		}
		while((IO0PIN&(1<<12))==(1<<12));
	
	}
}
}
void task2(void *a)
{
	char i;
while(1)
{
	if((IO0PIN&(1<<11))==(1<<11))
	{
			display("\rReading from queue\r");
		
		if(xQueueReceive(q,&i,100))
		{
					if(xSemaphoreTake(m,3000)==1)
			{
			display("\rSuccessfully read\r");
			trans(i);
				xSemaphoreGive(m);	
			}
		}
		else
		{
				if(xSemaphoreTake(m,3000)==1)
			{
			display("\rFailed  to read\r");
								xSemaphoreGive(m);
			}
		}
		while((IO0PIN&(1<<11))==(1<<11));
	}
	
}
}