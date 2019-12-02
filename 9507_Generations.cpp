#include<iostream>
using namespace std;
int main(void){
  long long t, dp[68];
  dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
  for(int i = 4;i<=67;i++){
    dp[i] = dp[i-4] + dp[i-3] + dp[i-2] + dp[i-1];
  }
  cin>>t;
  for(int i = 0 ;i<t;i++){
    int n;
    cin>>n;
    cout<<dp[n]<<'\n';
  }
  return 0;
}
