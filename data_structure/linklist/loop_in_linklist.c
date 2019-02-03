#include<stdio.h>
#include<stdlib.h>

typedef struct Nodes
{
	int val;
	struct Nodes * next;
}Nodes;

void removeloop(Nodes * , Nodes *);	//1st argument = slow_ptr and 2nd argument = head of linklist

int detectAndRemoveLoop(Nodes * list)
{
	Nodes * slow_ptr = list, * fast_ptr = list;
	while(slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;		//moves 1 step
		fast_ptr = fast_ptr->next->next;	//moves 2 steps

		if(slow_ptr == fast_ptr)
		{
			removeloop(slow_ptr,list);
			return 1;
		}
	}
	return 0;
}
void removeloop(Nodes * slow_ptr, Nodes * head)
{
	Nodes * ptr1, *ptr2;
	ptr1 = head;

	while(1)
	{
		ptr2= slow_ptr;
		while(ptr2->next != slow_ptr && ptr2->next !=ptr1)
			ptr2 = ptr2->next;
		if(ptr2->next == ptr1)
			break;
		ptr1 = ptr1->next;
	}
	ptr2->next = NULL;
}
void printList(struct Nodes *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->val);
        node = node->next;
    }
}

struct Nodes *newNode(int key)
{
    struct Nodes *temp = (struct Nodes*)malloc(sizeof(struct Nodes));
    temp->val = key;
    temp->next = NULL;
    return temp;
} 
int main()
{
    struct Nodes *head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next; 
  
    detectAndRemoveLoop(head); 	  
    printf("Linked List after removing loop \n");
    printList(head);
    return 0;
}
