//Reverse linked list in pairs
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;


struct node * revpair(struct node *hea)
{
	if(hea==NULL || hea->next==NULL)
		return hea;
		
	struct node *m=hea->next->next;
	struct node *newhead=hea->next;
	hea->next->next=hea;
	hea->next=revpair(m);
	return newhead;
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
	
	//REVERSE IN PAIR OF 2
	struct node *t=revpair(head);
		
	//PRINT	
	//struct node *t=head;
	while(t!=NULL)
	{
		printf("%d",t->data);
		t=t->next;
	}
	return 0;
}
