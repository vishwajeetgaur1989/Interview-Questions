#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 5;
	void * q=&a;
	printf("%d\n",(int)(*q));
}

