#include<iostream>
#include<queue>
#include<functional>
using namespace std;

typedef pair<int, int> pii;
const int INF = 2000000001;

vector<pii> v[1010];
priority_queue<int> dist[1010];

int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int N,M,K;
  priority_queue<pii, vector<pii>, greater<> > pq;
  cin>>N>>M>>K;
  for(int i = 0 ; i<M ; i++){
    int from, to, value;
    cin>>from>>to>>value;
    v[from].push_back({value, to});
  }
  pq.push({0, 1});
  dist[1].push(0);

  while(!pq.empty()){
    int nowIdx = pq.top().second, nowValue = pq.top().first;
    pq.pop();
    for(auto i : v[nowIdx]){
      int nextIdx = i.second, nextValue = i.first;
      if(dist[nextIdx].size() < K){
        dist[nextIdx].push(nextValue + nowValue);
        pq.push({nextValue + nowValue, nextIdx});
      }
      else if(dist[nextIdx].top() > nextValue + nowValue){
        dist[nextIdx].pop();
        dist[nextIdx].push(nextValue + nowValue);
        pq.push({nextValue + nowValue, nextIdx});
      }
    }
  }
  for(int i = 1 ; i<=N ; i++){
    dist[i].size() != K ? cout<<"-1\n" : cout<<dist[i].top()<<'\n';
  }
  return 0;
}
