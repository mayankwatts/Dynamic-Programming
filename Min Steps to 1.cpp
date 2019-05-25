#include<bits/stdc++.h>
using namespace std;

int min(int a,int b){
  if(a>=b)
    return b;
  else
    return a;
}

int count(int n,int dp[]){
  
   if(n==1){
    return 0;
  }
  
  if(dp[n]!=-1){
    return dp[n];
  }
  
  int a=count(n-1,dp);
  
  if(n%2==0){
   a=min(a,count(n/2,dp));
  }
  
  if(n%3==0){
   a=min(a,count(n/3,dp));
  }
    
  dp[n]=a+1;
  return a+1;
  
}

int countStepsTo1(int n){
  
  int arr[n+1];544
  for(int i=0;i<n+1;i++){
    arr[i]=-1;
  }
  
  int a=count(n,arr);
  
  return a;
  
}

int main(){

  int n;
  cin  >> n;
  cout << countStepsTo1(n) << endl;

return 0;
}


