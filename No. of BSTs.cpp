#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000000007
int countBST( int n)
{
    int dp[n+1];
    
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<n+1;i++){
        int x=0;
        for(int j=0;j<i;j++){
            x=(x%mod+((dp[j]%mod)*(dp[i-j-1]%mod))%mod)%mod;
        }
        dp[i]=x%mod;
        
    }
    
    return dp[n];
}


int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
