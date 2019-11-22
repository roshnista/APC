 //absolute difference 
 #include<iostream>
 using namespace std;
 int main()
 {
 	int a[]={1,4,5,8,10};
 	int b[]={6,9,15};
 	int c[]={2,3,6,6};
 	
 	int n1=5,n2=3,n3=4;
 	int i=0,k=0,j=0;
 	int min,max,cc,index,d=10000;	
 		
 	while(i<n1 && j<n2 && k<n3)
 	{
 		if(a[i]>b[j] && a[i]>c[k])
 			max=a[i];
 		else if(b[j]>c[k])
 			max=b[j];
 		else
 			max=c[k];
	 
	 	if(a[i]<b[j] && a[i]<c[k])
 			min=a[i];
 		else if(b[j]<c[k])
 			min=b[j];
 		else
			min=c[k];
		
		
		if(max-min<d)
			d=max-min;
			if(min==a[i])
				i++;
			else if(min==b[i])
				j++;
			else
				k++;
		
	}
 	cout<<d;
 	
 	return 0;
 }
