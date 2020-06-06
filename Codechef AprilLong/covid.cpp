#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int *arr = new int[200];
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        bool state = false;
        int dist = 0;
        bool ans = true;
        int last = -1;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 1)
            {

                if(state && i-last <= 5)
                {
                    ans = false;
                    break;
                }
                else
                {
                    last = i;
                    state = true;
                }
            }
            else
            {
                if(i-last >= 6)
                {
                    state = false;
                }
            }   
        }

        if(ans)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }


    }
    delete[] arr;
	return 0;
}
