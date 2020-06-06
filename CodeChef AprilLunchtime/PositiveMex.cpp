#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
unordered_map<int,int> mp;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}
ll power_2(ll n)
{

    if(n == 0)
        return 1;
    if(n == 1)
        return 2;

    ll small = power_2(n/2);
    small = ((small%mod)*(small%mod))%mod;
    if(n%2 == 1)
    {
        small = (small*2)%mod;
    }

    return small;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int idx = 0;
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            if(!mp.count(val))
            {
                mp[val] = idx;
                arr.push_back({val,1});
                idx++;
            }
            else
            {
                int index = mp[val];
                arr[index].second++;
            }
        }

        sort(arr.begin(),arr.end(),cmp);
        int m = arr.size();

        ll ans = 0;
        ll forw = 1;
        ll back = power_2(n);
        int rem = n;
        bool streak = true;
        ll last;
        //cout<<back<<" ";
        for(int i=0;i<m;i++)
        {
            int curr = arr[i].first;
            int freq = arr[i].second;
           //cout<<curr<<"|";
		
            rem = rem - freq;
            ll div = power_2(freq);

            if(curr == i+1)
            {
                back = back/div;
                ll sum = ((curr%mod*forw%mod)%mod *back%mod)%mod;
                ans = (ans%mod + sum%mod)%mod;

                forw = (forw%mod * (div - 1))%mod;
            }
            else{
                streak = false;
                back = back/div;
                ans = (ans + ( (curr-1)%mod * (back)%mod))%mod;
            }
            last = curr;
            
           // cout<<ans<<"|";
        }

        if(streak)
        {
            ans = (ans%mod + ( (last+1)%mod * (forw)%mod)%mod)%mod;
        }

        cout<<ans<<endl;

        arr.clear();

        mp.clear();
    }


    return 0;
}
    
