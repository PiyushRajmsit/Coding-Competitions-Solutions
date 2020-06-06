#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
	int n,k;	
	while(t--)
	{
		int sum = 0,p;
		for(int i=0;i<5;i++)
		{
			int elem;
			cin>>elem;
			sum += elem;
		}
		cin>>p;

		sum = sum *p;

		if(sum <= 24*5)
		{
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}


	}
	return 0;
}
