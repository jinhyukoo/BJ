#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define MAX 800001

int N, E, v1, v2;
vector<vector<int>> v(801, vector<int>(801));

struct info{
  int idx;
  int d;
};

struct cmp{
  bool operator()(info t, info u){
    return t.d > u.d;
  }
};

vector<int> Dijkstra(int n, int start){
  vector<int> dist(n+1, MAX);
  dist[start] = 0;
  priority_queue<struct info, vector<struct info>, cmp> pq;
  pq.push({start, 0});
  while(!pq.empty()){
    struct info now = pq.top();
    pq.pop();
    for(int i = 1 ; i<=N ; i++){
      if(!v[now.idx][i]) continue;
      if(dist[i] >= now.d + v[now.idx][i]){
        dist[i] = now.d + v[now.idx][i];
        pq.push({i, dist[i]});
      }
    }
  }
  return dist;
}

int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N>>E;

  for(int i = 1  ; i<=E ; i++){
    int from, to, value;
    cin>>from>>to>>value;
    v[from][to] = value;
    v[to][from] = value;
  }
  cin>>v1>>v2;
  vector<int> startToAB = Dijkstra(N, 1);
  vector<int> AToN = Dijkstra(N, v1);
  vector<int> BToN = Dijkstra(N, v2);
  int startABN = startToAB[v1] + AToN[v2] + BToN[N];
  int startBAN = startToAB[v2] + AToN[v2] + AToN[N];
  int result = min(startABN, startBAN);
  if(result >= MAX) cout<<-1;
  else cout<<result;

  return 0;
}
