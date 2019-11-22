//Reverse linked list in pair of K

#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;


struct node * revk(struct node *h,int k)
{
	struct node *curr=h;
	struct node *prev=NULL;
	struct node *ne=NULL;
	int c=0;
	
	while(curr!=NULL && c<k)
	{
		ne=curr->next;
		curr->next=prev;
		prev=curr;
		curr=ne;
		c++;
	}
	
	if(ne!=NULL)
		h->next=revk(ne,k);
	
	return prev;
}


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
	
	//REVERSE IN PAIR OF K
	struct node *t=revk(head,3);
		
	//PRINT	

	while(t!=NULL)
	{
		printf("%d",t->data);
		t=t->next;
	}
	return 0;
}
