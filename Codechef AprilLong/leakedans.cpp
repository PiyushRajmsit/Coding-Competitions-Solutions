#include <bits/stdc++.h>
using namespace std;
#define ll long long

void intial(int *arr,int n)
{

    for(int i=0;i<n;i++)
        arr[i] = 0;
}

void intialbool(bool *arr,int n)
{
    for(int i=0;i<=n;i++)
        arr[i] = false;

    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // scanf("%d",&t);
    cin>>t;    
    int **arr = new int*[510];
    for (int i = 0; i < 510; ++i)
    {
        arr[i] = new int[100010];
    }
    bool *row_check = new bool[510];
    int *miss_chance = new int[100010];

    int *ans =  new int[11];
    int *curr = new int[11];
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        bool allsame;
        intial(ans,11);
        intial(curr,11);
        intialbool(row_check,n+1);
        intial(miss_chance,k+1);
        int perfect_rows = 0;
        for (int i = 0; i < n; ++i)
        {
            allsame = true;
            for (int j = 0; j < k; ++j)
            {
                int elem;
                cin>>elem;
                arr[i][j] = elem;

                if(allsame)
                {
                    if(elem != arr[i][0])
                        allsame  = false;
                }

            }
            row_check[i] = allsame;
        }

        for (int i = 0; i < n; ++i)
        {
            if(!row_check[i])
                ans[arr[i][0]]++;
            else
            {
                perfect_rows++;
            }
        }
     //for(int i=1;i<=m;i++)
     //    cout<<ans[i]<<" ";

        for(int i=1;i<k;i++)
        {
            intial(curr,11);
            for(int j=0;j<n;j++)
            {
                if(!row_check[j])
                {
                    curr[arr[j][i]]++;
                }
            }

            for(int r=1;r<=m;r++)
            {
                // cout<<curr[r]<<" ";
                ans[r] = min(ans[r],curr[r]);
            }
        }

        int every_ans = 1;
        int maximum_freq = 0;
        
        for(int i=1;i<=m;i++)
        {   
            // cout<<ans[i]<<" ";
            if(ans[i] > maximum_freq)
            {
                maximum_freq = ans[i];
                every_ans = i;
            }
        }

        int diag_count = n - perfect_rows;

        maximum_freq = -1;
        if(maximum_freq >= diag_count)
        {
            for(int i=0;i<n;i++)
            {
                
                if(row_check[i])
                {
                    cout<<arr[i][0]<<" ";
                }
                else
                {
                    cout<<every_ans<<" ";   
                }
            }      
        }
        else
        {
            int row = 0;
            int col = 0;
            for(int i=0;i<n;i++)
            {
                if(row_check[i])
                {
                    cout<<arr[i][0]<<" ";
                    row++;   
                }
                else
                {

                    if(miss_chance[col] >= 1)
                    {
                        miss_chance[col]--;
                        int column;

                        for(int c=1;c<=k;c++)
                        {
                            column = (col+c)%k;
                            if(miss_chance[column] >= 1)
                            {
                                miss_chance[column]--;
                            }
                            else if(miss_chance[column] == 0)
                            {
                                break;
                            }
                        }

                        col = column;
                        int elem = arr[row][col];

                        for(int c=1;c<=k-1;c++)
                        {
                            column = (col+c)%k;
                            if(elem == arr[row][column])
                            {
                                miss_chance[column]++;
                            }

                        }                            
                        cout<<elem<<" ";
                    }
                    else
                    {

                        int column;
                        int elem = arr[row][col];

                        for(int c=1;c<=k-1;c++)
                        {
                            column = (col+c)%k;

                            if(elem == arr[row][column])
                            {
                                miss_chance[column]++;
                            }

                        }                            
                        cout<<elem<<" ";

                    }
                    row = (row+1);
                    col = (col+1)%k;
                }

            }

        }
        
        cout<<endl;
    }

    for (int i = 0; i < 510; ++i)
        delete[] arr[i];

    delete[] arr;
    delete[] ans;
    delete[] curr;
    delete[] row_check;
    delete[] miss_chance;
    return 0;
}
//Not fully correct Wrong ans
//Try to select column so most row get selected
