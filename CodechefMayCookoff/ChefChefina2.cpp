#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
	bool *l = new bool[100010];
	bool *r = new bool[100010];
	while(t--)
	{
		

		string s;
		cin>>s;
		int len = s.length();

		if(len % 2 != 0)
		{
			cout<<0<<endl;
		}
		else{

			for(int i=0;i<=len;i++)
			{
				l[i] = false;
				r[i] = false;
			}

			ll h1 = 0,h2 = 0;
			// Left string check hash function
			ll shift_count = 1;
			ll curr_count = 1;
			ll mid = -1;
			for(int i=0;i<len;i++)
			{
				// No shift
				if(curr_count % 2  == 1)
				{
					h2 = ((h2*10)%mod + ((ll)s[i])%mod)%mod; 
				}
				// requires shift
				else{

					mid++;
					h2 = ((h2%mod - ((ll)(s[mid] * shift_count))%mod)+ mod)%mod;
					h2 = ((h2*10)%mod + ((ll)s[i])%mod)%mod; 
					h1 = ((h1*10)%mod + ((ll)s[mid])%mod)%mod;
					shift_count = (shift_count*10)%mod;
					if(h1 == h2)
					{
						l[i] = true;
					}
				}

				// cout<<h1<<" "<<h2<<"|";
				curr_count++;
			}
			// Right string check hash function
			h1 = 0;h2 = 0;
			shift_count = 1;
			curr_count = 1;
			mid = -1;
			reverse(s.begin(),s.end());
			// cout<<s<<endl;
			for(int i=0;i<len;i++)
			{
				// No shift
				if(curr_count % 2  == 1)
				{
					h2 = ((h2*10)%mod + ((ll)s[i])%mod)%mod; 
				}
				// requires shift
				else{

					mid++;
					
					h2 = ((h2%mod - ((ll)(s[mid] * shift_count))%mod)+ mod)%mod;
					h2 = ((h2*10)%mod + ((ll)s[i])%mod)%mod; 
					h1 = ((h1*10)%mod + ((ll)s[mid])%mod)%mod;
					shift_count = (shift_count*10)%mod;
					if(h1 == h2)
					{
						r[i] = true;
					}
				}

				// cout<<h1<<" "<<h2<<"|";
				curr_count++;
			}
			int ans = 0;
			for(int i=1;i<len-1;i++)
			{
				if(l[i] == true && r[len-i-2] == true)
					ans++;
			
			}
			

			cout<<ans<<endl;
		}
	}
	delete[] l;
	delete[] r;

	return 0;
}
