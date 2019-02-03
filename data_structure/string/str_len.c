#include<stdio.h>
#include<string.h>

void str_copy(char * des,const char * src,int len)
{
	memcpy(des,src,len);
}
int main()
{
	char str[]="sajan",str2[10];
	printf("string1 = %s\nlength = %d\n",str,strlen(str));
	str_copy(str2,str,strlen(str));
	printf("copy string2 = %s\nlength = %d\n",str2,strlen(str2));

	return 0;
}
