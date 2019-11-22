#include <stdio.h>

int main()
{
	 	
struct elem
{
	int val;int index;		
};
struct elem arr[10];
	


	bool cmp(const void *a,const void *b)
    {
    	return (((struct elem *)a -> val )-((struct elem *)b -> val)>=0);
	}
	
	for(int i=0;i<10;i++)
	{
		arr[i].val=arr[i];
		arr[i].index=i;
	}
	
	qsort(arr,10,sizeof(arr[0]),cmp());
    
}

