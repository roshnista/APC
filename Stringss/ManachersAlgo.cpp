#include<iostream>
#include<string.h>
using namespace std;
#define SIZE 100000
int p[SIZE * 2];

int main()
{
    string s;
    getline(cin,s);
    string a="@";
    for(int i=0;i<s.size();i++)
    {
        a=a+"#"+s.substr(i,1);
    }
    a=a+"#$";
    
    //array of substr
    int c=0,r=0;
    for(int i=1;i<a.size()-1;i++)
    {
        int m=c-(i-c);
        if(r>i)
            p[i]=min(r-i,p[m]);
        while(a[i+1+p[i]]==a[i-1-p[i]])
            p[i]++;
        if(p[i]+i>r)
            {
                c=i;
                r=p[i]+i;
            }
    }
    
    //print longest substring
    int max=0;
    int index=0;
    for(int i=1;i<a.size()-1;i++)
    {
        
        if(p[i]>max)
            {
                max=p[i];
                index=i;
            }
    }
    cout<<max<<endl;
    string c1=s.substr((index-1-max)/2,max);
    cout<<c1;
   

}

