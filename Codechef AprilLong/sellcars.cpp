#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool cmp(int a,int b)
{

    return a>b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int *arr = new int[100010];
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];

        ll ans = 0;

        sort(arr,arr+n,cmp);


        for(int i=0;i<n;i++)
        {
            ll curr = max(arr[i]-i,0);
            ans = (ans + curr)%mod;
        }
        cout<<ans%mod<<endl;

    }
    delete[] arr;
    return 0;
}
