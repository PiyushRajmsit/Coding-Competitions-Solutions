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
	int n,k;
	unordered_map<char,int> charA;
	unordered_map<char,int> charB;
	map<int,vector<int>> toSmaller;

	int a[30];
	int b[30];

	while(t--)
	{
		charA.clear();
		charB.clear();
		toSmaller.clear();
		
		string A,B;
		cin>>n;
		cin>>A>>B;
		//cout<<n<<" "<<A<<" "<<B;
		int len1 = A.length();
		int len2 = B.length();
		
		for(int i=0;i<30;i++)
		{
			a[i] = 0;
			b[i] = 0;
		}

		for(int i=0;i<len1;i++)
		{

			char ch1 = A[i];
			char ch2 = B[i];
			int x = A[i] - 97;
			int y = B[i] - 97;

			if(!charA.count(ch1))
			{
				charA[ch1] = i;
			}

			if(!charB.count(ch2))
			{
				charB[ch2] = i;
			}
			
			a[x] = 1;
			b[y] = 1;

		}
		bool poss = true;

		if(poss){
			for(int i=0;i<len1;i++)
			{

				int x = A[i] - 97;
				int y = B[i] - 97;

				if(x == y)
				{
					continue;
				}
				if(x > y)
				{
					int x = B[i];
					char key = x*(-1);
					if(!toSmaller.count(key))
					{
						int idex;
						if(!charA.count(B[i]))
						{
							poss = false;
							break;
						}
						else{
							idex = charA[B[i]];	
						}

						toSmaller[key].push_back(idex);
						toSmaller[key].push_back(i);
					}
					else{
						toSmaller[key].push_back(i);
					}
					
				}	
				else if (x < y ){
					poss = false;
					break;
				}
			}
		}

		if(!poss)
		{
			cout<<-1<<endl;
		}
		else{

			int ans = toSmaller.size();
			cout<<ans<<endl;

			for(auto it = toSmaller.begin();it !=toSmaller.end();it++)
			{
				vector<int> v = it->second;
				cout<<v.size()<<" ";
				for(int i=0;i<v.size();i++)
					cout<<v[i]<<" ";

				cout<<endl;
			}


		}

		charA.clear();
		charB.clear();
		toSmaller.clear();
	}
	return 0;
}
