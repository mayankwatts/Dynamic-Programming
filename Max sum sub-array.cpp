#include <iostream>
#include <cstring>
#include <algorithm>
#include<climits>
using namespace std;

void findsum(int arr[],int n,int dp[],int index){
    if(index==n){
        return;
    }
    if(index!=0 && arr[index]+dp[index-1]>arr[index]){
        dp[index]=arr[index]+dp[index-1];
    }
    else{
        dp[index]=arr[index];
    }
    findsum(arr,n,dp,index+1);
}

int findSum(int arr[],int n){
    int dp[n]={0};
    findsum(arr,n,dp,0);
    int ans=INT_MIN;
    
    for(int i=0;i<n;i++){
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    
    return ans;
}
 
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
	cout<<findSum(arr,n);

    return 0;
}
