#include<iostream>
using namespace std;
int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int h, m[501][501], dp[501][501] = {0, };
  cin>>h;
  for(int i = 1 ;i<=h;i++){
    for(int j = 1 ; j<=i;j++){
      cin>>m[i][j];
    }
  }
  dp[1][1] = m[1][1];
  for(int i = 2 ;i<=h;i++){
    for(int j = 1 ;j<=i;j++){
      dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + m[i][j];
    }
  }
  int r = 0;
  for(int i = 1 ; i<=h ; i++){
    r = max(r,dp[h][i]);
  }
  cout<<r;
  return 0;
}
