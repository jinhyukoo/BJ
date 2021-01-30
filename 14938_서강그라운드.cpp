#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

#define MAX 1000000000

typedef pair<int, int> pii;

int main(void){
  int n, m, r, result = 0;
  vector<int> value(101);
  vector<vector<int>> inputs(101, vector<int>(101)), dist(101, vector<int>(101, MAX));
  cin>>n>>m>>r;
  for(int i = 1 ; i<=n ; i++){
    cin>>value[i];
  }
  for(int i = 0 ; i<r ; i++){
    int a, b, l;
    cin>>a>>b>>l;
    inputs[a][b] = l;
    inputs[b][a] = l;
  }
  for(int i = 1 ; i<=n ; i++){
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, i});
    dist[i][i] = 0;
    while(!pq.empty()){
      pii now = pq.top();
      int nowValue = now.first, nowIdx = now.second;
      pq.pop();
      for(int j = 1 ; j<=n ; j++){
        if(!inputs[nowIdx][j]) continue;
        int nextValue = nowValue + inputs[nowIdx][j];
        if(dist[i][j] > nextValue){
          dist[i][j] = nextValue;
          pq.push({nextValue, j});
        }
      }
    }
  }
  for(int i = 1 ; i<=n ; i++){
    int sum = 0;
    for(int j = 1 ; j<=n ; j++){
      if(dist[i][j] <= m) sum += value[j];
    }
    result = max(result, sum);
  }
  cout<<result;
  return 0;
}
