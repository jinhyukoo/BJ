#include<iostream>
#include<queue>
using namespace std;
int d[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}}, map[101][101][101] = {0, }, check[101][101][101] = {0, }, dis[101][101][101] = {0, }, r = 0, xs,ys,hs;
struct xyh{
  int h;
  int y;
  int x;
};
bool chk(int a, int b, int c){return (a>=0 && a<hs && b>=0 && b<ys && c>=0 && c<xs);}
queue<struct xyh> q;
void doBFS(){
  while(!q.empty()){
    struct xyh t = q.front();
    q.pop();
    check[t.h][t.y][t.x] = 1;
    for(int i = 0 ;i<6;i++){
      if(map[t.h + d[i][0]][t.y + d[i][1]][t.x + d[i][2]] == 0 && check[t.h + d[i][0]][t.y + d[i][1]][t.x + d[i][2]] == 0 && chk(t.h + d[i][0],t.y + d[i][1],t.x + d[i][2])){
        q.push({t.h + d[i][0],t.y + d[i][1],t.x + + d[i][2]});
        check[t.h + d[i][0]][t.y + d[i][1]][t.x + d[i][2]] = 1;
        map[t.h + d[i][0]][t.y + d[i][1]][t.x + d[i][2]] = 1;
        dis[t.h + d[i][0]][t.y + d[i][1]][t.x + d[i][2]] = dis[t.h][t.y][t.x] + 1;
        if(dis[t.h + d[i][0]][t.y + d[i][1]][t.x + d[i][2]]>r) r = dis[t.h + d[i][0]][t.y + d[i][1]][t.x + d[i][2]];
      }
    }
  }
}
int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL);
  cin>>xs>>ys>>hs;
  int sum = 0;
  for(int i = 0;i<hs;i++){
    for(int j = 0;j<ys;j++){
      for(int k = 0;k<xs;k++){
        cin>>map[i][j][k];
        if(map[i][j][k] != 0){
          sum++;
        }
      }
    }
  }
  if(sum == hs*ys*xs) cout<<0;
  else{
    for(int i = 0;i<hs;i++){
      for(int j = 0;j<ys;j++){
        for(int k = 0;k<xs;k++){
          if(map[i][j][k] != 1 || check[i][j][k] == 1) continue; //계속 안되다가 check조건을 추가해주니 성공...! 개이득~
          else q.push({i,j,k}); //한 번에 모든 토마토를 따져야 하므로 우선 queue에 모두 push
        }
      }
    }
    doBFS(); //그 후 BFS를 실행
    int sum = 0, minussum = 0;
    for(int i = 0;i<hs;i++){
      for(int j = 0;j<ys;j++){
        for(int k = 0;k<xs;k++){
          if(check[i][j][k] == 1) sum++;
          if(map[i][j][k] == -1) minussum++;
        }
      }
    }
    if(sum + minussum == hs*ys*xs)
      cout<<r;
    else cout<<-1;
  }
  return 0;
}
