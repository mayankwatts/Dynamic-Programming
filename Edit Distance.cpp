#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int editDistance(string s1, string s2){
    
    int m=s1.length();
    int n=s2.length();
    int** dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
    }
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i]==s2[n-j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    
    int ans=dp[m][n];
    for(int i=0;i<=m;i++){
        delete[] dp[i];
    }
    delete[] dp;
    
    return ans;

}


int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}


