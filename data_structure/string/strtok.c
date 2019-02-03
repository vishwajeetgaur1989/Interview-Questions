#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * _strtok_(char * src, char * delim)
{
	char * temp;
	for(int i=0;i<strlen(src);i++)
	{
		if(*(src+i) == *(delim))
		{
			temp = malloc(i);
			memcpy(temp,src,i);
			return temp;
		}
			
	}
}
int main()
{
	char ch[]="ab,cd,de";
	printf("output of self made strtok func = %s\n",_strtok_(ch,","));
	//_strtok_(ch,",");
	return 0;
}
