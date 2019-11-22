//insert at beginning
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;

void del(struct node **h)
{
	struct node *ptr;
	ptr=*h;
	*h=(*h)->next;
	free(ptr);
	 	
}

int main()
{
	
	struct node *n,*ptr;
	int d;
	scanf("%d",&d);
	while(d!=-1)
	{
		n=(struct node *)malloc(sizeof(struct node));
		n->data=d;
		if(head==NULL)
		{ 
			n->next=NULL;
			head=n;		
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=n;
			n->next=NULL;	
			
		}
		scanf("%d",&d);
		
	}
	
	struct node * pt=head;
	while(pt!=NULL)
	{
		printf("%d",pt->data);
		pt=pt->next;
	}
	
	del(&head);
	
	//print
	struct node * pt1=head;
	while(pt1!=NULL)
	{
		printf("%d",pt1->data);
		pt1=pt1->next;
	}
}

