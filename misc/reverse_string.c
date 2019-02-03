#include<stdio.h>
#include<string.h>

int  main()
{
	int len,i = 0,j;
	char str[] = "Hello world";
	len = strlen(str)-1;
	printf("string : %s\n",str);
	j = len;
	for(i=0;i<len/2;i++)
	{
		str[i] = (str[i])^(str[j]);
		str[j] = (str[i])^(str[j]);
		str[i] = (str[i])^(str[j]);
		j--;
	}
	
	printf("reverse string : %s\n",str);
	return 0;
}
