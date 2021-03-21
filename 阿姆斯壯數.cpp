#include <iostream>
#define endl '\n'
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(0);
	long long int a,b;
	while(cin>>a>>b)
	{
		long long int c[24]={1,2,3,4,5,6,7,8,9,153,370,371,407,1634,8208,9474,54748,92727,93084,548834,1741725,4210818,9800817,9926315}, f=0;
		for (int i=0;i<24;i++) 
		{
			if (c[i]>=a&&c[i]<=b) 
			{
				if (c[i]>b) 
				{
					break;
				}
				f=f+1;
				cout<<c[i]<<" ";
			}
		}
		if(f==0)
		{
			cout<<"none";
		} 
		cout<<endl;
	}
}
