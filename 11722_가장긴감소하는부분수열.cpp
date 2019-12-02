#include<iostream>
using namespace std;
int main(void){
  int n, arr[1001], dp[1001] = {0, }, r = 0;
  cin>>n;
  for(int i = 0 ;i<n;i++) cin>>arr[i];
  for(int i = 0 ;i<n;i++){
    int idx = -1;
    for(int j = 0 ;j<i;j++){
      if(arr[j]>arr[i]){
        if(dp[j]>=dp[idx]) idx = j;
      }
    }
    if(idx != -1) dp[i] = dp[idx] + 1;
  }
  for(int i = 0 ;i<n;i++){
    if(dp[i]>r) r=dp[i];
  }
  cout<<r+1;
  return 0;
}
