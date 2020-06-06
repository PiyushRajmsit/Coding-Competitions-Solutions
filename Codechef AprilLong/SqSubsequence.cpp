#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    int *arr = new int[100010];
    while(t--)
    {
       
       cin>>n;
       for(int i = 0;i<n;i++)
       {
            cin>>arr[i];
       }

       ll add = ((ll)n * (ll)(n+1))/2;

       ll sub = 0;
       ll last = -1;
       ll mid = -1;
       for(int i=0;i<n;i++)
       {
           
           if(arr[i]%4 == 0){
               
               if(mid != -1)
               {
                   
                    ll back = mid - last;
                    ll front = i-mid;
                    sub += back*front;
               }
               last = i;
               mid = -1;
               
           }
           
           
            else if(arr[i]%2 == 0)
            {
                if(mid == -1)
                {
                    mid = i;
                }
                else
                {
                    ll back = mid - last;
                    ll front = i-mid;
                    sub += back*front;

                    last = mid;
                    mid = i;
                }
            }
       }

       if(mid != -1)
       {
        sub += ((ll)n-mid)*(mid-last);
       }
       //cout<<add<<" "<<sub<<"| ";
       ll ans = add-sub;

       cout<<ans<<endl;


    }
    delete[] arr;
    return 0;
}
