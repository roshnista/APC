//intervals intersection 

#include<iostream>
#include<vector>
using namespace std;

void merge(vector< pair<int,int>  > &v)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i].second>=v[i+1].first && v[i].second<v[i+1].second)
		{
			v[i].second=v[i+1].second;
			v.erase(v.begin()+i+1);
			
		}
	}	
}

int main()
{
	vector< pair<int,int>  >v1;
	int n;
	cin>>n;
	int a[n],b[n];
	
	for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
			v1.push_back(make_pair(a[i],b[i]));
		}
	
    merge(v1);
	
		
	for(int i=0;i<v1.size();i++)
		{
			cout<<"("<<v1[i].first<<","<<v1[i].second<<")";	
		}
return 0;
}
