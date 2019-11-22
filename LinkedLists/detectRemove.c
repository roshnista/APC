//loop and removing loop
#include <stdio.h>
struct node
{ 
    int data; 
    struct node* next; 
}; 
struct node *head=NULL;

void detectloop(struct node *l)
{
	struct node *first=l;
	struct node *second=l;
	while(first && second && second->next)
	{
		first=first->next;
		second=second->next->next;
		
		if(first==second)
		removeloop(first,l);
	}
}
void removeloop(struct node *n,struct node *l)
{
	struct node *p1,*p2;
	p1=n;
	p2=n;
	int k=1;
	
	//count nodes in loop
	
	while(p1->next!=p2)
	{
		p1=p1->next;
		k++;
	}
	
	p1=l;
	p2=l;
	int i=0;
	for(i=0;i<k;i++)
	{
		p2=p2->next;
	}
	
	while(p1!=p2)
	{
		p1=p1->next;
		p2=p2->next;
	}
	
	while(p2->next!=p1)
	{
		p2=p2->next;	
	}
	p2->next=NULL;
	
	}
 
 
 
 int main()
{
	
	struct node *n,*ptr,*pt1;
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
			pt1=head;	
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
	
	head->next->next->next->next= head->next->next; 
	
	detectloop(head);
	
	//print
//	struct node * pt1=head;
	while(pt1!=NULL)
	{
		printf("%d",pt1->data);
		pt1=pt1->next;
	}
}

