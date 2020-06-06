#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);

        if(n <= 3)
        {
            cout<<1<<endl<<n<<" ";
            for(int i=1;i<=n;i++)
                cout<<i<<" ";
                cout<<endl;
        }
        else
        {
            int d = n/2;
            cout<<d<<endl;
            string s1 = "3 1 2 3\n";
            int j=4;
            
            while(j<=n)
            {
                if(j>n)
                    break;
                if(j<=n && j+1<=n)
                {
                 //   cout<<"2 "<<j<<" "<<j+1<<endl;
					s1 +="2 ";
					s1 +=to_string(j);
					s1 +=" ";
					s1 +=to_string(j+1);
					s1 +="\n";
                }
                else if(j == n)
                {
                  s1 +="1 "+to_string(j)+"\n";
                }
                j +=2;
                
            }
            cout<<s1;
        }

    }
    return 0;
}
