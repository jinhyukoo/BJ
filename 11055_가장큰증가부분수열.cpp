#include<iostream>
using namespace std;
int main(void){
  int num[1001], dp[1001], count, r = 0;
  cin>>count;
  for(int i = 0 ;i<count;i++){
    cin>>num[i];
  }
  dp[0] = num[0];
  for(int i = 1;i<count;i++){
    if(num[i]>num[i-1]) dp[i] = dp[i-1] + num[i];
    else{
      int m = 0;
      for(int j = 0;j<i;j++){
        if(num[j]<num[i] && dp[m]<dp[j]){
          m = j;
          cout<<m<<endl;
        }
      }
      if(m==0){
        dp[i] = num[i];
      }
      else{
        dp[i] = dp[m] + num[i];
      }
    }
  }
  for(int i = 0 ;i<count;i++){
    r = max(r, dp[i]);
    cout<<dp[i]<<" ";
  }
  cout<<r;
  return 0;
}
