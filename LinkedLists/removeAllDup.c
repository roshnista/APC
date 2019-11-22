//remove All Duplicates
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;


void removeAllDup(struct node **start)
{
    struct node* dummy=(struct node *)malloc(sizeof(struct node)) ; 
    dummy -> next = *start; 
    struct node* ptr1 = dummy; 
    struct node* ptr2 = *start; 
    while(ptr2!= NULL) 
    { 
        
        while(ptr2 -> next != NULL && ptr1->next->data == ptr2->next->data) 
            ptr2 = ptr2 -> next; 
  
        if (ptr1 -> next == ptr2) 
            ptr1 = ptr1 -> next; 
   
        else
            ptr1 -> next = ptr2-> next; 
  
        ptr2 =ptr2-> next; 
    } 
    *start =  dummy->next; 
}
	


int main()
{
	struct node *curr;
	struct node *ptr;
	int d;
	scanf("%d",&d);
	while(d!=-1)
	{
		curr=(struct node*)malloc(sizeof(struct node));
		curr->data=d;
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
	
	removeAllDup(&head);
	
	struct node * p=head;
	while(p)
	{
		printf("%d",p->data);
		p=p->next;
	}
	return 0;
}
