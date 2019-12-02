#include<iostream>
using namespace std;
int main(void){
  int n;
  long long dp[101][10], r[101];
  cin>>n;
  for(int i = 1 ;i<=9;i++){
    dp[1][i] = 1;
    dp[2][i] = 2;
  }
  dp[2][9] = 1;
  r[1] = 9; r[2] = 17;
  for(int i = 3;i<=n;i++){
    int sum = 0;
    for(int j = 1;j<=9;j++){
      if(j == 1){
        dp[i][j] = (dp[i-2][j] + dp[i-1][j+1])%1000000000;
        sum = (sum+dp[i][j])%1000000000;
      }
      else if(j==9){
        dp[i][j] = dp[i-1][j-1]%1000000000;
        sum = (sum+dp[i][j])%1000000000;
      }
      else{
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        sum = (sum + dp[i][j])%1000000000;
      }
    }
    r[i] = sum%1000000000;
  }
  cout<<r[n];
  return 0;
}
#include<iostream>
using namespace std;
int main(void){
  int n, sum = 0;
  long long dp[101][10], r[101];
  cin>>n;
  for(int i = 1 ;i<=9;i++){
    dp[1][i] = 1;
    dp[2][i] = 2;
  }
  dp[2][9] = 1;
  r[1] = 9; r[2] = 17;
  for(int i = 3;i<=n;i++){
    for(int j = 1;j<=9;j++){
      if(j == 1){
        dp[i][j] = (dp[i-2][j] + dp[i-1][j+1])%1000000000;
      }
      else if(j==9){
        dp[i][j] = dp[i-1][j-1]%1000000000;
      }
      else{
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
      }
    }
  }
  for(int i = 1 ;i<=9;i++)
    sum = (sum+dp[n][i])%1000000000;
  cout<<sum;
  return 0;
}
