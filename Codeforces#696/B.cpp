#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

// y가 x로 나눠지면 x는 y의 divisor이다.
// integer d가 주어지고 가장 작은 a를 찾아야 한다.
// a는 최소 4개의 divisor를 가진다.
// a의 divisor들의 차는 최소 d이다.
int main(void){
  int size = 1010101;
  int t;
  vector<int> arr(size, 0);
  //0이면 소수, 1이면 소수 아님
  cin>>t;
  for(int i = 2 ; i<=sqrt(size) ; i++){
    for(int j = i+i ; j<=size ; j += i){
      arr[j] = 1;
    }
  }
  while(t--){
    long long d, a, b;
    cin>>d;
    for(int i = 1 + d ; i<=size ; i++){
      if(!arr[i]) {
        a = i;
        break;
      }
    }
    for(int i = a + d ; i<=size ; i++){
      if(!arr[i]) {
        b = i;
        break;
      }
    }
    cout<<a*b<<'\n';
  }
  return 0;
}
