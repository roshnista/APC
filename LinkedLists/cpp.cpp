//swapping
#include<iostream>
using namespace std;

struct node
{
int info;
node *link;
};

int main()
{
int i,k,key1,key2,item;
struct node *start,*n,*ptr,*loc1,*loc2,*loc1p,*loc2p;
cin>>k;
struct node *head=NULL;
for(i=0;i<k;i++)
{
    cin>>item;
    n=new node();
    n->info=item;
    if(head==NULL)
        {
            n->link=NULL;
            head=n;
        }
    else
        {
            ptr=head;
            while(ptr->link!=NULL)
                ptr=ptr->link;
            ptr->link=n;
            n->link=NULL;
        }

}
//keys
cin>>key1>>key2;


    

//print
struct node *hd =head;
int j=0;
while (hd != NULL) { 
  
        for (int i = 0; i < 2 * (k - j); i++) 
            cout<<" "; 
  
       cout<<hd->info; 
  
        hd = hd->link; 
        j++; 
}
//swap
int pos1=key1;
int pos2=key2;


    struct node *node1, *node2, *prev1, *prev2, *temp;

    // Get the far position among both
    const int maxPos = (pos1 > pos2) ? pos1 : pos2;

    // Get total nodes in the list
    const int totalNodes =k;

    
    // If both positions are same then no swapping required
    if (pos1 == pos2)
    {
//        return 1;
    }


    // Identify both nodes to swap
    i = 1;
    temp  = head;
    prev1 = NULL;
    prev2 = NULL;

    // Find nodes to swap
    while (temp != NULL && (i <= maxPos))
    {
        if (i == pos1 - 1)
            prev1 = temp;
        if (i == pos1)
            node1 = temp;

        if (i == pos2 - 1)
            prev2 = temp;
        if (i == pos2)
            node2 = temp;

        temp = temp->link;
        i++;
    }

    // If both nodes to swap are found.
    if (node1 != NULL && node2 != NULL)
    {
        // Link previous of node1 with node2
        if (prev1 != NULL)
            prev1->link = node2;

        // Link previous of node2 with node1
        if (prev2 != NULL)
            prev2->link = node1;

        // Swap node1 and node2 by swapping their 
        // next node links
        temp        = node1->link;
        node1->link = node2->link;
        node2->link = temp;

        // Make sure to swap head node when swapping
        // first element.
        if (prev1 == NULL)
            head = node2;
        else if (prev2 == NULL)
            head = node1;
    }

//print
j=0;
while (head != NULL) { 
  
        for (int i = 0; i < 2 * (k - j); i++) 
           cout<<" ";
  
        cout<< head->info; 
  
        head = head->link; 
        j++;
		
		 } 
return 0;
}
