#include<stdio.h>
#include<stdlib.h>

typedef struct Head
{
	struct Head * ptr;
}Head;

typedef struct Nodes
{
	int val;
	struct Nodes * next;
}Nodes;

Nodes * create_nodes();
int print_midpoint(Nodes *);
void Insert_Begining(Head *);
Nodes * reverse(Nodes *);
int display(Nodes *);
int choice();
int main()
{
	int ch;
	Head * head = (Head *)malloc(sizeof(Head));
	if(!head)
	{	
		perror("create_nodes :");
		return 0;
	}
	head->ptr = NULL;
	while(1)
	{
		ch = choice();
		switch(ch)
		{
			case 1: Insert_Begining(head);
				break;
			case 2: display((Nodes *)head->ptr);
				break;
			case 3: print_midpoint((Nodes *)head->ptr);
				break;
			case 4:	head->ptr =(Head *)reverse((Nodes *)head->ptr);
				break;
			case 5:
				return 0;
			default:
				break;
		}
	}
	return 0;
}

Nodes *  reverse(Nodes * node)
{
	Nodes * prev,* curr,* next;
	prev = NULL;
	curr = node;
	while(curr !=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

int choice()
{
	int ch;
	printf("1.Insert At Begining\n2.Display\n3.Print Mid value\n4.Reverse\n5.Exit\n");
	scanf("%d",&ch);
	return ch;
}

int print_midpoint(Nodes * node)
{
	Nodes *ptr1,*ptr2;
	if(!node)
	{
		printf("list is empty!\n");
		return 0;
	}
	ptr1 = node;
	ptr2 = node;
	while(ptr2->next)
	{
		ptr1 = ptr1->next;
		for(int i=0;i<2;i++)
		{
			if(ptr2->next)
				ptr2 = ptr2->next;
			else
				goto end;
		}
	}
	end: printf("mid value at linklist is %d\n",ptr1->val);
}

void Insert_Begining(Head * head)
{
	Nodes * temp = create_nodes();
	printf("Enter the value\n");
	scanf("%d",&(temp->val));
	temp->next = (Nodes *)head->ptr;
	head->ptr = temp;
}

int  display(Nodes * node)
{
	if(!node)
	{
		printf("Nothing to display!\n");
		return 0;
	}
	while(node->next)
	{
		printf("%d ->",node->val);
		node = node->next;
	}
	printf("%d ",node->val);
	printf("\n");
}

Nodes * create_nodes()
{
	return ((Nodes *)malloc(sizeof(Nodes)));
}
