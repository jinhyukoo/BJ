#include<iostream>
#include<vector>
using namespace std;
int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin>>N>>M;
  vector<vector<int>> arr(N+1, vector<int>(N+1, 0)), dp(N+1, vector<int>(N+1, 0));
  for(int i = 1 ; i<=N ; i++){
    for(int j = 1 ; j<=N ; j++){
      cin>>arr[i][j];
    }
  }
  for(int i = 1 ; i<=N ; i++){
    for(int j = 1 ; j<=N ; j++){
      dp[j][i] = dp[j-1][i] + arr[j][i];
    }
  }
  for(int i = 1 ; i<=N ; i++){
    for(int j = 1 ; j<=N ; j++){
      dp[i][j] = dp[i][j] + dp[i][j-1];
    }
  }
  for(int i = 0 ; i<M ; i++){
    int x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<dp[x2][y2]+dp[x1-1][y1-1]-dp[x1-1][y2]-dp[x2][y1-1]<<'\n';
  }
  return 0;
}
