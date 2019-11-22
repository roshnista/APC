//reverse linked list recursively
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *h;

struct node *reverse(struct node **curr)
{
	
	struct node *first=*curr;
	struct node *second;
	if(first)
		second=first->next;
	
	if(!second)
		return first;
	
	else
	{
		h=reverse(&second);
		first->next=second->next;
		second->next=first;
	}
	
	return h;	
	
	
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
	
	struct node * pt1=reverse(&head);
	
	//print

	while(pt1!=NULL)
	{
		printf("%d",pt1->data);
		pt1=pt1->next;
	}
}

