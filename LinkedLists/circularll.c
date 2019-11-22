#include<stdio.h>
#include<stdlib.h>

/* structure for a node */
struct node
{
  int data;
  struct node *next;
};

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node *pre,*first=*head_ref;
    struct node *pre1=*head_ref,*h=*head_ref;
   //NULL
    if((*head_ref)==NULL)
        {
            (*head_ref)=new_node;
            new_node->next=new_node;
        }
    else
        {
            //starting
            if(new_node->data <= (*head_ref)->data)
            {
                while(pre->next != (*head_ref))
                    pre=pre->next;
                pre->next=new_node;
                new_node->next=(*head_ref);
                (*head_ref)=new_node;
            }
            else
            {
                //in between
                (*head_ref)=(*head_ref)->next;
                while((*head_ref)->data < new_node->data && (*head_ref)!=first)
                {
                    pre1=(*head_ref);
                    (*head_ref)=(*head_ref)->next;
                }
                new_node->next=pre1->next;
                pre1->next=new_node;
                

                // //at last
                // while(pre->next->data != h->data)
                //     pre=pre->next;
                // pre->next=new_node;
                // new_node->next=h;
            }
        }
     //*head_ref=h;  
}

void printList(struct node *start)
{
  struct node *temp;

  if(start != NULL)
  {
    temp = start;
    
    do {
      printf("%d\n", temp->data);
      temp = temp->next;
    } while(temp != start);
  }
}

/* Driver program to test above functions */
int main()
{
  int arr; //= {12, 56, 2, 11, 1, 90};
  int list_size, i;

  /* start with empty linked list */
  struct node *start = NULL;
  struct node *temp;
    
  int n;
  scanf("%d",&n);

  /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
  for(i = 0; i< n; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&arr);
    temp->data = arr;
    sortedInsert(&start, temp);
  }

  printList(start);
  //getchar();
  return 0;
}
