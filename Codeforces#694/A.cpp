// 길이가 n인 array a, 그리고 정수 x를 입력으로 받음.
// 최대한 많이 동작시켜야 함. (0번도 가능)
// 2개의 인접한 요소를 그들의 sum으로 바꾼다.
// [3,6,9] => [3,15]
// 원래 어레이에서 동작을 수행해서 얻을 수 있는 최대, 최소 값을 구해라.
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(void){
  int t;
  cin>>t;
  while(t){
    t--;
    int n, x, arr[101010] = {0, };
    long long result = 0, remainder = 0, recount = 0;
    cin>>n>>x;
    for(int i = 0 ; i<n ; i++){
      cin>>arr[i];
      if(arr[i] % x != 0){
        result += arr[i] / x + 1;
        recount++;
      }
      else result += arr[i] / x;
      remainder += arr[i] % x;
    }
    if(remainder % x == 0) cout<<result - recount + remainder/x<<" "<<result<<'\n';
    else cout<<result - recount + remainder/x + 1<<" "<<result<<'\n';
  }
  return 0;
}
