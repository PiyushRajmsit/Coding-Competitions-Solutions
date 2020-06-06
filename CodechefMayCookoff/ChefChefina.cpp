#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void computeLPSArray(string &pat, int M, int* lps) 
{ 
    int len = 0; 
  
    lps[0] = 0;  
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            if (len != 0) { 
                len = lps[len - 1]; 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
	int n,k;
	int *lps1 = new int[100010];
	int *lps2 = new int[100010];
	
	while(t--)
	{
		string s1;
		cin>>s1;
		int len = s1.length();
			
		if(len %2 == 1)
		{
			cout<<0<<endl;
			continue;
		}
		computeLPSArray(s1,len,lps1);
		string s2 = s1;

		reverse(s2.begin(),s2.end());
		computeLPSArray(s2,len,lps2);
		

		int ans = 0;

		for(int i=0;i<len;i++)
			cout<<lps1[i]<<" ";
		cout<<endl;
		for (int i = 0; i < len; ++i)
		{
			cout<<lps2[i]<<" ";
		}
		cout<<endl;


		for(int i=1;i<len;i+=2)
		{
			int curr_len = i-0+1;

			if(i+curr_len >=len)
			{
				break;
			}
			else
			{
				
				int idx2 = i + curr_len;
				if(curr_len <= lps1[idx2])
				{
					cout<<idx2<<" "<<curr_len<<"|";
					int rem_length = len - 2*curr_len;
					if(rem_length %2 == 0)
					{
						if(lps2[rem_length - 1] >= rem_length/2)
						{
							ans++;
						}
					}

				}
			}

		}

		cout<<ans<<endl;

	}
	delete[] lps1;
	delete[] lps2;
	return 0;
}
