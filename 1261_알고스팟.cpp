#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int N, M, result = 10001, d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct info{
  int y;
  int x;
  int count = 0;
};
deque<struct info> dq;
int main(void){
  cin>>N>>M;
  vector<vector<int>> map(M, vector<int>(N)), visited(M, vector<int>(N, 0));
  for(int i = 0 ; i<M ; i++){
    for(int j = 0 ; j<N ; j++){
      char input;
      cin>>input;
      map[i][j] = input - '0';
    }
    getchar();
  }
  dq.push_back({0,0,0});
  visited[0][0] = 1;
  while(!dq.empty()){
    struct info now = dq.front();
    dq.pop_front();
    if(now.y == M-1 && now.x == N-1) result = min(result, now.count);
    for(int i = 0 ; i<4 ; i++){
      int nextY = now.y + d[i][0], nextX = now.x + d[i][1];
      bool bound = nextY >= 0 && nextX >=0 && nextY < M && nextX < N;
      if(!bound) continue;
      bool visit = visited[nextY][nextX];
      if(visit) continue;
      if(map[nextY][nextX] == 1){
        dq.push_back({nextY, nextX, now.count + 1});
        visited[nextY][nextX] = 1;
      }
      else{
        dq.push_front({nextY, nextX, now.count});
        visited[nextY][nextX] = 1;
      }
    }
  }
  cout<<result;
  return 0;
}
