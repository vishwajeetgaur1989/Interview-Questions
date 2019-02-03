#include<stdio.h>

void print_binary(unsigned int);
int swap_bit(int,int,int);
int main()
{
	unsigned int val;
	int x1,x2;
	scanf("%d",&val);
	print_binary(val);
	printf("Enter bit position 1 & 2 \n");
	scanf("%d %d",&x1,&x2);
	val = swap_bit(val,x1,x2);
	print_binary(val);
	return 0;
}
int swap_bit(int a,int x1,int x2)
{
	int ch1,ch2,xor,result;
	ch1 = (a>>x1) & 0x01; //get the input variable to LSB for X1
	ch2 = (a>>x2) & 0x01; //get the input variable to LSB for X2
	xor = ch1^ch2;	     // perform the xor of the input	
	xor = (xor << x1) | (xor << x2);
	result = (a ^ xor);
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
