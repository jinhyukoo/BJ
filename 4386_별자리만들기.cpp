#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int parents[10001] = {0, };
struct info{
  int from;
  int to;
  double d;
};

struct cmp{
  bool operator()(info t, info u){
    return t.d > u.d;
  }
};
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
  int N, count = 0; cin>>N;
  double result = 0;
  for(int i = 0 ; i<N ; i++) parents[i] = i;
  vector<pair<double, double>> inputs;
  vector<vector<double>> dist(N, vector<double>(N));
  priority_queue<struct info, vector<struct info>, cmp> pq;
  for(int i = 0 ; i<N ; i++){
    double x, y; cin>>x>>y;
    inputs.push_back({x, y});
  }
  for(int i = 0 ; i<N ; i++){
    pair<double, double> now = inputs[i];
    for(int j = 0 ; j<N ; j++){
      pair<double, double> next = inputs[j];
      if(i == j){
        dist[i][j] = 1000000000;
        continue;
      }
      double x = next.first - now.first, y = next.second - now.second;
      dist[i][j] = sqrt(x*x + y*y);
      pq.push({i,j,dist[i][j]});
    }
  }
  while(!pq.empty()){
    if(count == N) break;
    struct info now = pq.top();
    pq.pop();
    if(find(now.from) == find(now.to)) continue;
    merge(now.from, now.to);
    result += now.d;
    count++;
  }
  cout<<fixed;
  cout.precision(2);
  cout<<result;
  return 0;
}
