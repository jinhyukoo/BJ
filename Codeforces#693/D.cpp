// Alice가 먼저 움직인다.
// 각 턴에 array에서 element를 선택하고 제거한다.
// 만약 alice가 짝수를 선택하면 자신의 스코어에 그 숫자를 더한다. 홀수는 변화없음
// Bob이 홀수를 선택하면 스코어가 추가되고 짝수 선택하면 변화없다.
// 남은 숫자가 없으면 게임이 종료된다.
// 스코어가 높은 사람이 승리 비길 수도 있음



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
  int T;
  cin>>T;
  for(int i = 0 ; i<T ; i++){
    int N;
    long long alice = 0, bob = 0;
    cin>>N;
    vector<int> inputs(N);
    for(int j = 0 ; j<N ; j++){
      cin>>inputs[j];
    }
    sort(inputs.begin(), inputs.end(), greater<int>());
    for(int j = 0 ; j<N; j++){
      if(j % 2 == 0){
        if(inputs[j] % 2 == 0) alice += inputs[j];
      }
      else{
        if(inputs[j] % 2 == 1) bob += inputs[j];
      }
    }
    if(alice == bob) cout<<"Tie\n";
    else if(alice > bob) cout<<"Alice\n";
    else cout<<"Bob\n";
  }
  return 0;
}
