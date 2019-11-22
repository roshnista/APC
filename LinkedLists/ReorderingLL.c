//Reordering take one from front and back
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *h;


int main()
{
	struct node *n;
	int d;
	scanf("%d",&d);
	while(d!=-1)
	{
		n=(struct node *)malloc(sizeof(struct node));
		n->data=d;
		if(head==NULL)
		{
			head=n;
			n->next=NULL;
		}
		else
		{
			struct node *ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;  
			n->next=NULL;
			ptr->next=n;
		}		
	scanf("%d",&d);
	}
	
	//REorder

	struct node *ptr1=head,*ptr2=ptr1->next;
	while(ptr2 && ptr2->next)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
	}
	
	struct node *h2=ptr1->next;
	struct node *h1=head;
	ptr1->next=NULL;


	//reverse
		
		struct node *prev=h2;
		struct node *curr=h2->next;
		h2=h2->next;
		prev->next=NULL;
		
		while(h2!=NULL)
		{
			h2=h2->next;
			curr->next=prev;
			prev=curr;
			curr=h2;
		}
		h2=prev;
	
	
	struct node *headx=(struct node *)malloc(sizeof(struct node));	
	while(h1 || h2)
	{
		if(h1)
		{
			headx->next=h1;
			headx=headx->next;
			h1=h1->next;
		}
		if(h2)
		{
			headx->next=h2;
			headx=headx->next;
			h2=h2->next;
		}
		
	}
	//headx->next=NULL;
		
	//PRINT	
	struct node *t=head;
	while(t!=NULL)
	{
		printf("%d",t->data);
		t=t->next;
	}
	return 0;
}
