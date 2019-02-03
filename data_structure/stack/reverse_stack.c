#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int * stack;
	int top,size;
}Stack;

Stack * push(Stack *,int);
int * pop(Stack *);
Stack * display(Stack *);
void reverse(Stack *,int);
void InsertAtBottom(Stack *,int,int);
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
	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	display(s);
	reverse(s,3);
	s->top = 3;
	display(s);

}

	Stack * push(Stack * s,int val)
	{
		if(s->top >= ((s->size)-1))
		{
			printf("Stack is full!\n");
			return 0;
		}
		*((s->stack)+(++s->top)) = val;
	
	}
	void InsertAtBottom(Stack * s,int top,int val)
	{
		*((s->stack)+top) = val;
	}
	void reverse(Stack * s,int top)
	{
		int temp;
		if(top == -1)
		{	
			s->top = 3;
			return;
		}
		temp = pop(s);
		reverse(s,(top-1));
		InsertAtBottom(s,s->top,temp);
		--(s->top);
	}

	int * pop(Stack * s)
	{
		int temp;
		if(s->top == -1)
		{
			printf("Stack is Empty!\n");
			return 0;
		}
		temp = *((s->stack)+(s->top--));
		printf("dequeue value is %d\n",temp);
		return temp;
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
