#include<iostream>
#include<vector>
using namespace std;
int main(void){
  int N, M;
  cin>>N;
  vector<int> inputs(N+1);
  for(int i = 1 ; i<=N ; i++){
    cin>>inputs[i];
    inputs[i] += inputs[i-1];
  }
  cin>>M;
  while(M--){
    int a, b;
    cin>>a>>b;
    cout<<inputs[b] - inputs[a-1]<<'\n';
  }
  return 0;
}
