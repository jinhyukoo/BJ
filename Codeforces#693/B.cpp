// 사탕의 무게는 1그램 또는 2그램
// 사탕의 무게가 같아지게 나누기를 원한다.
// 그렇게 할 수 있는지 체크해라
// 사탕을 쪼개는건 불가능

#include<iostream>
using namespace std;
int main(void){
  int T;
  cin>>T;
  for(int i = 0 ; i<T ; i++){
    int N, alice = 0, bob = 0;
    int candies[2] = {0, };
    cin>>N;
    for(int j = 0 ; j<N ; j++){
      int input;
      cin>>input;
      candies[input-1]++;
    }
    if(candies[1] % 2 == 1){
      alice += 2;
    }
    if(alice > bob){
      candies[0] -= 2;
    }
    if(candies[0] >= 0 && candies[0] % 2 == 0) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
