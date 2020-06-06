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
	int n;
	int *arr = new int[100];
	while(t--)
	{
		cin>>n;

		for(int i=0;i<n;i++)
			cin>>arr[i];

		sort(arr,arr+n);

		int high = 0;
		int low = n+1;
		int last = arr[0];
		int curr = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i] - last <= 2 )
				curr++;
			else{
				low = min(low,curr);
				curr = 1;
			}
			last = arr[i];
			high = max(high,curr);
		}
		
		low = min(low,curr);
		
		if(high == n)
			low = high;
		
		cout<<low<<" "<<high<<endl;

	}
	delete[] arr;
	return 0;
}
