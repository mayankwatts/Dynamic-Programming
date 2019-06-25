#include <iostream>
using namespace std;

void lis(int arr[],int n,int index,int dp[]){
    if(index==n){
        return;
    }
    int flag=0;
    int a=index;
    a--;
    while(a>=0){
        if(flag==0 && arr[a]==arr[index]){
            arr[index]=arr[a];
            lis(arr,n,index+1,dp);
            return;
        }
        if(arr[a]<arr[index] && dp[arr[a]]>=dp[arr[index]]){
            dp[arr[index]]=dp[arr[a]];
            flag=1;
        }  
        a--;
    }
    
    dp[arr[index]]+=1;
    
    lis(arr,n,index+1,dp);
    
    return;   
}

 int lis(int arr[], int n) {
     int max=0;
     for(int i=0;i<n;i++){
         if(max<arr[i]){
             max=arr[i];
         }
     }
     
     int dp[max+1]={0};
     lis(arr,n,0,dp);
     
     int ans=0;
     for(int i=0;i<max+1;i++){
         if(dp[i]>ans){
             ans=dp[i];
         }
     }
     
     return ans;
 }

int main(){
    int n;
    cin >> n;
    int arr[100000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << lis(arr, n);
    
    return 0;
}

