#include<stdio.h>

int countPairs(int numbers_count, int* numbers, int k) 
{
    int i=0,j=0,size=numbers_count;
    int p[numbers_count],l[numbers_count];
    int c=0,m=0,k1=0;
    
   for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(numbers[i] == numbers[j])
            {
                
                for(k1=j; k1<size; k1++)
                {
                    numbers[k1] = numbers[k1 + 1];
                }
                size--;
                j--;
            }
        }
    }
    
   int ii,jj;
   
  
    for(ii=0;ii<size;ii++)
    {
        for(jj=ii+1;jj<size;jj++)
        {
        	
            if( numbers[ii]+k == numbers[jj] )
            {
                c++;
                
            }
        }
    }
    return c;
}

int main()
{
	int a[10]={1,1,2,2,3,3};
	int x=countPairs(6,a,1);
	printf("%d",x);
}
