#include<stdio.h>

void print_binary(unsigned int);
int inverse_bit(int);
int main()
{
	unsigned int val;
	scanf("%d",&val);
	print_binary(val);
	val = inverse_bit(val);
	print_binary(val);
	return 0;
}
int inverse_bit(int a)
{
	int result = 0;
	for(int i =0;i<31;i++)
	{
		result |=(a&0x01);
		a>>=1;
		result<<=1;
	}
	return result;
}
void print_binary(unsigned int a)
{
	for(int i=0;i<32;i++)
	{
		printf("%d",(a&0x80000000)>>31);
		a <<=1;
	}
	printf("\n");
}
