#include<iostream>
using namespace std;
int main(void){
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N, arr[4002], A, dp[4002];
  cin>>N;

  //숫자 받아서 배열에 저장 이 때 -1을 저장해줌으로써 짝수개 팰린드롬에 대비한다.
  for(int i = 1 ;i<=2*N;i+=2){
    cin>>arr[i+1];
    arr[i] = -1;
  }


  int r = 0, p = 0; //r은 dp[p] + p, p는 최대 값을 가진 곳의 index


  for(int i = 1 ;i<=2*N;i++){
    if(i<=r) dp[i] = min(dp[2*p - i], r - i); //특정 index에 도달했을 때 r보다 작다는 것은 특정 팰린드롬에 속해있다는 의미 따라서 그 곳의 dp값은 기존 값을 참고하여 초기화
    else dp[i] = 0; //r보다 i가 크다는 것은 특정 팰린드롬에 속해있지 않다는 의미임. 따라서 0으로 초기화
    while(i - dp[i] - 1>0 && i + dp[i] + 1 <=2*N && arr[i - dp[i] - 1] == arr[i + dp[i] + 1]) dp[i]++; //양쪽의 수가 같은 만큼 dp값을 증가시켜줌.
    if(r < i + dp[i]){ //r과 p를 갱신해주는 부분, 새롭게 구한 값이 기존의 r보다 클 경우 갱신
      r = i + dp[i];
      p = i;
    }
  }


  cin>>A;
  for(int i = 0 ;i<A;i++){
    int t1, t2;
    cin>>t1>>t2;
    if(t1==t2) cout<<1<<'\n'; //하나의 수는 무조건 팰린드롬이므로 1출력
    else{
      if(dp[t1+t2] != 0){ //dp의 값이 0이라는 것은 팰린드롬이 존재하지 않는 다는 의미이므로 패스하고 그렇지 않을 경우 팰린드롬인지 판별하는 식으로 들어감.
        if((t1+t2) - dp[t1+t2] <= t1*2 && dp[t1+t2] + (t1+t2) >= t2*2) cout<<1<<'\n'; //t1과 t2가 있을 때 특정 부분에서 팰린드롬 범위에 t1과 t2가 들어있는지 판별. 범위 안에 있으면 1 범위를 넘어가면 0 출력
        else cout<<0<<'\n';
      }
      else cout<<0<<'\n';
    }
  }


  return 0;
}
