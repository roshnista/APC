//insert at beginning
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};


void insrt(struct node **h,int ta)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=ta;
	n->next=*h;
	*h=n;	
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
			n->next=NULL;	
			ptr->next=n;
		}
		scanf("%d",&d);
		
	}
	
	insrt(&head,28);
	
	//print
	struct node * pt=head;
	while(pt!=NULL)
	{
		printf("%d",pt->data);
		pt=pt->next;
	}
}

//	struct node *start=NULL;
//
//int main()
//{
//	struct node *ptr =(struct node *)malloc(sizeof(struct node));
//	*ptr=*start;
//	while((ptr)!=NULL)
//	{
//		printf("%d",ptr -> data);
//		ptr=ptr->next;
//	}
//	return 0;
//}
