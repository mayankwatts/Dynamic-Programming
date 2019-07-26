#include<iostream>
using namespace std;

int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int maxi=0;
    for(int i=0;i<row;i++){
        arr[i][0]^=1;
        if(maxi<arr[i][0]){
            maxi=arr[i][0];
        }
    }
    for(int i=1;i<col;i++){
        arr[0][i]^=1;
        if(maxi<arr[0][i]){
            maxi=arr[0][i];
        }
    }
    
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j]==1){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=1+min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]));
            }
            
            if(maxi<arr[i][j]){
                maxi=arr[i][j];
            }
        }
    }
    
    return maxi;  
}

int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}
