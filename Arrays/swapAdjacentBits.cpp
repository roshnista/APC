//swap adjacent bits
#include<iostream>
using namespace std;
int main()
{
	int n,y,x;
	cin>>n;
	x=(n>>1)&(0b01010101); // 0x55
	y=(n<<1)&(0b10101010); // 0xAA
	cout<< (x|y);	
		
	
return 0;
}
