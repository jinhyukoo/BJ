#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct xy{
  int x;
  int y;
};
int d[8][2] = {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

void doBFS(int map[302][302], struct xy now, struct xy des){
  queue<struct xy> q;
  map[now.y][now.x] = 0;
  q.push(now);
  while(!q.empty()){
    if(q.front().x == des.x && q.front().y == des.y){
      cout<<map[des.y][des.x]<<endl;
      break;
    }
    for(int i = 0 ;i<8;i++){
      if(map[q.front().y + d[i][0]][q.front().x + d[i][1]] > map[q.front().y][q.front().x] + 1){
        q.push({q.front().y + d[i][0], q.front().x + d[i][1]});
      }
    }
    q.pop();
  }
  cout<<map[des.y][des.x]<<endl;
}
int main(void){
  int count;

  for(int i = 0 ; i<count ;i++){
    int map[302][302] = {0, };
    fill(&map[1][1],&map[301][301]+1,10000);
    int size;
    struct xy now, des;
    cin>>size;
    cin>>now.y>>now.x>>des.y>>des.x;
    doBFS(map,now,des);
  }
  return 0;
}
