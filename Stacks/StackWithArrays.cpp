//make a stack using arrays

#include<iostream>
#define max 5
using namespace std;

int main()
{
	int stack[max];
	int elem,r;
	int top=-1;
	
	cout<<"enter element to stack";


//push
while(top<max-1)
{
		top++;
		cin>>elem;	
		stack[top]=elem;
		
}

//peek
cout<<stack[top]<<endl;

//pop

while(top!=-1)	
{
	r=stack[top];
	cout<<r<<"  ";
	top--;
}
return 0;
}
