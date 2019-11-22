//insert at end
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};


void insrte(struct node *h,int ta)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	struct node *curr=h;
	n->data=ta;
	n->next=NULL;
	if(h==NULL)
		h=n;
	else
	{
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
			curr->next=n;
				
	}
}
	
int main()
{
	struct node *head=NULL;
	struct node *n,*ptr,*ptr1;
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
	
	insrte(&head,28);
	
	//print
	struct node * pt=head;
	while(pt!=NULL)
	{
		printf("%d",pt->data);
		pt=pt->next;
	}
}
