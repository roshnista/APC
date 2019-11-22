//reverse linked list iteratively
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;

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
			ptr->next=n;
			n->next=NULL;
		}		
	scanf("%d",&d);
	}

		//REVERSE ITERATIVELY
		
		struct node *prev=head;
		struct node *curr=head->next;
		head=head->next;
		prev->next=NULL;
		
		while(head!=NULL)
		{
			head=head->next;
			curr->next=prev;
			prev=curr;
			curr=head;
		}
		head=prev;
	
	
	//PRINT	
	
	struct node *t=head;
	while(t!=NULL)
	{
		printf("%d",t->data);
		t=t->next;
	}
	return 0;
}
