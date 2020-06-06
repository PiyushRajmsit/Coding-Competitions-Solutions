#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool cmp(int a,int b)
{

    return a>b;
}

bool check(ll x,ll k)
{

    ll num = 1;
    bool ans = true;
    for(int i=1;i<=k;i++)
    {
        num = num*2;
        if(num>x)
        {
            return false;
        }
    }

    return true;
}

ll returnFactor(ll num)
{

    bool found = false;
    ll factor_value = -1;
    for(int ll i = 2;i*i<=num;i++)
    {
        if(num % i == 0)
        {
            found = true;
            factor_value = i;
            break;
        }
    }

    if(!found)
    {
        return num;
    }

    return factor_value;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll x,k;
        cin>>x>>k;


        bool poss = check(x,k);

        if(!poss)
        {
            cout<<0<<endl;
        }
        else
        {

            ll start = x;
            ll factors_remaining = k;
            while(factors_remaining > 1)
            {
                ll factor = returnFactor(start);
                start = start/factor;

                if(start == 1)
                    break;

                factors_remaining--;
            }

            if(factors_remaining == 1)
            {
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }

        }



    }
    return 0;
}
