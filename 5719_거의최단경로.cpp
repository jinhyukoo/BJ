#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<cstring>
using namespace std;

int N,M,S,D;
vector<int> trace[501];
vector<vector<int>> inputs(501, vector<int>(501));
typedef pair<int, int> pii;

#define MAX 1000000000

struct info{
  int idx;
  int d;
};

struct cmp{
  bool operator()(info t, info u){
    return t.d > u.d;
  }
};

vector<int> dijkstra(){

  vector<int> dist(N, MAX);
  priority_queue<struct info, vector<struct info>, cmp> pq;
  dist[S] = 0;
  pq.push({S, 0});
  while(!pq.empty()){
    struct info now = pq.top();
    int nowIdx = now.idx, nowValue = now.d;
    pq.pop();
    for(int i = 0 ; i<N ; i++){
      int nextValue = inputs[nowIdx][i] + nowValue;
      if(!inputs[nowIdx][i]) continue;
      if(dist[i] < nextValue) continue;
      // 클 때만 pq에 넣는다.
      if(dist[i] > nextValue){
        pq.push({i, nextValue});
      }
      // 같을 때도 체크는 해야 하기 때문에 다음과 같이
      dist[i] = nextValue;
      trace[i].push_back(nowIdx);
    }
  }
  return dist;
}

int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  while(1){
    cin>>N>>M;
    if(N == 0 && M == 0) break;
    cin>>S>>D;

    // 사용하는 배열들 초기화
    for(int i = 0 ; i<N ; i++){
      trace[i].clear();
      for(int j = 0 ; j<N ; j++){
        inputs[i][j] = 0;
      }
    }

    for(int i = 0 ; i<M ; i++){
      int U,V,P;
      cin>>U>>V>>P;
      inputs[U][V] = P;
    }

    // 첫번째 다익스트라 돌려서 최단 경로 찾기
    vector<int> dist = dijkstra();
    queue<int> q;
    // BFS를 통해 최단 경로 제거해주기
    // 최단 경로인지 확인하는 방법은 5번에서 4번으로 간다고 했을 때 Dist[5] = Dist[4] + inputs[4][5] 인 것을 활용
    q.push(D);
    while(!q.empty()){
      int now = q.front();
      q.pop();
      for(int i = 0 ; i<trace[now].size() ; i++){
        int next = trace[now][i];
        if(inputs[next][now] && dist[next] == dist[now] - inputs[next][now]){
          inputs[next][now] = 0;
          q.push(next);
        }
      }
    }

    // 최단 경로에 들어가는 간선들을 제거 한 후 다시 다익스트라 돌리기
    vector<int> secondDist = dijkstra();

    int result = secondDist[D] == MAX ? -1 : secondDist[D];
    cout<<result<<'\n';
  }
  return 0;
}
