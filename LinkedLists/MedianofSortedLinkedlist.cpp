//median of sorted linked list
#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
	int data;
	struct node *next;	
};
struct node *head=NULL;

void findmedian(struct node *h)
{
	struct node *p1=h,*p2=h,*p3=h;
	if(head!=NULL)
	{
	
		while(p2 && p2->next)
		{
			p2=p2->next->next;
			p3=p1;
			p1=p1->next;
		}
	
		if(p2!=NULL)
		{
			cout<<p1->data;
		}
		else
		{
			cout<< (p1->data + p3->data)/2.0;
		}
	}
}

int main()
{
	int d;
	cin>>d;
	
	while(d!=-1)
	{
		struct node *n=(struct node *)malloc(sizeof(struct node));
		n->data=d;
		if(head==NULL)
		{
			head=n;
			n->next=NULL;
		}
		else
		{
			struct node *h=head;	
			while(h->next!=NULL)
			{
				h=h->next;
			}
			n->next=NULL;
			h->next=n;
		}	
		cin>>d;
	}
	
	
	findmedian(head);
	
	return 0;
}

