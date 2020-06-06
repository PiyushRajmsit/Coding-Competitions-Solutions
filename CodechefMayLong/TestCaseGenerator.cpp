#include <iostream>
#include <bits/stdc++.h>
using namespace std;
	
ofstream outfile;
int fact(int n) 
{ 
    return (n==1 || n==0) ? 1: n * fact(n - 1);  
} 

void generate(int count,bool *mark,int n,string s){

	if(count == n)
	{
		int k = rand() % 4;
		outfile<<n;
		outfile<<" ";
		outfile<<k;
		outfile<<"/n";
		outfile<<s;
		outfile<<"/n";
		return;
	}

	for(int i=1;i<=n;i++)
	{
		if(!mark[i]){
			mark[i] = true;
			string s1 = to_string(i) + " ";		
			generate(count+1,mark,n,s+s1);
			mark[i] = false;
		}
	}
}


void generator(int n)
{
	bool *visit = new bool[n+1];
	
	for(int i=1;i<=n;i++)
		visit[i] = false;
	
	generate(0,visit,n,"");

	delete[] visit;
	return;
}


void generateCases()
{
	
	int arr[] = {5,4,6};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int testCase = 0;
	
	for(int i=0;i<n;i++)
	{
		testCase += fact(arr[i]);
	}
	outfile<<testCase;
	outfile<<"\n";
	
	for(int i=0;i<n;i++)
	{
		generator(arr[i]);
	}
	
}


int main()
{
    outfile.open("testcase.txt", ios::out);
	 
	generateCases();
	outfile.close();
	return 0;
}
