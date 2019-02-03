#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int msg;
	int * read_data;
	key_t kkey,ukey;
	ukey = 123;
	kkey = shmget(ukey,sizeof(msg),666|IPC_CREAT);
	if(kkey == -1)
	{
		perror("shmget:");
		exit(EXIT_FAILURE);
	}
	read_data = (int *)shmat(kkey,(void *)0,0);
	*read_data = 0;
	printf("waiting for data...\n");
	while(1)
	{
		if(*read_data)
		{
			printf("\rread : %d %%",*read_data);
			if(*read_data == 100) {
				printf("\rread : %d %%",*read_data);
				break;
				}

			//memset(read_data,'\0',100);
		}

	}
	shmdt((void*)0);
	return 0;

}
