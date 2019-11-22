#include<stdio.h>
#include<stdlib.h>
//queue using linked list
struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *front,*rear;	
};

struct node *newnode(int k)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=k;
	temp->next=NULL;
	return temp;
}

struct queue* newqueue()
{
	struct queue *q=(struct queue *)malloc(sizeof(struct queue));
	q->front=NULL;
	q->rear=NULL;
	return q;
}

void enq(struct queue *q,int x)
{
	struct node *t=newnode(x);
	if(q->rear==NULL)
		q->rear=q->front=t;
	else
		q->rear->next=t;
		q->rear=t;
}

struct node *deq(struct queue *q)
{
	if(q->front==NULL)
		return;
	struct node *w=q->front;
	q->front=q->front->next;
	if(q->front==NULL)
		q->rear=NULL;
	return w;
}

int main() 
{ 
    struct queue* q = newqueue(); 
    enq(q, 10);
	enq(q, 20); 
    enq(q, 40); 
    enq(q, 30); 
    enq(q, 50); 
    struct node* n = deq(q); 
    if (n != NULL) 
        printf("Dequeued item is %d", n->data); 
        
    while(q)
    {
     struct node* n = deq(q); 
    	printf("%d",n->data);	
	}
    return 0; 
} 

