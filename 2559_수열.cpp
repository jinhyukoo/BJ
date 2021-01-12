#include<iostream>
#include<vector>
using namespace std;
int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int N, K, max = -1000000000;
  cin>>N>>K;
  vector<int> arr(N+1, 0);
  for(int i = 1 ; i<=N ; i++){
    cin>>arr[i];
    arr[i] = arr[i] + arr[i-1];
  }
  for(int i = K ; i<=N ; i++){
    int now = arr[i] - arr[i-K];
    if(max < now) max = now;
  }
  cout<<max;
  return 0;
}
