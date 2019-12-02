#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
  int n, k, c[101], dp[10001] = {0, };
  cin>>n>>k;
  for(int i = 0 ;i<n;i++){
    cin>>c[i];
  }
  sort(c,c+n);
  for(int i = 1 ;i<=k;i++){
    if(i%c[0] == 0) dp[i] = 1;
  }
  for(int i = 1;i<n;i++){
    for(int j = 1;j<=k;j++){
      if(j==c[i]) dp[j]++;
      else if(j>c[i]) dp[j] = dp[j] + (dp[j-c[i]]);
    }
  }
  cout<<dp[k];
  return 0;
}
