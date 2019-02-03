#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
	unsigned int msg;
	unsigned int * read_data;
	key_t kkey,ukey;
	unsigned int i = 0;
	ukey = 123;
	kkey = shmget(ukey,sizeof(msg),666|IPC_CREAT);
	if(kkey == -1)
	{
		perror("shmget:");
		exit(EXIT_FAILURE);
	}
	read_data = (int *)shmat(kkey,(void *)0,0);
	printf("write your data...\n");
	while(i<=100)
	{
		//scanf("%[^\n]s",read_data);
		*read_data = i;
		i++;
		sleep(1);
		//getchar();
	}
	shmdt((void*)0);
	return 0;

}
