#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 1000000000

struct info{
  int idx;
  int d;
  int prev;
};

struct cmp{
  bool operator()(info t, info u){
    return t.d > u.d;
  }
};

int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int N,M,X,result = 0;
  cin>>N>>M>>X;
  vector<vector<int>> v(N+1, vector<int>(N+1)), rv(N+1, vector<int>(N+1));
  vector<int> go(N+1, MAX), back(N+1, MAX);
  while(M){
    M--;
    int from, to, value;
    cin>>from>>to>>value;
    v[from][to] = value;
    rv[to][from] = value;
  }
  // 간선 방향을 뒤집어서 갈 때 걸리는 최소 비용 구하기
  priority_queue<struct info, vector<struct info>, cmp> pq;
  go[X] = 0;
  for(int i = 1 ; i<=N ; i++){
    pq.push({i, go[i], 0});
  }
  while(!pq.empty()){
    struct info now = pq.top();
    pq.pop();
    for(int i = 1 ; i<=N ; i++){
      if(!rv[now.idx][i]) continue;
      int adj = rv[now.idx][i];
      if(go[i] >= now.d + adj){
        go[i] = now.d + adj;
        pq.push({i, go[i], now.idx});
      }
    }
  }
  // 오는데 걸리는 비용 다익스트라로 탐색
  back[X] = 0;
  for(int i = 1 ; i<=N ; i++){
    pq.push({i, back[i], 0});
  }
  while(!pq.empty()){
    struct info now = pq.top();
    pq.pop();
    for(int i = 1 ; i<=N ; i++){
      if(!v[now.idx][i]) continue;
      int adj = v[now.idx][i];
      if(back[i] >= now.d + adj){
        back[i] = now.d + adj;
        pq.push({i, back[i], now.idx});
      }
    }
  }
  for(int i = 1 ; i<=N ; i++) result = max(result, go[i] + back[i]);
  cout<<result;
  return 0;
}
