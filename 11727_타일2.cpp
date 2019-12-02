/*
잘 보면 금방 규칙이 보이는 문제
맨 마지막에 들어올 타일만을 생각해보면 2x1, 1x2, 2x2가 있다
이 부분을 잘 생각해보면 3가지 경우의 수를 따져주면 된다는 결론이 나온다.
2x2와 2x1은 끝이 2개 비어있는 경우이므로 i-2번째 dp를 더해주고 1x2에 대한 연산은 i-1번째 dp로 진행한다.
*/
#include<iostream>
using namespace std;
int main(void){
  int c, d[1002];
  cin>>c;
  d[1] = 1; d[2] = 3;
  for(int i = 3 ;i<=c;i++){
    d[i] = (d[i-1] + d[i-2]*2)%10007;
  }
  cout<<d[c];
  return 0;
}
