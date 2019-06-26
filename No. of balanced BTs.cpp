#include <iostream>
#include <cmath>
using namespace std;

#include<bits/stdc++.h>
long int binary(int h,int dp[]){
    if(h==1 || h==0){
        dp[h]=1;
        return 1; 
    }
    long int mod=pow(10,9)+7;
    
    if(dp[h]!=0){
        return dp[h];
    }
    
    int ans=((binary(h-1,dp)*binary(h-1,dp))%mod + (2*binary(h-1,dp)*binary(h-2,dp))%mod)%mod;
    
    dp[h]=ans;
    return ans;  
}

int binaryTreesOfHeightH(int h) {
    // Write your code here
    int dp[h+1]={};
    
    int ans=binary(h,dp);
    
    return ans;
}

int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
    
    return 0;
}
