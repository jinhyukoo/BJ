#include<iostream>
#include<queue>
#include<string>
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
  int N;
  cin>>N;
  vector<string> map(N);
  vector<vector<int>> dist(N, vector<int>(N, MAX));
  priority_queue<struct info, vector<struct info>, cmp> pq;
  for(int i = 0 ; i<N ; i++){
    cin>>map[i];
  }
  dist[0][0] = 0;
  pq.push({0,0,0});
  while(!pq.empty()){
    struct info now = pq.top();
    pq.pop();
    for(int i = 0 ; i<4 ; i++){
      int nextY = now.y + d[i][0], nextX = now.x + d[i][1];
      bool bound = nextY>=0 && nextX>=0 && nextY<N && nextX<N;
      if(!bound) continue;
      int plus = map[nextY][nextX] == '0' ? 1 : 0;
      if(dist[nextY][nextX] > dist[now.y][now.x] + plus){
        dist[nextY][nextX] = dist[now.y][now.x] + plus;
        pq.push({nextY, nextX, dist[nextY][nextX]});
      }
    }
  }
  cout<<dist[N-1][N-1];
  return 0;
}
