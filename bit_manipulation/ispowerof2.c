#include<stdio.h>

typedef _Bool bool;
bool ispowerof2(int);

int main()
{
	int result,input;
	printf("Enter number :");
	scanf("%d",&input);
	printf("\n");

	result = ispowerof2(input);
	if(result)
		printf("Yes,it's a power of 2\n");
	else
		printf("No,it's not!\n");
	return 0;
}

bool ispowerof2(int x)
{
	int res = ( !(x & (x-1)));
	return res;
}
