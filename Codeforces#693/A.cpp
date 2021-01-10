// w x h 의 종이
// 2가지 경우로 자를 수 있다.
// w가 짝수면 반으로 자르고 w2 x h를 얻음
// h가 짝수면 반으로 자르고 w x h2를 얻음
// 둘 다 짝수면 두 가지 경우 중 하나로 가능
// 종이를 자르고 나면 총 종이의 수는 1 증가한다.
// 위의 규칙대로 종이를 자를 수 있는지 체크해라. 적어도 n개의 종이를 얻을 수 있는지 체크
#include<iostream>
#include<cmath>

using namespace std;
int main(void){
  int T;
  cin>>T;
  for(int i = 0 ; i<T ; i++){
    int w, h, n, count = 0;
    cin>>w>>h>>n;
    while(w%2 == 0){
      count++;
      w = w/2;
    }
    while(h%2 == 0){
      count++;
      h = h/2;
    }
    if(n<=pow(2, count)) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
