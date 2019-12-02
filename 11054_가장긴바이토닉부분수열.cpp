#include<iostream>
using namespace std;
int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N, arr[1001], dp[1001] = {1, }, dp2[1001] = {1, }, r = 0;
  cin>>N;
  for(int i = 0 ;i<N;i++) cin>>arr[i];
  for(int i = 1 ;i<N;i++){
    int mindp = 0, maxdp = 0;
    for(int j = 0;j<i;j++){
      if(dp[j] > maxdp && arr[i] > arr[j]) maxdp = dp[j];
    }
    dp[i] = maxdp + 1;
    dp2[i] = maxdp + 1;
  }
  for(int i = 1; i<N;i++){
    int mindp = 0;
    for(int j = 0 ;j<i;j++){
      if(dp2[j]>mindp && arr[i]<arr[j]) mindp = dp2[j];
    }
    if(mindp != 0) dp2[i] = max(mindp + 1,dp2[i]);
  }
  for(int i = 0 ;i<N;i++){
    if(dp2[i] > r) r = dp2[i];
  }
  cout<<r;
  return 0;
}
