#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
  int t; cin>>t;
  while(t--){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n, result = -1000000000;
    cin>>n;
    vector<int> arr(n+1);
    vector<int> sum;
    for(int i = 1 ; i<=n ; i++){
      cin>>arr[i];
    }
    for(int i = 1 ; i<=n ; i++){
      int tmp = arr[i];
      sum.push_back(tmp);
      for(int j = i+1; j<=n ; j++){
        tmp += arr[j];
        sum.push_back(tmp);
      }
    }
    for(int i = 0 ; i<sum.size() ; i++){
      result = max(result, sum[i]);
    }
    cout<<result<<'\n';
  }
  return 0;
}
