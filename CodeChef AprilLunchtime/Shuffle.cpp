#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,k;
    int *a = new int[100010];
    while(t--){

        cin>>n>>k;
        if(k == 1)
        {
			for(int i=0;i<n;i++)
                cin>>a[i];
            cout<<"yes"<<endl;
        }
        else
        {
            int row = k;
            int col = (n/k) + 1;

            vector<vector<int>> arr(row);
            for(int i=0;i<n;i++)
                cin>>a[i];
            
            int r = 0;
            int c = 0;
            
            for(int i=0;i<n;i++){
                r = i%k;
                arr[r].push_back(a[i]);
            }

            for(int i=0;i<row;i++)
            {
                sort(arr[i].begin(),arr[i].end());
            }

            string ans = "yes";
            r = 0;
            c = 0;
            int last  =  arr[0][0];
            for (int i = 1; i < n; ++i)
            {

                r = i%k;
                c = i/k;
                //cout<<arr[r][c]<<"|";
                if(arr[r][c] < last)
                {
                    ans = "no";
                    break;
                }
    
                last  = arr[r][c];
            }
            
            cout<<ans<<endl;
            arr.clear();
        }
        
    }
    delete[] a;
    return 0;
}
    
