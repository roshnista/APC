#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{	
	vector< pair<int,int> >v;
	int a[]={34, 8, 10, 3, 2, 80, 30, 33, 1};
	int n=9;
	 
	for(int i=0;i<n;i++)
		v.push_back(make_pair(a[i],i));
		
	sort(v.begin(), v.end());

	int max=0;
	int min=v[0].second;
	
	
	for(int i=1;i<n;i++)
	{
		if(v[i].second-min>max)
			max=v[i].second-min;
		if(v[i].second<min)
			min=v[i].second;
	}
	
	
	cout<<max;

return 0;
}



