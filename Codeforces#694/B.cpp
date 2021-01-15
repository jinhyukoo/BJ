// 길이 n의 array a와 정수 x
// 현재 요소가 q라고 하자.
// 만약 q가 x로 나눠지면 어레이 끝에 q/x를 x번 추가하고 다음 순서로 이동한다.
// 새롭게 추가된 것 역시 robot이 수행한다.
// q가 x로 나눠지지 않으면 동작을 중지한다.
// 프로세스가 끝났을 때의 array의 sum을 구해라.

#include<iostream>
using namespace std;
int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t){
    t--;
    long long n, x, input[101010] = {0, }, arr[101010] = {0, }, flag = 1, count = 1, idx = -1;
    long long result = 0;
    cin>>n>>x;
    for(int i = 0 ; i<n ; i++){
      cin>>arr[i];
      input[i] = arr[i];
    }
    while(flag){
      for(int i = 0 ; i<n ; i++){
        if(arr[i] % x != 0){
          flag = 0;
          idx = i;
          break;
        }
        arr[i] /= x;
      }
      count++;
    }
    if(idx == -1){
      for(int i = 0 ; i<n ; i++) result += input[i] * count;
    }
    else {
      for(int i = 0 ; i<idx ; i++) result += input[i] * count;
      for(int i = idx ; i<n ; i++) result += input[i] * (count - 1);
    }
    cout<<result<<'\n';
  }
  return 0;
}
