#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int map[102][102];
int y,x;
struct xy_break{
  int x;
  int y;
  bool isbreak;
};
int dis[102][102][2] = {0, };
int doBFS(){
  queue<struct xy_break> q;
  struct xy_break temp;
  temp.x = 1;
  temp.y = 1;
  temp.isbreak = 0;
  q.push(temp);
  dis[1][1][0] = 1;
  while(!q.empty()){
    struct xy_break temp2;
    temp = q.front();
    q.pop();
    if(temp.y == y && temp.x == x) return dis[temp.y][temp.x][temp.isbreak];
    for(int i = 0 ;i<4 ; i++){
      temp2.y = temp.y + dir[i][0];
      temp2.x = temp.x + dir[i][1];
      temp2.isbreak = temp.isbreak;
      if(dis[temp2.y][temp2.x][temp.isbreak]) continue;
      if(map[temp2.y][temp2.x]==0){
        dis[temp2.y][temp2.x][temp.isbreak] = dis[temp.y][temp.x][temp.isbreak] + 1;
        q.push(temp2);
      }
      if(map[temp2.y][temp2.x]==1 && temp.isbreak == 0){
        dis[temp2.y][temp2.x][1] = dis[temp.y][temp.x][temp.isbreak] + 1;
        temp2.isbreak = 1;
        q.push(temp2);
      }
    }
  }
  return -1;
}
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  char input;
  cin>>y>>x;
  fill(&map[0][0],&map[y+1][x+1]+1,2);
  for(int i = 1 ;i<=y;i++){
    for(int j = 1 ; j<=x ;j++){
      cin>>input;
      if(input==48)
        map[i][j] = 0;
      else
        map[i][j] = 1;
    }
  }
  int result = doBFS();
  cout<<result;
  return 0;
}
