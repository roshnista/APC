//rev in pairs

#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;

struct node * revt(struct node *head)
{
	if (head == NULL || head->next == NULL) 
        return head; 
  
    // Store head of list after two nodes 
    struct node* remaing = head->next->next; 
  
    // Change head 
    struct node* newhead = head->next; 
  
    // Change next of second node 
    head->next->next = head; 
  
    // Recur for remaining list and change next of head 
    head->next = revt(remaing); 
  
    // Return new head of modified list 
    return newhead; 
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
	
	//print
	struct node * pt1=revt(head);
	
	while(pt1!=NULL)
	{
		printf("%d",pt1->data);
		pt1=pt1->next;
	}
}

