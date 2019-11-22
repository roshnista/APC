//sort linked list in ascending hackerrank reverse ll
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *head1=NULL;
struct node *h;

struct node *reverse(struct node **curr)
{
    
    struct node *first=*curr;
    struct node *second;
    if(first)
        second=first->next;
    
    if(!second)
        return first;
    
    else
    {
        h=reverse(&second);
        first->next=second->next;
        second->next=first;
    }
    
    return h;   
}
struct node* SortedMerge(struct node *a, struct node *b) 
{  
    if (a==NULL && b==NULL) 
		return NULL; 
  
    struct node *res = NULL; 
  
    // Traverse both lists while both of then 
    // have nodes. 
    while (a != NULL && b != NULL) 
    { 
        // If a's current value is smaller or equal to 
        // b's current value. 
        if (a->data <= b->data) 
        { 
            // Store next of current Node in first list 
            struct node *temp = a->next; 
  
            // Add 'a' at the front of resultant list 
            a->next = res; 
            res = a; 
  
            // Move ahead in first list 
            a = temp; 
        } 
  
        // If a's value is greater. Below steps are similar 
        // to above (Only 'a' is replaced with 'b') 
        else
        { 
            struct node *temp = b->next; 
            b->next = res; 
            res = b; 
            b = temp; 
        } 
    } 
  
    // If second list reached end, but first list has 
    // nodes. Add remaining nodes of first list at the 
    // front of result list 
    while (a != NULL) 
    { 
        struct node *temp = a->next; 
        a->next = res; 
        res = a; 
        a = temp; 
    } 
  
    // If first list reached end, but second list has 
    // node. Add remaining nodes of first list at the 
    // front of result list 
    while (b != NULL) 
    { 
        struct node *temp = b->next; 
        b->next = res; 
        res = b; 
        b = temp; 
    } 
  
    return res; 
} 

int main()
{
    
    struct node *n,*n1,*ptr1,*ptr;
    int d,i;
    for( i=0;i<3;i++)
    {
        scanf("%d",&d);
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
    }

    int d1,j;
    for(j=0;j<3;j++)
    {
         scanf("%d",&d1);
        n1=(struct node *)malloc(sizeof(struct node));
        n1->data=d1;
        if(head1==NULL)
        { 
            n1->next=NULL;
            head1=n1;        
        }
        else 
        {
            ptr1=head1;
            while(ptr1->next!=NULL)
                ptr1=ptr1->next;
            ptr1->next=n1;
            n1->next=NULL;      
        }
    }
    
    struct node * pt1=reverse(&head);
    struct node * pt2=reverse(&head1); 
    
    struct node *po=pt1,*p1=pt1;
    struct node * p2=pt2;
    while(pt1->next!=NULL)
    {
        pt1=pt1->next;
    }
    
        pt1->next=pt2;
    
		if(pt1->data < pt2->data)
		{
			reordr(&po);
		}

    
    
    while(po!=NULL)
    {
        printf("%d ",po->data);
        po=po->next;
    }
   
}

