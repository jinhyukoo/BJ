#include<iostream>
#include<queue>
using namespace std;
int N,M,K,map[15][15] = {0, },dp[15][15] = {0, },d[2][2] = {{1,0},{0,1}}, cpx, cpy;
bool chk(int a, int b){return (a>=0 && b>=0 && a<N && b<M);}
bool chk2(int a, int b){return (a>=0 && b>=0 && a<=cpy && b<=cpx);}
bool chk3(int a, int b){return (a>=cpy && b>=cpx && a<N && b<M);}
struct xy{
  int y;
  int x;
};
int main(void){
  cin>>N>>M>>K;
  for(int i = 0 ;i<N;i++){
    for(int j = 0 ;j<M;j++){
      map[i][j] = i*M + j + 1;
      if(map[i][j] == K){
        cpx = j;
        cpy = i;
      }
    }
  }

  if(K==0){
    queue<struct xy> q;
    q.push({0,0});
    while(!q.empty()){
      struct xy t = q.front();
      q.pop();
      for(int i = 0 ;i<2;i++){
        int ny = t.y + d[i][0], nx = t.x + d[i][1];
        if(chk(ny, nx)){
          q.push({ny,nx});
          dp[ny][nx]++;
        }
      }
    }
    cout<<dp[N-1][M-1];
  }
  else{
    queue<struct xy> q;
    q.push({0,0});
    while(!q.empty()){
      struct xy t = q.front();
      q.pop();
      for(int i = 0;i<2;i++){
        int ny = t.y + d[i][0], nx = t.x + d[i][1];
        if(chk2(ny,nx)){
          q.push({ny,nx});
          dp[ny][nx]++;
        }
      }
    }
    int temp = dp[cpy][cpx];
    q.push({cpy,cpx});
    while(!q.empty()){
      struct xy t = q.front();
      q.pop();
      for(int i = 0;i<2;i++){
        int ny = t.y + d[i][0], nx = t.x + d[i][1];
        if(chk3(ny,nx)){
          q.push({ny,nx});
          dp[ny][nx]++;
        }
      }
    }
    cout<<dp[N-1][M-1] * temp;
  }
  return 0;
}
