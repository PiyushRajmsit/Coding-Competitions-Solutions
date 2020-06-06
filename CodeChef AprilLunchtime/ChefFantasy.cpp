#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    int a[101];
    int b[101];
    int c[101];
    while(t--){

        int n,s;
        cin>>n>>s;

        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }

        int x = 0;
        int y = 0;
        int val;
        for(int i=0;i<n;i++)
        {
            cin>>val;

            if(val)
            {
                a[x] = c[i];
                x++;
            }
            else{
                b[y] = c[i];
                y++;
            }
        }

        sort(a,a+x);
        sort(b,b+y);
        bool ans = true;
        if(x <=0  || y<= 0)
        {
            ans = false;
        }

        int total = s + a[0]+b[0];

        if(total > 100)
        {
            ans = false;
        }

        if(ans)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }


    }

    return 0;
}
    
