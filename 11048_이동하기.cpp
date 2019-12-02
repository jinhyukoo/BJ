#include<iostream>
using namespace std;
int main(void){
  int map[101][101] = {0, }, dp[101][101] = {0, }, n, m;
  cin>>n>>m;
  for(int i = 0 ;i<n;i++){
    for(int j = 0;j<m;j++){
      cin>>map[i][j];
    }
  }
  dp[0][0] = map[0][0];
  for(int i = 1 ;i<n;i++){
    dp[i][0] = dp[i-1][0] + map[i][0];
  }
  for(int i = 1 ;i<m;i++){
    dp[0][i] = dp[0][i-1] + map[0][i];
  }
  for(int i = 1;i<n;i++){
    for(int j = 1;j<m;j++){
      if(i==0){
        dp[i][j] = dp[i][j-1] + map[i][j];
      }
      else if(j==0){
        dp[i][j] = dp[i-1][j] + map[i][j];
      }
      else dp[i][j] = max(dp[i-1][j],max(dp[i-1][j-1], dp[i][j-1])) + map[i][j];
    }
  }
  cout<<dp[n-1][m-1];
  return 0;
}
