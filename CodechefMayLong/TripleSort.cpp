#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<vector<int>> even;
vector<vector<int>> odd;
vector<int> loop;
vector<int> merger;
int even_count = 0;
int odd_count = 0;
int tot_even = 0;
int tot_odd = 0;
int doLoop(int& count,int index,int *arr,bool *mark)
{
	if(mark[index])
	{	
		if(count%2 == 0)
		{
			even_count++;
			even.push_back(loop);
			tot_even +=count;
		}
		else{
			odd_count++;
			odd.push_back(loop);
			tot_odd += count;
		}

		return 0;
	}
	
	mark[index] = true;
	loop.push_back(index);
	count++;	
	int res = 1 + doLoop(count,arr[index],arr,mark);
	loop.pop_back();
	return res;

}

int pick(int *arr,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(arr[i] == i)
			return i;
	}
	return 1;
}
void rearrange(int op,int *arr,int row,int index,int n)
{


	int i1,i2,i3;	
	if(op == 1)
	{
		i1 = odd[row][index];
		i2 = odd[row][index+1];
		i3 = odd[row][index+2];

	}
	else if(op == 2) {
		i1 = merger[index];
		i2 = merger[index+1];
		i3 = merger[index+2];		
	}
	else
	{
		int n1 = even[row].size()-1;
		i1 = even[row][n1];
		i2 = even[row+1][0];
		i3 = index;
	}


	int v1 = arr[i1];
	int v2 = arr[i2];
	int v3 = arr[i3];
	
	arr[i1] = v3;
	arr[i2] = v1;
	arr[i3] = v2;


	cout<<"|| Sorting Part Array =>";
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
	
	
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
	int n,k;
	int *arr = new int[200010];
	bool *mark = new bool[200010];
	while(t--)
	{
		cin>>n>>k;

		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
			mark[i] = false;
		}

		int rem = n;
		for(int i=1;i<=n;i++)
		{
			if(arr[i] == i)
			{
				rem--;
			}
		}
		
		if(rem - k*3 >= 1){
			cout<<-1<<endl;
		}
		else
		{
			bool ever = true;
			int operations_count = 0;
			int row_count  = 0;
			even_count = 0;
			odd_count = 0;
			tot_even = 0;
			tot_odd = 0;	
			for(int i=1;i<=n;i++)
			{
				if(!mark[i])
				{
					int c = 0;
					int count = doLoop(c,i,arr,mark);

					if(count%2 == 1)
					{
						operations_count += (count/2);
					}

				}
			}
			//operations_count = (tot_even+tot_odd)/2 + (even_count/2);
			operations_count = operations_count + (tot_even/2) + (even_count/2);
			if(odd_count == 0 || even_count%2 == 1 || operations_count > k)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<operations_count<<endl;
				for (int i = 0; i < odd_count; ++i)
				{
					int n_row = odd[i].size()-1;
					int index = n_row -  2; 
					while(index >= 0)
					{
						for(int j=index;j<=index+2;j++)
						{
							cout<<odd[i][j]<<" ";
						}
						// rearrange(1,arr,i,index,n);
						cout<<endl;
						index = index - 2;
					}
				}
				// All odd Length Loops sorted
				int row = 0;
				int idx = pick(arr,n);
				while(row < even_count)
				{
					int i = row;
					int n1 = even[i].size() - 1;
					int n2 = even[i+1].size() - 1;
					cout<<even[i][n1]<<" "<<even[i+1][0]<<" "<<idx;
					// rearrange(3,arr,i,idx,n);
					cout<<endl;
					merger.insert(merger.begin(),even[i].begin(),even[i].end());
					merger.push_back(idx);
					merger.insert(merger.end(),even[i+1].begin()+1,even[i+1].end());
					merger.push_back(even[i+1][0]);

					int n_row = merger.size()-1;
					int index = n_row -  2; 
					while(index >= 0)
					{
						for(int j=index;j<=index+2;j++)
						{
							cout<<merger[j]<<" ";
						}
						//rearrange(2,arr,i,index,n);
						cout<<endl;
						index = index - 2;
					}
					merger.clear();
					row = row+2;
				}


			}

			
		}
		odd.clear();
		even.clear();
		
	}
	delete[] arr;
	delete[] mark;
	return 0;
}
