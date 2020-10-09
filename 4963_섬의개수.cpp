#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int w=1,h=1;
int d[8][2] = {{1,-1}, {1,0}, {1,1}, {0,-1}, {0,1}, {-1,-1}, {-1,0}, {-1,1}};

void doBFS(vector<vector<int>> &map, int y, int x){
  queue<pair<int, int>> q;
  q.push({y,x});
  map[y][x] = 2;
  while(!q.empty()){
    pair<int, int> now = q.front();

    q.pop();
    for(int i = 0 ; i<8 ; i++){
      int nextY = now.first + d[i][0], nextX = now.second + d[i][1];
      if(nextY >= 0 && nextY < h && nextX >= 0 && nextX < w && map[nextY][nextX] == 1){
        map[nextY][nextX] = 2;
        q.push({nextY, nextX});
      }
    }
  }
}

int main(void){
  while(1){
    int result = 0;
    cin>>w>>h;
    if(w==0 && h==0) break;
    vector<vector<int>> map(h, vector<int>(w,0));
    for(int i = 0 ; i < h ; i++){
      for(int j = 0 ; j < w ; j++){
        cin>>map[i][j];
      }
    }
    for(int i = 0 ; i < h ; i++){
      for(int j = 0 ; j < w ; j++){
        if(map[i][j] == 1){
          doBFS(map, i, j);
          result++;
        }
      }
    }
    cout<<result<<'\n';
  }
  return 0;
}
