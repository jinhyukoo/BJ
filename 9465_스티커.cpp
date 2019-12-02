/*
그 전에 참고할 수 있는 최대값을 가진 스티커는 대각선 아래, 그리고 두칸 뒤의 스티커 두장이다. 따라서 그 3개의 경우의 수를 따져준다.
*/
#include<iostream>
using namespace std;
int main(void){
  int iter;
  cin>>iter;
  for(int i = 0 ;i<iter;i++){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int c, m = -1, n[100002][2], dp[100002][2] ={0, };
    cin>>c;
    for(int j = 1 ;j<=c;j++){
      cin>>n[j][0];
    }
    for(int j = 1 ;j<=c;j++){
      cin>>n[j][1];
    }
    dp[1][0] = n[1][0]; dp[1][1] = n[1][1];
    for(int j = 2 ;j<=c;j++){
      dp[j][0] = max(dp[j-1][1],max(dp[j-2][0],dp[j-2][1]))+n[j][0];
      dp[j][1] = max(dp[j-1][0],max(dp[j-2][0],dp[j-2][1]))+n[j][1];
    }
    cout<<max(dp[c][0],dp[c][1])<<endl;
  }
  return 0;
}
