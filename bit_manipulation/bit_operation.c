#include<stdio.h>

#define SET_BIT(X,Y) X |=(1<<Y)
#define SET_RESET(X,Y) X &=~(1 << Y)
#define TOGGLE(Y) Y ^=0xFF

int getchoice();
void print_bit_pattern(unsigned char);
unsigned char SWAP(unsigned char,int,int);
int main()
{
	int choice,pos,x,y;
	unsigned char input = '\0';
	unsigned int i; 
	printf("Enter the value : ");
	scanf("%u",&i);
	
	input =(char)i;
	printf("\n");
	print_bit_pattern(input);
	while(1)
	{
		choice = getchoice();
		switch(choice)
		{
			case 1: 
				printf("Enter the position\n");
				scanf("%d",&pos);
				SET_BIT(input,pos);
				print_bit_pattern(input);

				break;
			case 2:
				printf("Enter the position\n");
				scanf("%d",&pos);
				SET_RESET(input,pos);
				print_bit_pattern(input);
				break;
			case 3:
				TOGGLE(input);
				print_bit_pattern(input);
				break;
			case 4:
				printf("Enter the 1st position\n");
				scanf("%d",&x);
				printf("Enter the 2nd position\n");
				scanf("%d",&y);
				print_bit_pattern(SWAP(input,x,y));
				break;
			case 5:
				return 0;
		}
	}
	return 0;
}
int getchoice()
{
	int ch;
	printf("Please enter your choice?\n1.BIT SET\n2.BIT RESET\n3.BIT TOGGLE\n4.BIT SWAP\n5.EXIT\n");
	scanf("%d",&ch);
	return ch;
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
unsigned char SWAP(unsigned char input,int x, int y)
{	
	unsigned char ch1,ch2,xor,result;
	ch1 = (input >> x)&0x01;
	ch2 = (input >> y)&0x01;
	xor = ch1^ch2;
	xor = (xor<<x)|(xor<<y);
	result = input^xor;
	return result;
}
