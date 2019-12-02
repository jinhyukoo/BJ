#include<iostream>
using namespace std;
int main(void){
  int T;
  cin>>T;
  for(int i = 0 ;i<T;i++){
    int n, dp[101] = {0, },r=0;
    cin>>n;
    for(int j = 2;j<=n/2;j++){
      for(int k = j; k<=n; k+=j){
        dp[k] = (dp[k]+1)%2;
      }
    }
    for(int j = n/2 + 1;j<=n;j++){
      dp[j] = (dp[j]+1)%2;
    }
    for(int j = 1;j<=n;j++){
      if(dp[j] == 0) r++;
    }
    cout<<r<<'\n';
  }
  return 0;
}
