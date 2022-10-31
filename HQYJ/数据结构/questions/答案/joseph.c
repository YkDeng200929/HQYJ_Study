#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *init_list_head(void)
{
	struct node *head = (struct node *)malloc(sizeof(struct node));
	if(!head)
	return false;
	head->data = 1;
	head->next = head;
	return head;
}

bool insert_val_tail(struct node *phead,int val)
{
	struct node *pcur = NULL;
	if(!phead)
	return false;
	struct node *pnew = (struct node *)malloc(sizeof(struct node));
	if(!pnew)
	return false;
	pnew->data = val;
	pnew->next = pnew;
	for(pcur = phead; pcur->next != phead;pcur = pcur->next)
	{
	}

	pnew->next = pcur->next;
	pcur->next = pnew;
	return true;
}

void print_linklist(struct node *phead)
{
	struct node *pcur = phead;
	do
	{
		printf("val = %d\n",pcur->data);
		pcur = pcur->next;
	}while(pcur != phead);
}

int main()
{
	int i;
	int count = 0;
	struct node *phead;
	
	phead = init_list_head();
	
	for(i = 2; i <= 8; i++)
	{
		insert_val_tail(phead,i);
	}
	print_linklist(phead);

	int b = 3, k = 4;
	struct node *prev,*pstart;
	
	for(pstart = phead; pstart->data != 3; pstart = pstart->next)
	{
	}

	printf("pstart %d\n",pstart->data);
	
	while(pstart->next != pstart)
	{
		
		while(count < k-1)
		{
			prev = pstart;
			pstart = pstart->next;
			count++;
		}
		printf("out: %d\n",pstart->data);
		prev->next = pstart->next;
		pstart->next = NULL;
		free(pstart);
		pstart = prev->next;
		count = 0;
	}
	printf("the last one = %d\n",pstart->data);
	return 0;
}
