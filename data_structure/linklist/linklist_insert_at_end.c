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
int Insert_End(Head *);
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
			case 1: Insert_End(head);
				break;
			case 2: display((Nodes *)head->ptr);
				break;
			case 3:
				return 0;
			default:
				break;
		}
	}
	return 0;
}

int choice()
{
	int ch;
	printf("1.Insert At End\n2.Display\n3.Exit\n");
	scanf("%d",&ch);
	return ch;
}

int Insert_End(Head * head)
{
	Nodes * node;
	Nodes * temp = create_nodes();
	printf("Enter the value\n");
	scanf("%d",&(temp->val));
	if(!head->ptr)
	{
		head->ptr = temp;
		temp->next = NULL;
		return 0;
	}
	node = (Nodes *)head->ptr;
	while(node->next)
		node = node->next;
	node->next = temp;
	node = node->next;
	node->next = NULL;
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
