#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
	int * queue;
	int fi,ri,size;
}Queue;
int choice();
Queue * enqueue(Queue *);
Queue * dequeue(Queue *);
Queue * display(Queue *);

int main()
{
	int ch;
	Queue * q;
	q = (Queue *)malloc(sizeof(Queue));
	if(!q)
	{
		perror("Malloc:");
		return 1;
	}
	q->size = 5;
	q->ri = -1;
	q->fi = -1;
	q->queue = (int*)malloc(sizeof(int)*q->size);
	printf("Queue created sucessfully of size 5\n");

	while(1)
	{
		ch = choice();
		switch(ch)
		{
			case 1: enqueue(q);
				break;
			case 2: dequeue(q);
				break;
			case 3: display(q);
				break;
			case 4:
				return 0;
			default:
				break;
		}
	}
	
}
	int choice()
	{
		int ch;
		printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
		scanf("%d",&ch);
		return ch;
	}

	Queue * enqueue(Queue * q)
	{
		if(q->ri >= ((q->size)-1))
		{
			printf("Queue is full!\n");
			return 0;
		}
		printf("Enter value : ");
		scanf("%d",((q->queue)+(++q->ri)));
		printf("\n");
	}

	Queue * dequeue(Queue * q)
	{
		if(q->ri == q->fi)
		{
			printf("Queue is Empty!\n");
			q->ri = -1;
			q->fi = -1;
			return 0;
		}
		printf("dequeue value is %d\n",*((q->queue)+(++q->fi)));
	}

	Queue * display(Queue * q)
	{
		int i;
		if(q->ri == q->fi)
		{
			printf("Queue is Empty!\n");
			return 0;
		}
		for(i=q->fi+1;i<=q->ri;i++)
			printf("%d ---> %d\n",i,*((q->queue)+i));
	}
