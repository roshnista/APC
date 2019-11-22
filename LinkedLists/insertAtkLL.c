//insert before after at Kth position
#include<stdio.h>
struct node
{
	int data;
	struct node *next;	
};
struct node *head=NULL;

void insert(struct node **h)
{
	int d;
	scanf("%d",&d);
	while(d!=-1)
	{
		struct node *n=(struct node *)malloc(sizeof(struct node));
		n->data=d;
		if(*h==NULL)
		{
			
			n->next=NULL;
			*h=n;
		}
		else
		{
			struct node *ptr=*h;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			n->next=NULL;
			ptr->next=n;
			
		}
		
		scanf("%d",&d);	
	}	
}

void insertBeforek(struct node **h,int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=80;
	struct node *preptr,*ptr=*h;
	while(ptr->data!=x)
	{
		preptr=ptr;
		ptr=ptr->next;	
	}	
	preptr->next=n;
	n->next=ptr;
}

void insertAfterk(struct node **h,int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=80;
	struct node *preptr,*ptr=*h;
	while(preptr->data!=x)
	{
		preptr=ptr;
		ptr=ptr->next;	
	}	
	preptr->next=n;
	n->next=ptr;
}

insertAtpos(struct node **head,int x)
{
	int c=1;
	struct node *preptr,*ptr=*head;
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=21;
	while(ptr!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
		c++;
		if(c==x)
		{
			preptr->next=n;
			n->next=ptr;	
		}	
	}	
}

delAtpos(struct node **h,int x)
{
	int c=1;
	struct node *preptr,*n,*ptr=*h;
	while(ptr!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
		c++;
		if(c==x)
		{
			n=ptr;
			preptr->next=ptr->next;
			free(n);
			break;	
		}	
	}	
}

int main()
{

	insert(&head);
	insertBeforek(&head,99);
	insertAfterk(&head,77);
	insertAtpos(&head,3);
	delAtpos(&head,3);
	struct node *pt=head;
	while(pt!=NULL)
	{
		printf("%d",pt->data);
		pt=pt->next;
	}
	
	return 0;
}
