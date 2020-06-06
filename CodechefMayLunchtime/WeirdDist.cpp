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
	int *a = new int[100010];
	int *b = new int[100010];
	while(t--)
	{
		ll sum = 0;
		ll curr1 = 0;
		ll curr2 = 0;
		cin>>n;

		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}

		for(int i=0;i<n;i++)
		{

			if(curr1 == curr2 && a[i] == b[i]){
				sum +=a[i];
			}

			curr1 += a[i];
			curr2 += b[i];
		}

		cout<<sum<<endl;
	}
	delete[] a;
	delete[] b;
	return 0;
}
