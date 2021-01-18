#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define MAX 2000000001

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

int parents[1001] = {0, };
stack<int> s;

int find(int u){
  if(parents[u] == u) return u;
  s.push(parents[u]);
  return find(parents[u]);
}

void merge(int u, int v){
  if(u == v) return;
  parents[v] = u;
}

int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, start, end, time=MAX;
  cin>>N>>M;
  vector<vector<int>> v(N+1, vector<int>(N+1, MAX));
  vector<int> dist(N+1, MAX);
  priority_queue<struct info, vector<struct info>, cmp> pq;

  for(int i = 1 ; i<=N ; i++) parents[i] = i;

  for(int i = 0 ; i<M ; i++){
    int from, to, value;
    cin>>from>>to>>value;
    v[from][to] = min(v[from][to], value);
  }

  cin>>start>>end;

  pq.push({start, 0, 1});
  dist[start] = 0;
  while(!pq.empty()){
    struct info now = pq.top();
    pq.pop();

    for(int i = 1 ; i<=N ; i++){
      int next = v[now.idx][i];
      if(next == MAX) continue;
      if(dist[i] > dist[now.idx] + next){
        dist[i] = dist[now.idx] + next;
        pq.push({i, dist[i], now.prev + 1});
        merge(now.idx, i);
        if(i == end) time = now.prev + 1;
      }
    }
  }
  cout<<dist[end]<<'\n';
  cout<<time<<'\n';
  find(end);
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<end;
  return 0;
}
