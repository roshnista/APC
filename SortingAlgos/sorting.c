#include<stdio.h>

//void merge(int *arr,int left,int mid,int right)
//{
//	int n1=mid-left+1;
//	int n2=right-mid;
//	int arr1[n1];
//	int arr2[n2];
//	int i=0,j=0,k=0;
//	while(i<n1 && j<n2)
//	{
//		if(arr1[i]<=arr2[j])
//			arr[left+k]=arr[i];
//		
//		while(i<n1)
//		{
//			arr[left+k]=arr1[i];
//			i++;
//			k++;
//		}
//		
//	}
//}

void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];	//array used for merging
	int i,j,k;
	i=i1;	//beginning of the first list
	j=i2;	//beginning of the second list
	k=0;
	
	while(i<=j1 && j<=j2)	//while elements in both lists
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=j1)	//copy remaining elements of the first list
		temp[k++]=a[i++];
		
	while(j<=j2)	//copy remaining elements of the second list
		temp[k++]=a[j++];
		
	//Transfer elements from temp[] back to a[]
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}

void mergesort(int *a,int left,int right)
{
	int mid;
	if(left<right)
	{
	mid=left+(right-left)/2;
	mergesort(a,left,mid);
	mergesort(a,mid+1,right);
	merge(a,left,mid,mid+1,right);
	}
}


int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	mergesort(a,0,n-1);
	
	//after sorting 
	for( i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
	return 0;
}
