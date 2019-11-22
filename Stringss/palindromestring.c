#include<stdio.h>
#include<string.h>
void pallindrome(char *txt){
int l=strlen(txt);
int A[l];
int i,left,right,count=1;
for(i=0;i<l;)
{
    count =1;
    if(txt[i-1]==txt[i+1])
	{
        left=i-1;
    right=i+1;
    while((txt[left]==txt[right])&&right<=l&&left>=0)
	{
        count=count+2;
        left--;
        right++;
    }
	}
    else if(txt[i]==txt[i+1])
	{
            count=0;
        left=i;
        right=i+1;
        while((txt[left]==txt[right])&&right<=l&&left>=0)
		{
        count=count+2;
        left--;
        right++;
   	    }
    }
    A[i]=count;
    if(count!=1){
        left=i-1;
        i++;
        while((i+(A[left]/2)<right-1)){
            A[i]=A[left];
            i++;
            left--;
        }
    }
    else{
        i++;
    }
}/*
for(int i=0;i<l;i++){
    printf("index=%c val=%d\n",txt[i],A[i]);
}*/
int max=A[0],pos=0;
for(i=1;i<l;i++){
    if(A[i]>max){
        max=A[i];
        pos=i;
    }
}
//printf("%d\n%d\n",pos,max);
int strt;
if(max%2==0){
    strt=(pos-(max/2))+1;}
else{
 strt=pos-(max/2);
}
int end=(pos+max/2)+1;
//printf("%d\n",strt);
for(i=strt;i<end;i++)
    printf("%c",txt[i]);
}
int main(){
char txt[]="abacdfgdcaba";
pallindrome(txt);
}
