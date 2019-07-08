#include<iostream>
#include<string>
using namespace std;

string solve(int n, int x, int y){

    int dp[n+1]={};
    dp[1]=1;
    dp[x]=1;
    dp[y]=1;
    for(int i=2;i<=n;i++){
        if(i==x || i==y){
            continue;
        }
        dp[i]=dp[i-1]^1;
        if(i-x>0){
            dp[i]=dp[i]||(dp[i-x]^1);
        }
        if(i-y>0){
            dp[i]=dp[i]||(dp[i-y]^1);
        }
    }
    if(dp[n]){
        return "Beerus";
    }
    return "Whis";
}

int n,x,y;
int main()
{
	cin>>n>>x>>y;
	cout<<solve(n,x,y)<<endl;
  
  return 0;
}
