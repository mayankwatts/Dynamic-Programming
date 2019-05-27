#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int ans(string input,int size){
    int *output=new int[size+1];
    output[0]=1;
    output[1]=1;
    for(int i=2;i<size+1;i++){
        output[i]=0;
        if(input[i-1]!='0')
            output[i]=output[i-1];
        int num=input[i-1]-'0' + (input[i-2]-'0')*10;
        if(num>=10 && num<=26){
            output[i]=(output[i]%mod + output[i-2]%mod)%mod;
        }
    }
  return output[size];
  
}

int main()
{
  string input;
  cin>>input;
  
  while(input!="0"){
      cout<<ans(input,input.length())<<endl;
    cin>>input;
  }
    return 0;
}
