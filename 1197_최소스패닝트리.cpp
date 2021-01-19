#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

struct info{
  int a;
  int b;
  int v;
};

struct cmp{
  bool operator()(info t, info u){
    return t.v > u.v;
  }
};

int parents[10001] = {0, };

int find(int u){
  if(parents[u] == u) return u;
  return parents[u] = find(parents[u]);
}

void merge(int u, int v){
  u = find(u); v = find(v);
  if(u == v) return;
  parents[v] = u;
}

int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int V, E, count = 1, result = 0;
  cin>>V>>E;
  priority_queue<struct info, vector<struct info>, cmp> pq;

  for(int i = 1 ; i<=V ; i++) parents[i] = i;
  for(int i = 0 ; i<E ; i++){
    int A, B, C;
    cin>>A>>B>>C;
    pq.push({A,B,C});
  }
  while(!pq.empty()){
    if(count == V) break;
    struct info now = pq.top();
    pq.pop();
    if(find(now.a) == find(now.b)) continue;
    merge(now.a, now.b);
    result += now.v;
    count++;
  }
  cout<<result;
  return 0;
}
