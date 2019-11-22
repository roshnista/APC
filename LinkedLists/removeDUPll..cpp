//remove duplicates
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;

void removeDup(struct node **head)
{
	struct node *ptr1,*ptr2,*temp,*pre;
	ptr1=ptr2=pre=*head;
	
	while(ptr1!=NULL)
	{
		ptr2=ptr1->next;	
		while(ptr2!=NULL )
		{
			if(ptr1->data==ptr2->data && ptr1!=ptr2)
			{
				pre=ptr2->next->next;		
				temp=ptr2;
				ptr2=ptr2->next;
				//temp=NULL;
			}
			else
			{
			pre=ptr2;
			ptr2=ptr2->next;	
			}
		}
			ptr1=ptr1->next;
	}	
}

int main()
{
	struct node *curr;
	struct node *ptr;
	int d;
	scanf("%d",&d);
	curr->data=d;
	while(d!=-1)
	{
		curr=(struct node*)malloc(sizeof(struct node));
		
		if(head==NULL)
		{
			curr->next=NULL;
			head=curr;
			
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=curr;
			curr->next=NULL;
		}
		scanf("%d",&d);
	}
	
	removeDup(&head);
	
	struct node * p=head;
	while(p!=NULL)
	{
		printf("%d",p->next);
		p=p->next;
	}
	
	
	return 0;
}
