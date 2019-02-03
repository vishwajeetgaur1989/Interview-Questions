#include<stdio.h>
#include<stdlib.h>

int main()
{
	char i =0;
//	const char volatile *  ptr1="Hello_world"; //here address is volatile but value is const
//	ptr1 = &i;	// <------------- so this change will happen.
//	*(ptr1) ="Myworld";//<----------- this change will not happen.
	volatile char const *  ptr2="Hello_world"; //here address is const but value is volatile
//	ptr2 = &i; //<-------------------this will not happen
	ptr2 = &i; 
	printf("value %s\n",*ptr2);
	return 0;
}
