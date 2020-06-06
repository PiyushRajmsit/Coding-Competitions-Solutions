#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int ans = INT_MAX;

void bfs(vector<int> *adj,int curr,int end,int last,vector<int> &v,int *values)
{

	v.push_back(values[curr]);
	if(curr == end)
	{
		sort(v.begin(),v.end());
		int curr_ans = INT_MAX;

		for(int i=1;i<v.size();i++)
		{
			curr_ans = min(curr_ans,v[i] - v[i-1]);
		}
		ans = curr_ans;
		v.pop_back();
		return;
	}

	for(int i=0;i<adj[curr].size();i++)
	{

		int nxt = adj[curr][i];

		if(nxt != last)
		{
			bfs(adj,nxt,end,curr,v,values);
		}
	}

	v.pop_back();

	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
	int s,e;
	int *values = new int[200002];
	while(t--)
	{
		int n,q;
		cin>>n>>q;

		for(int i=1;i<=n;i++)
			cin>>values[i];

		vector<int> *adj = new vector<int>[n+1];
		
		for(int i=0;i<n-1;i++)
		{	

			cin>>s>>e;
			adj[s].push_back(e);
			adj[e].push_back(s);
		}

		for(int i=0;i<q;i++)
		{

			cin>>s>>e;
			vector<int> v;
			ans = INT_MAX;
			bfs(adj,s,e,-1,v,values);
			cout<<ans<<endl;
		}
		for(int i=0;i<n+1;i++)
			adj[i].clear();

	}
	delete[] values;

	return 0;
}
