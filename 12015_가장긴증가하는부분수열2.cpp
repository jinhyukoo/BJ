#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N;
  vector<int> L;
  cin>>N;
  for(int i = 0 ; i<N ; i++){
    int input;
    cin>>input;
    if(L.empty()){
      L.push_back(input);
      continue;
    }
    auto lbound = lower_bound(L.begin(), L.end(), input);
    if(lbound == L.begin() + L.size()) L.push_back(input);
    else *lbound = input;
  }
  cout<<L.size();
  return 0;
}
