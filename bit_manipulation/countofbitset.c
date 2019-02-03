#include<stdio.h>

void numOfsetbit(int);
int main()
{
	int num;
	printf("Enter number :");
	scanf("%d",&num);
	printf("\n");
	numOfsetbit(num);
	return 0;
}
void numOfsetbit(int n)
{
	int count = 0;
	while(n)
	{
		count += n&0x01;
		n>>=1;
	}
	printf("Number of set bits : %d\n",count);
}
