//remove duplicates in an unsorted linked list
#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;	
};
node *head=NULL;

void removedup(node **head)
{
	node *ptr1,*ptr2,*temp,*pre;
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
				temp=NULL;
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


void push(node **head,int data)
{
	node *start=new node();
	start->data=data;
	start->next=*head;
	*head=start;
}

void print(node **head)
{
	node *s=new node();
	s=*head;
	while(s!=NULL)
	{
		cout<< s->data;
		s=s->next;
	}
}
int main()
{
	
	push(&head,10);
	push(&head,3);
	push(&head,8);
	push(&head,6);
	push(&head,3);
	push(&head,7);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,1);
	removedup(&head);
	print(&head);
	return 0;
}
