#include<iostream>
#include<queue>
using namespace std;

#define MAX 1000000000

struct info{
  int y;
  int x;
  int d;
};

struct cmp{
  bool operator()(info t, info u){
    return t.d > u.d;
  }
};

int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int N = -1, count = 1;
  while(1){
    cin>>N;
    if(N == 0) break;

    priority_queue<struct info, vector<struct info>, cmp> pq;
    vector<vector<int>> map(N, vector<int>(N)), dist(N, vector<int>(N, MAX));

    for(int i = 0 ; i<N ; i++){
      for(int j = 0 ; j<N ; j++){
        cin>>map[i][j];
      }
    }
    dist[0][0] = map[0][0];
    pq.push({0,0,dist[0][0]});
    while(!pq.empty()){
      struct info now = pq.top();
      pq.pop();
      if(now.y == N-1 && now.x == N-1) break;
      for(int i = 0 ; i<4 ; i++){
        int nextY = now.y + d[i][0], nextX = now.x + d[i][1];
        bool bound = nextY >= 0 && nextX >=0 && nextY < N && nextX < N;
        if(!bound) continue;
        if(dist[nextY][nextX] > dist[now.y][now.x] + map[nextY][nextX]){
          dist[nextY][nextX] = dist[now.y][now.x] + map[nextY][nextX];
          pq.push({nextY, nextX, dist[nextY][nextX]});
        }
      }
    }
    cout<<"Problem "<<count++<<": "<<dist[N-1][N-1]<<'\n';
  }
  return 0;
}
