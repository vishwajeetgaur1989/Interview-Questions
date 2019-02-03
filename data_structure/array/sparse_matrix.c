#include<stdio.h>

int main()
{
	int i,j,r,c,counter = 0;
	printf("Enter value for row and column\n");
	scanf("%d %d",&r,&c);
	int arr[r][c];
	for(i=0;i<r;i++)
	{
		printf("enter value for %d row\n",(i+1));
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 0)
				counter++;
		}
	}
	printf("input matrix\n");
	for(i=0;i<r;i++)
	{
		printf("\n");
		for(j=0;j<c;j++)
		{
			printf("%d ",arr[i][j]);
		}
	}
	if(counter > (r*c)/2)
		printf("\nSparse Matrix\n");
	else
		printf("\nNot sparse matrix\n");
	return 0;
}
