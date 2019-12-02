//그 전까지의 합이 음수가 될 경우 그 다음 값을 더하더라도 절대 최대값이 될 수 없다는 생각을 했다.
//따라서 그 전까지의 합이 양수라면 계속해서 더해주고 그렇지 않다면 해당 index의 배열 값으로 초기화 시켜준다.
#include<iostream>
using namespace std;

int main(void){
  int c, r, n[10002], dp[10002];
  cin>>c;
  for(int i = 1 ;i<=c;i++)
    cin>>n[i];
  dp[1] = n[1];
  if(c == 1){cout<<n[1]; return 0;} //1과 2일때는 어짜피 경우의 수가 저것 밖에 없음.
  if(c == 2){cout<<max(max(n[1]+n[2],n[2]),n[1]); return 0;}
  r = dp[1];
  for(int i = 2 ;i<=c;i++){
    if(dp[i-1]>0) dp[i] = dp[i-1] + n[i]; //그 전까지의 합이 양수이면 더하기 연산
    else dp[i] = n[i]; // 만약 그 전의 값이 음수라면 배열의 값으로 초기화 시켜줌.
    if(dp[i]>r) r = dp[i]; //최대값 비교
  }
  for(int i = 1 ;i<=c ;i++)
    cout<<dp[i]<<" ";
  cout<<r;
  return 0;
}
