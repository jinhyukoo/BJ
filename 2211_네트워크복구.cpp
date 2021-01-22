#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<set>
using namespace std;

#define MAX 1000000000
typedef pair<int, int> pii;
vector<int> dist(1001, MAX), parents(1001);
vector<vector<int>> inputs(1001, vector<int>(1001));
set<pii> s;

int find(int u){
  if(parents[u] == u) return u;
  s.insert({parents[u], u});
  return find(parents[u]);
}

void merge(int u, int v){
  parents[v] = u;
}

int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int N,M;
  cin>>N>>M;
  for(int i = 0 ; i<M ; i++){
    int A,B,C;
    cin>>A>>B>>C;
    inputs[A][B] = C;
    inputs[B][A] = C;
  }
  priority_queue<pii, vector<pii>, greater<>> pq;
  for(int i = 1 ; i<=N ; i++) parents[i] = i;
  dist[1] = 0;
  pq.push({0, 1});
  while(!pq.empty()){
    pii now = pq.top();
    int nowIdx = now.second, nowValue = now.first;
    pq.pop();
    for(int i = 1 ; i<=inputs[nowIdx].size() ; i++){
      int nextValue = inputs[nowIdx][i];
      if(!nextValue) continue;
      if(dist[i] > dist[nowIdx] + nextValue){
        dist[i] = dist[nowIdx] + nextValue;
        pq.push({dist[i], i});
        merge(nowIdx, i);
      }
    }
  }
  for(int i = 2 ; i<=N ; i++){
    find(i);
  }
  cout<<s.size()<<'\n';
  for(auto i : s){
    cout<<i.first<<" "<<i.second<<'\n';
  }
  return 0;
}
