#include<stdio.h>
int length(char * str)
{
	int i = 0;
	while(*(str+i))
	{
		i++;
	}
	return i;
}
