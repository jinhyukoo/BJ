#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
vector<int> inputs, L, P;
stack<int> S;

void printResult(int num, int idx){
  int tempIdx = 0;
  if(num == 0){
    while(!S.empty()){
      cout<<S.top()<<" ";
      S.pop();
    }
    return;
  }
  for(int i = idx-1 ; i>=0 ; i--){
    if(P[i] == num){
      S.push(inputs[i]);
      tempIdx = i;
      break;
    }
  }
  printResult(num-1, tempIdx);
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N;
  cin>>N;
  for(int i = 0 ; i<N ; i++){
    int input;
    cin>>input;
    inputs.push_back(input);
    if(L.empty()){
      L.push_back(input);
      P.push_back(1);
      continue;
    }
    auto lbound = lower_bound(L.begin(), L.end(), input);
    if(lbound == L.begin() + L.size()){
      L.push_back(input);
      P.push_back(L.size());
    }
    else{
      *lbound = input;
      P.push_back(lbound - L.begin() + 1);
    }
  }
  cout<<L.size()<<'\n';
  printResult(L.size(), P.size());
  return 0;
}
