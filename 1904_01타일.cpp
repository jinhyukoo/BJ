/*
간단하게 규칙을 찾을 수도 있고 문제의 정의에 따라 접근해보면
뒤에 올 수 있는 숫자 종류로는 00과 1이 있기 때문에
i번째의 경우 i-2번째의 수들에 00을 붙인 경우와 i-1번째 수에 1을 붙인 수들의 합이 i번째에 만들 수 있는 경우의 수가 된다는 점을 활용한다.
규칙을 찾아보면 피보나치와 동일하다.
*/
#include<cstdio>
using namespace std;
int main(void){
  int n, a, b;
  a = 1; b = 1;
  scanf("%d",&n);
  for(int i = 2 ;i<=n;i++){
    int temp = (a + b)%15746;
    if(i%2 == 0) a = temp;
    else b = temp;
  }
  if(n%2 == 0) printf("%d",a);
  else printf("%d",b);
  return 0;
}
