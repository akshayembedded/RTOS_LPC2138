#include "FreeRTOS.h"
#include "task.h"
void task1(void *a)
{
	int i;
while(1)
{
	IO0SET=0x4;
	for(i=0;i<=100000;i++);
	
	IO0CLR=0x4;
	for(i=0;i<=100000;i++);
}
}
void task2(void *a)
{
	int i;
while(1)
{
	IO0SET=0x8;
	for(i=0;i<=100000;i++);
	
	IO0CLR=0x8;
	for(i=0;i<=100000;i++);
	
}
}