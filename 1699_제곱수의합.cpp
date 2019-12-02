#include<iostream>
#include<cmath>
using namespace std;
int main(void){
  int num, dp[100001];
  for(int i = 0 ;i<100001;i++) dp[i] = 100000;
  cin>>num;
  for(int i = 1; i<=sqrt(100000);i++){
    dp[i*i] = 1;
    dp[i*i+1] = 2;
    // dp[i*i*2] = 2;
  }
  for(int i = 2;i<=num;i++){
    int temp = 100000;
    if(dp[i]<=2) continue;
    for(int j = i-1;j>=i/2;j--){
        temp = dp[j] + dp[i-j];
        if(dp[i]>temp) dp[i] = temp;
    }
    // dp[i] = temp;
  }
  cout<<dp[num];
  return 0;
}
