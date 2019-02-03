#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int * stack;
	int top,size;
}Stack;
int choice();
Stack * push(Stack *);
Stack * pop(Stack *);
Stack * display(Stack *);

int main()
{
	int ch;
	Stack * s;
	s = (Stack *)malloc(sizeof(Stack));
	if(!s)
	{
		perror("Malloc:");
		return 1;
	}
	s->size = 5;
	s->top = -1;
	s->stack = (int*)malloc(sizeof(int)*s->size);
	printf("Stack created sucessfully of size 5\n");

	while(1)
	{
		ch = choice();
		switch(ch)
		{
			case 1: push(s);
				break;
			case 2: pop(s);
				break;
			case 3: display(s);
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
		printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		scanf("%d",&ch);
		return ch;
	}

	Stack * push(Stack * s)
	{
		if(s->top >= ((s->size)-1))
		{
			printf("Stack is full!\n");
			return 0;
		}
		printf("Enter value : ");
		scanf("%d",((s->stack)+(++s->top)));
		printf("\n");
	}

	Stack * pop(Stack * s)
	{
		if(s->top == -1)
		{
			printf("Stack is Empty!\n");
			return 0;
		}
		printf("dequeue value is %d\n",*((s->stack)+(s->top--)));
	}

	Stack * display(Stack * s)
	{
		int i;
		if(s->top == -1)
		{
			printf("Stack is Empty!\n");
			return 0;
		}
		for(i=s->top;i>=0;i--)
			printf("%d ---> %d\n",i,*((s->stack)+i));
	}
