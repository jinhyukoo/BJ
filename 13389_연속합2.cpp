#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin>>N;
  vector<int> inputs(N+1);
  vector<vector<int>> sum(N+1, vector<int>(2));
  for(int i = 1 ; i<=N ; i++){
    cin>>inputs[i];
  }

  int answer = inputs[1];
  sum[1][0] = sum[1][1] = inputs[1];
  for(int i = 2 ; i<=N ; i++){
    sum[i][0] = max(sum[i-1][0] + inputs[i], inputs[i]);
    sum[i][1] = max(sum[i-1][0], sum[i-1][1] + inputs[i]);
    answer = max(answer, max(sum[i][0], sum[i][1]));
  }
  cout<<answer;
  return 0;
}
