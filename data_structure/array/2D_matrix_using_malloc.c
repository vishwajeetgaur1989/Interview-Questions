#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **ptr;
	int r,c;
	printf("Enter row n cols for the matrix\n");
	scanf("%d %d",&r,&c);
	ptr = (int **)malloc(sizeof(int *)*r);
	for(int i=0;i<r;i++)
	{
		*(ptr+i) =(int *)malloc(sizeof(int)*c);
	}
	for(int i=0;i<r;i++)
	{
		printf("enter value for %d row \n",(i+1));
		for(int j=0;j<c;j++)
		{
			scanf("%d",*(ptr+i)+j);
		}
	}
	printf("entered matrix : \n");
	for(int i=0;i<r;i++)
	{
		printf("\n");
		for(int j=0;j<c;j++)
		{
			printf("%d ",*(*(ptr+i)+j));
		}
	}
	printf("\n");
}
