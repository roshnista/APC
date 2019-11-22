#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct tree{
int data;
struct tree *left;
struct tree *right;
};
struct stree{
struct tree *node;
struct stree *nxt;
int dist;
};
struct map{
int da;
int key;
struct map *left;
struct map *right;
};
/*struct tree  *insert(struct tree *root,int d){
if(root==NULL){
    struct tree *n=(struct tree*)malloc(sieof(struct tree));
    n->data=d;
    n->left=NULL;
    n->right=NULL;
    return n;
}
else if(d<root->data){
    root->left=insert(root->left,d);
}
else if(d>root->data){
    root->right=insert(root->right,d);
}
return root;
}*/
void push(struct stree **h,struct tree *d,int di){
struct stree *nn=(struct stree*)malloc(sizeof(struct stree));
struct stree *curr=*h;
nn->node=d;
nn->nxt=NULL;
nn->dist=di;
    if(*h==NULL){
        *h=nn;
    }
    else{
        while(curr->nxt!=NULL){
            curr=curr->nxt;
        }
        curr->nxt=nn;
    }
}
struct tree* pop(struct stree **h){
struct stree *curr=*h;
*h=curr->nxt;
return curr->node;
}
struct map  *mpush(struct map *m,int dist,int val){
if(m==NULL){
    struct map* ma=(struct map*)malloc(sizeof(struct map));
    ma->da=dist;
    ma->key=val;
    ma->right=NULL;
    ma->left=NULL;
    return ma;
}
else if(dist<m->da){
    m->left=mpush(m->left,dist,val);
}
else if(dist>m->da){
    m->right=mpush(m->right,dist,val);
}
return m;
}
int mfind(struct map *m,int dist){
int a;
if(m==NULL){
    return 0;
}
if(m!=NULL&&m->da==dist){
    return 1;
}
else if(m->da>dist){
    a=mfind(m->left,dist);
}
else if(m->da<dist){
    a=mfind(m->right,dist);
}
return 0;
}
void inorder(struct map *r){
if(r==NULL)
    return;
inorder(r->left);
printf("%d ",r->key);
inorder(r->right);
}
void topview(struct tree *root){
    struct tree *curr=root;
struct stree *queue=NULL;
struct map *m=NULL;
int dist=0,tdist;
push(&queue,root,dist);
while(queue!=NULL){
    tdist=queue->dist;
    curr=pop(&queue);
    //printf("%d %d\n",curr->data,tdist);
    if(m==NULL||mfind(m,tdist)==0){
    m=mpush(m,tdist,curr->data);
    //inorder(m);
    }
    if(curr->left!=NULL){
    push(&queue,curr->left,tdist-1);
    }
    if(curr->right!=NULL){
    push(&queue,curr->right,tdist+1);
    }
    //printf("%d %d",m->key,m->da);
}
inorder(m);
}
struct tree* newNode(int d){
struct tree *n=(struct tree *)malloc(sizeof(struct tree));
n->data=d;
n->left=NULL;
n->right=NULL;
return n;
}
int main(){
    struct tree *root=newNode(1);
    root->right=newNode(2);
    root->right->right=newNode(5);
    root->right->right->right=newNode(6);
    root->right->right->left=newNode(3);
    root->right->right->left->right=newNode(4);
    //inorder(root);
/*int n,d;
scanf("%d",&n);
while(n>0){
        scanf("%d",&d);
        root=insert(root,d);
}*/
topview(root);
return 0;
}


