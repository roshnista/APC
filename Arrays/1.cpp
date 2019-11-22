#include<stdio.h>
#include<conio.h>
int main()
{
int r,c;
printf("Enter the size of array");
scanf("%d %d",&r,&c);
printf("Enter the elements of matrix");
int arr[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0)
            {
            arr[i][j]=2;
            }
        }
    }
    
    
    
    
    
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==2)
        {
            arr[i][j]=0;
        for(int k=0;k<r;k++)
        {
            //if(arr[k][j]==1)
            arr[k][j]=0;
        }
        for(int z=0;z<c;z++)
        {
            //if(arr[i][z]==1)
            arr[i][z]=0;
        }
        }
    }
}












for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }

}
