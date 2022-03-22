#include<lpc213x.h>
void main()
{
	int i;
	PINSEL0=0;
	IO0DIR=1<<2|1<<3;
	while(1)
	{
		IO0SET=1<<2;
		for(i=0;i<=100000;i++);//1s
		IO0CLR=1<<2;
		for(i=0;i<=100000;i++);//1s
	}
}