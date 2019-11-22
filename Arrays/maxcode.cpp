#include<iostream> 
using namespace std;
 
void fun(int n1,int n2,int n3)
 {
 	int min[5],max[5],d[5];
 	int i1=0,i=0;
 	int arr[]={n1,n2,n3};
 	for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
 	{
 		int j=0;
			while(arr[i])
		 	{
		 		d[j]=arr[i] % 10;
		 		arr[i]=arr[i]/10;
		 		j++;
			}
			//max
			for(i1=0;i1<j;i1++)
			{
				if(d[i1]>d[i1+1])
					max[i]=d[i1];
				else
					max[i]=d[i1+1];
			}
			
			//min
			for(i1=1;i1<j;i1++)
			{
				if(d[i1]<d[i1-1])
					min[i]=d[i1];
				else
					min[i]=d[i1-1];
			}
	}
			int num;
			int mm=0;
			for(i=1;i< (sizeof(max)/sizeof(max[0]) ) ;i++)
			{
				if(max[i]>max[i-1])
					mm=max[i];
			}
			cout<<mm<<endl;
			cout<<" "<<min[2]<<" "<<min[1]<<" "<<min[0]<<endl;
			cout<<" "<<max[2]<<" "<<max[1]<<" "<<max[0];
  	
  }
  
  	
 int main()
 {
 	int n1,n2,n3;
 	cout<<"enter 1 no";
 	cin>>n1;
 	cout<<"enter 2 no";
 	cin>>n2;
 	cout<<"enter 3 no";
 	cin>>n3;
 	fun(n1,n2,n3);
 	return 0;
 }
