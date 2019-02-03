#include<stdio.h>
typedef struct user
{
    int     emp_id;  
    char    name[0];
    int     name_len;
}user;
int main()
{
	printf("sizeof struct =  %d\n",sizeof(user));
	return 0;
}
