//insert in sorted linked list

#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
};
node *head=NULL;


void push(struct node **h,int d)
{
	node *n=new node;
	n->data=d;
	if((*h)==NULL)
	{
		*h=n;
		n->next=NULL;
	}
	else
	{
			struct node *p=*h;	
			while(p->next!=NULL)
			{
				p=p->next;
			}
			n->next=NULL;
			p->next=n;
	}	
}


struct node * merge(struct node *a,struct node *b)
{
	struct node *r=NULL;
		
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	
	if(a->data <= b->data)
	{
			r=a;
			r->next=merge(a->next,b);
	}
	else
	{
			r=b;
			r->next=merge(a,b->next);
	}
	return r;
	
}

void frontbacksplit(struct node *source,struct node **a,struct node **b)
{

	struct node* fast; 
    struct node* slow; 
    slow = source; 
    fast = source->next; 
  
  	 while (fast != NULL) 
	{ 
        fast = fast->next; 
        if (fast != NULL)
		 { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    *a = source; 
    *b = slow->next; 
    slow->next = NULL;
}



void mergesort(struct node **h)
{
	struct node *a,*b;
	struct node *n=*h;
	if( (n==NULL ) || (n->next==NULL) )
		return ;
		
	frontbacksplit(n,&a,&b);

	mergesort(&a);
	mergesort(&b);
	
	*h=merge(a,b);
}
int main()
{
	int nn;
	cin>>nn;
	while(nn!=-1)
	{
	
	push(&head,nn);
	cin>>nn;
	}
				
	mergesort(&head);
				
	node *j=new node;
	j=head;
	while(j!=NULL)
	{
		cout<<j->data<<" ";
		j=j->next;
	}

return 0;
}

