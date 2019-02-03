#include<stdio.h>
#include<stdarg.h>
int func(int num,...)
{
	int count = 0;
	va_list vlist;
	va_start(vlist,num);
	for(int i=0;i<num;i++)
		count += va_arg(vlist,int);
	va_end(vlist);
	return count;
}

int main()
{
	printf("sum of 1,2,3,4,5,6 =  %d\n",func(6,1,2,3,4,5,6));
	return 0;
}
