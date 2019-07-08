#include<iostream>
#include<vector>
using namespace std;

#include<bits/stdc++.h>
int solve(int n,vector<int>A){
    int maxi=0;
    for(int i=0;i<n;i++){
        if(A[i]>maxi){
            maxi=A[i];
        }
    }
    int freq[maxi+1]={};
    for(int i=0;i<n;i++){
        freq[A[i]]++;
    }
    int dp[maxi+1]={};
    dp[1]=freq[1];
    dp[2]=max(2*freq[2],dp[1]);
    for(int i=3;i<maxi+1;i++){
        dp[i]=max(i*freq[i]+dp[i-2],dp[i-1]);
    }
    
    return dp[maxi];

}

int n;
vector<int>A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
