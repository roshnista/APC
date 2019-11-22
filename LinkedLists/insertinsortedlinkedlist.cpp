//insert element in sorted linked list
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

void insert(struct node **h,int x)
{
	node *n=new node;
	n->data=x;
	
	if(*h==NULL || (*h)->data>x)
	{
		n->next=*h;	
		*h=n;
	}	
	else
	{
		node *p1=*h,*p2=*h;
		while(p2!=NULL && p2->data<=x)
		{
			p1=p2;
			p2=p2->next;
		}
		p1->next=n;
		n->next=p2;
	}
	//*h=h1;
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
				
	int x;
	cin>>x;
	
	insert(&head,x);
				
	node *j=new node;
	j=head;
	while(j!=NULL)
	{
		cout<<j->data<<" ";
		j=j->next;
	}

return 0;
}

