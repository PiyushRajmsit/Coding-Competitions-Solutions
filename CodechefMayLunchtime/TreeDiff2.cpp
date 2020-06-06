#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void dfs(vector<int> *adj,int *parent,int *depth,int *values,int start,int prev,int height)
{
	depth[start] = height;
	parent[start] = prev;

	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];

		if(next != prev)
		{
			dfs(adj,parent,depth,values,next,start,height+1);
		}
	}

	return;
}
int lca(int *depth,int *values,int *parent,int s,int e)
{

	int bucket[101] = {0};
	int bucketsize = 0;
	int idx;
	int ans = INT_MAX;
	while(s != e)
	{	

		if(depth[s] > depth[e])
		{
			idx = s;
			bucket[values[s]]++;
			bucketsize++;
			s = parent[s];
		}
		else{
			idx = e;
			bucket[values[e]]++;
			bucketsize++;
			e = parent[e];
		}
		if(bucketsize >=101)
		{
			ans = 0;
			break;
		}
		if(bucket[values[idx]] >=2)
		{
			ans = 0;
			break;
		}
	}
	bucket[values[s]]++;

	if(ans == 0)
		return ans;

	int last = -100;
	for(int i=1;i<=100;i++)
	{
		if(bucket[i] == 0)
			continue;

		if(bucket[i] >=2)
		{
			ans = 0;
			break;
		}
		else{
			ans = min(ans,i-last);
			last = i;
		}
	}	

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
	int s,e;
	int *values = new int[200002];
	int *parent = new int[200002];
	int *depth  = new int[200002];
	while(t--)
	{
		int n,q;
		cin>>n>>q;

		for(int i=1;i<=n;i++)
		{
			cin>>values[i];
			parent[i] = i;
			depth[i] = 0;
		}

		vector<int> *adj = new vector<int>[n+1];
		
		for(int i=0;i<n-1;i++)
		{	

			cin>>s>>e;
			adj[s].push_back(e);
			adj[e].push_back(s);
		}

		dfs(adj,parent,depth,values,1,1,0);

		for(int i=0;i<q;i++)
		{
			cin>>s>>e;

			int ans =  lca(depth,values,parent,s,e);
			cout<<ans<<endl;
		}
		for(int i=0;i<n+1;i++)
			adj[i].clear();

		delete[] adj;			
	}
	delete[] values;
	delete[] parent;
	delete[] depth;

	return 0;
}
