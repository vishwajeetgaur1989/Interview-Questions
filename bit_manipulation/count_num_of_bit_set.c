#include<stdio.h>
typedef unsigned int uint32_t;

void print_bit(uint32_t a)
{
	printf("Binary output: ");
	for(int i=0;i<32;i++)
	{
		printf("%d",((a&0x80000000)>>31));
		a<<=1;
	}
	printf("\n");
}
int count_bit_set(uint32_t a)
{
	int count = 0;
	for(int i=0;i<32;i++)
	{
		if((a&0x01)&1)
			count++;
		a>>=1;
	}
	return count;
}
int main()
{
	uint32_t val,count;
	printf("Enter the value of integer to see number of bit set\n");
	scanf("%d",&val);
	print_bit(val);
	count=count_bit_set(val);
	printf("Number of bit set = %d\n",count);
	return 0;
}
