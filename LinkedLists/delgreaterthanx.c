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
	
	//x=3
	int x=3;
	struct node *ptrr=head;
	struct node *preptr=head;
	struct node *temp;
	while(ptrr!=NULL)
	{
		if(ptrr->data>x)
		{
			temp=ptrr;
			preptr->next=ptrr->next;
			ptrr=ptrr->next;
			free(temp);
		}
		else
		{
			preptr=ptrr;
			ptrr=ptrr->next;
		}
	}
	
	
	
	//print
	struct node * pt1=head;
	while(pt1!=NULL)
	{
		printf("%d",pt1->data);
		pt1=pt1->next;
	}
}

