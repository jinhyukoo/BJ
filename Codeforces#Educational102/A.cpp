// 모두 양수
// 첫번째로 3개의 구분된 index 선택 가능
// ai를 aj + ak로 바꿀 수 있다.

// 첫번째 줄 t (테스트 케이스)
// n, d => n은 어레이 길이
// 모든 요소를 d보다 작거나 같게 만들 수 있다면 YES 아니ㅏ면 No
// 안 바꿔도 됨.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
  int t;
  cin>>t;
  for(int i = 0 ; i<t ; i++){
    int n, d, flag = 0;
    cin>>n>>d;
    vector<int> arr(n);
    for(int i = 0 ; i<n ; i++){
      cin>>arr[i];
      if(arr[i] > d) flag = 1;
    }
    if(!flag){
      cout<<"YES\n";
      continue;
    }
    sort(arr.begin(), arr.end());
    if(arr[0] + arr[1] <= d) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
