#include<iostream>
using namespace std;

int min(int n,int dp[]){
  
  if(n<=3)
  {
    return n;
  }
  if(dp[n]!=0){
    return dp[n];
  }
  
  int a=n;
  
  for(int i=1;i<n+1;i++)
  {
    int b=i*i;
    if(b>n)
    {
      break;
    }
    
    else
    {
      int c=1+min(n-b,dp);
      if(a>c)
      {
        a=c;
      }
    }
  }

  dp[n]=a;
return a;
 
}

int minCount(int n){
    
    int dp[n+1]={};
  int a=min(n,dp);
  
  return a;
    
}

int main(){
    
    int num;
    cin >> num;
    cout << minCount(num);
    
    return 0;
}
