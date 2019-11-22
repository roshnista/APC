//delete at end
#include<stdio.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;

void dend(struct node **h)
{
	struct node *curr=*h;
	while(curr && curr->next && curr->next->next)
	{
		curr=curr->next;
	}
	curr->next=NULL;
}

int main()
{
	struct node *n,*ptr,*pt;
	int x;
	scanf("%d",&x);
	while(x!=-1)
	{
		n=(struct node*)malloc(sizeof(struct node));
		n->data=x;
		if(head==NULL)
		{
			n->next=NULL;
			head=n;
		}
		else
		{
			ptr=head;
			while(ptr->next)
				ptr=ptr->next;
			
			ptr->next=n;
			n->next=NULL;
		}
		scanf("%d",&x);
	}
	
	dend(&head);
	
	pt=head;
	while(pt!=NULL)
	{
		printf("%d",pt->data);
		pt=pt->next;
	}
	
	return 0;
}
