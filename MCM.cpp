#include<iostream>
#include<climits>
using namespace std;

int mcm(int* p,int s,int e,int** dp){
    if(e-s==1 || e-s==0){
        return 0;
    }
    int mins=INT_MAX;
    for(int i=s+1;i<e;i++){
        if(dp[s][i]!=-1 && dp[i][e]!=-1){
            mins=min(mins,dp[s][i]+dp[i][e]+(p[s]*p[i]*p[e]));
        }
        else if(dp[s][i]!=-1 && dp[i][e]==-1){
            mins=min(mins,dp[s][i]+mcm(p,i,e,dp)+(p[s]*p[i]*p[e]));
        }
        else if(dp[s][i]==-1 && dp[i][e]!=-1){
            mins=min(mins,mcm(p,s,i,dp)+dp[i][e]+(p[s]*p[i]*p[e]));
        }
        else{
            mins=min(mins,mcm(p,s,i,dp)+mcm(p,i,e,dp)+(p[s]*p[i]*p[e]));
        }
    }
    
    return dp[s][e]=mins;
}
int mcm(int* p, int n){
    
    int** dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    
    int ans=mcm(p,0,n,dp);
    delete[] dp;

    return ans;
}

int main(){

  int n; 
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i <= n; i++){
    cin >> p[i];
  }

  cout << mcm(p, n);
  
  return 0;
}


