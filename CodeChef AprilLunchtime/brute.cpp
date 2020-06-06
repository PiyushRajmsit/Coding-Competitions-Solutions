#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
ll ans = 0;

ll maxfor(vector<int>& arr)
{

    int n = arr.size();
    if(n == 0)
		return 0;
    int mini = arr[0];
    int big = arr[n-1];

    if(mini >= 2)
        return 1;
    int last = 0;
    for(int i=0;i<n;i++)
    {

        if(arr[i]-last > 1)
        {
            return last+1;
        }
        last  = arr[i];
    }
    return big+1;
}


void solve(vector<int> &v ,int n ,int idx,vector<int>& arr)
{

    if(idx == n)
    {
        ll getans = maxfor(arr);
        ans  = (ans+getans)%mod;
		cout<<getans<<"|";
        return;
    }
    arr.push_back(v[idx]);
    solve(v,n,idx+1,arr);
    arr.pop_back();
    solve(v,n,idx+1,arr);

    return;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,k;

    while(t--)
    {
        cin>>n;
		ans = 0;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<int> v;
        solve(a,n,0,v);   
        cout<<ans+1<<endl;
        a.clear();
    }

    return 0;
}
    
