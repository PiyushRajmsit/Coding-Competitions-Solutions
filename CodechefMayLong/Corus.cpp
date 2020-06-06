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
	int n,q;
	int arr[28];
	while(t--)
	{
		
		for(int i=0;i<28;i++)
			arr[i] = 0;

		cin>>n>>q;
		string s1;
		cin>>s1;
		int len = s1.length();
		//cout<<len<<" | "<<endl;

		for(int i=0;i<len;i++)
		{
			arr[s1[i]-97]++;
		}

		// for(int i=0;i<28;i++)
		// {

		// 	cout<<arr[i]<<" ";
		// }
		// cout<<endl;

		while(q--)
		{
			int c; 
			cin>>c;
			int ans = 0;
			for(int i=0;i<26;i++)
			{
				ans += max(arr[i]-c,0);
			}
			cout<<ans<<endl;
		}

	}
	return 0;
}
