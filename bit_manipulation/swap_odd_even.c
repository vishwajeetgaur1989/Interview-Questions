#include<stdio.h>

void print_bit_pattern(unsigned char);
int main()
{
	int choice,pos,x,y;
	unsigned char input = '\0',out;
	unsigned int i; 
	printf("Enter the value : ");
	scanf("%c",&input);
	
	//input =(char)i;
	printf("\n");
	printf("Input  :");
	print_bit_pattern(input);
	out = (0x00|(input>>1))|(0x00|(input<<1));
	printf("Output :");
	print_bit_pattern(out);
	return 0;
}
void print_bit_pattern(unsigned char c)
{
	unsigned i;
	for(int i=0;i<8;i++)
	{
		printf("%d",((c>>7)&0x01));
		c<<=1;
		
	}
	printf("\n");
}
