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
	int *arr = new int[2000];
	unordered_map<int,int> mp;
	unordered_map<int,int> occ;
	while(t--)
	{
		cin>>n;

		for(int i=0;i<n;i++)
			cin>>arr[i];

		int idx = 0;
		bool ans = true;
		while(idx < n)
		{
			if(mp.count(arr[idx]))
			{
				ans = false;
				break;
			}
			else
			{
				int j = idx;
				int c = 0;
				while(j<n && arr[j] == arr[idx])
				{
					j++;
				}
				int tot = j-idx+1;

				if(occ.count(tot))
				{
					ans = false;
					break;
				}
				else{
					
					occ[tot] = 1;
				}
				mp[arr[idx]] = 1;
				idx = j;
			}
		}

		if(ans)
		{
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}


		mp.clear();
		occ.clear();
	}
	delete[] arr;
	return 0;
}
