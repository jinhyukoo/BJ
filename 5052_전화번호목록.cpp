#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<string> arr(n);
    for(int i = 0 ; i<n ; i++){
      cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 1 ; i<n ; i++){
      if(arr[i].find(arr[i-1]) == 0){
        cout<<"NO\n";
        goto next;
      }
    }
    cout<<"YES\n";
    next:
      continue;

  }
  return 0;
}
