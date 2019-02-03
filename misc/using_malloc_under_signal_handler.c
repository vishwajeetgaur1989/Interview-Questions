#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void handler()
{
	printf("Im into handler\n");
	int * ptr =(int *)malloc(sizeof(int));
	*ptr = 10;
	printf("Malloc done value at ptr = %d\n",*ptr);
}
int main()
{
	signal(SIGINT,handler);
	while(1);
	return 0;
}
