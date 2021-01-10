#include<iostream>
#include<vector>
using namespace std;
int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin>>N>>M;
  vector<int> arr(N), dp(N);
  for(int i = 0 ; i<N ; i++){
    cin>>arr[i];
    if(i == 0) dp[i] = arr[i];
    else dp[i] = dp[i-1] + arr[i];
  }
  for(int i = 0 ; i<M ; i++){
    int from, to;
    cin>>from>>to;
    if(from == 1) cout<<dp[to-1]<<'\n';
    else cout<<dp[to-1] - dp[from-2]<<'\n';
  }
  return 0;
}
